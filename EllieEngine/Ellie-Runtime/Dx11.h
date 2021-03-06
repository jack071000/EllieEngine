#pragma once

class Dx11
{
public:
	Dx11();
	~Dx11();

	bool Init(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen,
		float screenDepth, float screenNear);
	bool Resize();

	int Rendering();
	void BeginScene(float red, float green, float blue, float alpha);
	void EndScene();

	void Release();

private:
	bool m_Vsync_Enabled;
	int m_VideoCardMemory;
	char m_VideoCardDescription[128];
	UINT m_4xMsaaQuality;
	bool m_EnableMsaa;
	int m_ScreenWidth;
	int m_ScreenHeight;

	IDXGISwapChain* m_SwapChain;
	ID3D11Device* m_Device;
	ID3D11DeviceContext* m_ImmediateContext;

	ID3D11RenderTargetView* m_RenderTargetView;
	ID3D11Texture2D* m_DepthStencilBuffer;

	ID3D11DepthStencilState* m_DepthStencilState;
	ID3D11DepthStencilView* m_DepthStencilView;
	ID3D11DepthStencilState* m_DepthDisabledStencilState;

	ID3D11RasterizerState* m_RasterState;
	ID3D11RasterizerState* m_RasterStateNoCulling;

	XMMATRIX m_ProjectionMatrix;
	XMMATRIX m_WorldMatrix;
	XMMATRIX m_OrthoMatrix;

	D3D11_VIEWPORT m_Viewport;
};