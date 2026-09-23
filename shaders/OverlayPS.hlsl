// OverlayPS.hlsl — pixel del overlay 2D del port (A2, render hook de RT64).
//
// El atlas codifica el nivel del glifo 2bpp en R: R=255 = tinta (texto), R=0 = sombra (nivel 1,
// desplazada en diagonal, como el motor). El alfa es la cobertura. Para paneles (textura 1x1 blanca)
// R=255, asi que se pinta el color de vertice tal cual.
//
// Mismo binding que Goemon/recompui (sampler s1/space0, textura t2/space1).

SamplerState gSampler : register(s1, space0);
Texture2D<float4> gTexture : register(t2, space1);

void PSMain(
    in float4 iColor : COLOR,
    in float2 iUV : TEXCOORD,
    out float4 oColor : SV_TARGET)
{
    float4 t = gTexture.SampleLevel(gSampler, iUV, 0);
    float3 shadow = float3(0.0, 0.0, 0.0);   // sombra negra (paralela en diagonal)
    oColor = float4(lerp(shadow, iColor.rgb, t.r), t.a * iColor.a);
}
