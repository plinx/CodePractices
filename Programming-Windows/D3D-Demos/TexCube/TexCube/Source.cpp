#include "d3dUtility.h"
#include "cube.h"
#include "vertex.h"

IDirect3DDevice9 *Device = 0;

const int Width = 640;
const int Height = 480;

Cube *Box = 0;
IDirect3DTexture9 *Tex = 0;

bool Setup()
{
	Box = new Cube(Device);

	D3DLIGHT9 light;
	::ZeroMemory(&light, sizeof(light));
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	light.Specular = D3DXCOLOR(0.2f, 0.2f, 0.2f, 0.2f);
	light.Direction = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
	Device->SetLight(0, &light);
	Device->LightEnable(0, true);

	D3DXCreateTextureFromFile(Device, "crate.jpg", &Tex);

	Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DX_PI * 0.5f,
		(float)Width / (float)Height,
		1.0f,
		1000.0f);

	Device->SetTransform(D3DTS_PROJECTION, &proj);

	return true;
}

void Cleanup()
{
	d3d::Delete<Cube*>(Box);
	d3d::Release<IDirect3DDevice9*>(Device);
}

bool Display(float timeDelta)
{
	if (Device)
	{
		static float angle = (3.0f * D3DX_PI) / 2.0f;
		static float height = 2.0f;

		if (::GetAsyncKeyState(VK_LEFT) & 0x8000f)
		{
			angle -= 0.5f * timeDelta;
		}
		if (::GetAsyncKeyState(VK_RIGHT) & 0x8000f)
		{
			angle += 0.5f * timeDelta;
		}
		if (::GetAsyncKeyState(VK_UP) & 0x8000f)
		{
			height += 5.0f * timeDelta;
		}
		if (::GetAsyncKeyState(VK_DOWN) & 0x8000f)
		{
			height -= 5.0f * timeDelta;
		}

		D3DXVECTOR3 pos(cosf(angle) * 3.0f, height, sinf(angle) * 3.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXMATRIX V;
		
		D3DXMatrixLookAtLH(&V, &pos, &target, &up);
		Device->SetTransform(D3DTS_VIEW, &V);

		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		Device->BeginScene();

		Device->SetMaterial(&d3d::WHITE_MTRL);
		Device->SetTexture(0, Tex);

		Box->draw(0, 0, 0);

		Device->EndScene();
		Device->Present(0, 0, 0, 0);
	}

	return true;
}

LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
	HINSTANCE prevInstance,
	PSTR cmdLine,
	int showCmd)
{
	if (!d3d::InitD3D(hinstance,
		Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}

	if (!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop(Display);

	Cleanup();

	Device->Release();

	return 0;
}