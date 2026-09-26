// OverlayPS.hlsl — pixel del overlay 2D del port (A2, render hook de RT64).
//
// El atlas codifica el nivel del glifo 2bpp en R: R=255 = tinta (texto), R=0 = sombra (nivel 1,
// desplazada en diagonal, como el motor). El alfa es la cobertura. Para paneles (textura 1x1 blanca)
// R=255, asi que se pinta el color de vertice tal cual.
//
// `mode == 1` es la capa de IMAGEN (logos HD): se pinta el COLOR REAL de la textura (no solo el R).
// `mode == 2` es la capa de IMAGEN con CLAVE DE BLANCO: el fondo blanco puro del PNG se vuelve
// transparente (lo aporta la capa blanca del overlay), dejando solo el arte del logo. Evita que el
// blanco del logo se sume al de la capa (doble blanco) durante los fades.
//
// Mismo binding que Goemon/recompui (sampler s1/space0, textura t2/space1).

struct Input {
    float4 transform;
    float mode;
};

[[vk::push_constant]]
ConstantBuffer<Input> gInput : register(b0, space0);

SamplerState gSampler : register(s1, space0);
Texture2D<float4> gTexture : register(t2, space1);

void PSMain(
    in float4 iColor : COLOR,
    in float2 iUV : TEXCOORD,
    out float4 oColor : SV_TARGET)
{
    float4 t = gTexture.SampleLevel(gSampler, iUV, 0);
    if (gInput.mode > 1.5) {
        // Imagen con clave de blanco: alpha = 0 donde el pixel es blanco puro (min(R,G,B) alto).
        float k = min(t.r, min(t.g, t.b));
        float key = 1.0 - smoothstep(0.90, 0.985, k);
        oColor = float4(t.rgb, t.a * key * iColor.a);
    } else if (gInput.mode > 0.5) {
        // Imagen a color (RGBA8): color real de la textura * color de vertice.
        oColor = float4(t.rgb * iColor.rgb, t.a * iColor.a);
    } else {
        float3 shadow = float3(0.0, 0.0, 0.0);   // sombra negra (paralela en diagonal)
        oColor = float4(lerp(shadow, iColor.rgb, t.r), t.a * iColor.a);
    }
}
