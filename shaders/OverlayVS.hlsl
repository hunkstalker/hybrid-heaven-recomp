// OverlayVS.hlsl — vertice del overlay 2D del port (A2, render hook de RT64).
//
// Coordenadas en la RESOLUCION VIRTUAL del overlay (px, origen arriba-izquierda). El push constant
// lleva la transformacion a clip: xy = escala (clip/unidad), zw = offset. Convencion D3D (y=+1
// arriba); DXC_VS_OPTS añade -fvk-invert-y al compilar a SPIR-V para Vulkan.

struct Input {
    float4 transform;
};

[[vk::push_constant]]
ConstantBuffer<Input> gInput : register(b0, space0);

void VSMain(
    in float2 iPosition : POSITION,
    in float4 iColor : COLOR,
    in float2 iUV : TEXCOORD,
    out float4 oColor : COLOR,
    out float2 oUV : TEXCOORD,
    out float4 oPosition : SV_Position)
{
    oPosition = float4(iPosition * gInput.transform.xy + gInput.transform.zw, 0.0, 1.0);
    oColor = iColor;
    oUV = iUV;
}
