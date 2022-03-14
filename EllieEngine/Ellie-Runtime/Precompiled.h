#pragma once
#define WIN32_LEAN_AND_MEAN
#define _CRTDBG_MAP_ALLOC

#pragma comment(lib, "dxgi.lib")

//*Header*//
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>

#include <d3d11.h>
#include <D3DX11.h>
#include <DirectXMath.h>
#include <string>
#include <D3DX11tex.h>
#include <d3dx9math.h>

//*using*//
using namespace DirectX;

//*Custom Class*//
#include "Dx11.h"
#include "EllieCore.h"
#include "Matrix.h"
#include "Vector.h"
#include "MacroDef.h"
