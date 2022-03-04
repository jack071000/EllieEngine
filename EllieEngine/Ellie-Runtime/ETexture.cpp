#include "Precompiled.h"
#include "ETexture.h"

ETexture::ETexture()
{
}

ETexture::~ETexture()
{
}

bool ETexture::LoadTexture(ID3D11Device* g_pDevice, const WCHAR* path)
{
    //*����Ÿ�ٿ� �ؽ�ó ����� ����� ����

    //1. �̹��� ���� ����
    //�ش� ������ ����� ���˿� ���� �ؽ�ó�� ����� ���� ��쿡 ����Ѵ�.
    D3DX11_IMAGE_INFO imageinfo;
    HRESULT hr; D3DX11GetImageInfoFromFile(path, NULL, &imageinfo, &hr);
    if (FAILED(hr)) return false;
    m_ImageInfo = imageinfo;

    //2. �ؽ�ó ���ҽ� ����
    ID3D11Resource* g_pTexture = NULL;
    D3DX11CreateTextureFromFile(g_pDevice, path, NULL /*����Ʈ ����*/, NULL/*�񵿱� ����*/, &g_pTexture, &hr);

    /*
    //���� �ؽ�ó�� ���� �������� �ְ� �ʹٸ�
    D3DX11_IMAGE_LOAD_INFO imageLoadInfo;
    imageLoadInfo.Width = 256;
    imageLoadInfo.Height = 256;
    imageLoadInfo.Depth = 0;
    imageLoadInfo.FirstMipLevel = 0;
    imageLoadInfo.MipLevels = 8;
    imageLoadInfo.Usage = D3D11_USAGE_DEFAULT;
    imageLoadInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    imageLoadInfo.CpuAccessFlags = 0;
    imageLoadInfo.MiscFlags = 0;
    imageLoadInfo.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    imageLoadInfo.Filter = D3DX11_FILTER_LINEAR;
    imageLoadInfo.pSrcInfo = NULL;

    D3DX11CreateTextureFromFile(g_pDevice, path, &imageLoadInfo, NULL, &g_pTexture, &hr);
    */
    if (FAILED(hr)) return false;
    m_TextureResource = g_pTexture;


    //3. �ؽ�ó ���ҽ��� ���̴����� �׼��� �Ϸ��� [���̴� ���ҽ� ��]�� �����ؾ� �Ѵ�.
    ID3D11ShaderResourceView* g_pTextureRV = NULL;
    hr = g_pDevice->CreateShaderResourceView(g_pTexture, NULL, &g_pTextureRV);
    if (FAILED(hr)) return false;
    m_TextureResourceView = g_pTextureRV;

    return true;
}

void ETexture::Excute()
{
}

void ETexture::Destroy()
{
}