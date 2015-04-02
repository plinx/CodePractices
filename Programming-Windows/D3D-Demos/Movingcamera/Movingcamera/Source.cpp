#include <iostream>
#include "d3dUtility.h"

IDirect3DDevice9 *Device = 0;

const int Width = 640;
const int Height = 480;

ID3DXMesh *Objs[2] = { 0, 0 };
D3DXMATRIX Worlds[2];
D3DMATERIAL9 Mtrls[2];

bool Setup()
{
	D3DXCreateTeapot(Device, &Objs[0], 0);
	D3DXCreateTeapot(Device, &Objs[1], 0);

	D3DXMatrixTranslation(&Worlds[0], -2.0f, 0.0f, 0.0f);
	D3DXMatrixTranslation(&Worlds[1], 2.0f, 0.0f, 0.0f);

	Mtrls[0] = d3d::BLUE_MTRL;
	Mtrls[1] = d3d::GREEN_MTRL;

	D3DXVECTOR3 dir(0.0f, 0.0f, 1.0f);
	D3DXCOLOR dc = d3d::WHITE;
	D3DLIGHT9 dlight = d3d::InitDirectionalLight(&dir, &dc);

	Device->SetLight(0, &dlight);
	Device->LightEnable(0, true);

	Device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	Device->SetRenderState(D3DRS_SPECULARENABLE, false);

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DX_PI * 0.25f,
		(float)Width / (float)Height,
		1.0f,
		1000.f);

	Device->SetTransform(D3DTS_PROJECTION, &proj);

	return true;
}

void Cleanup()
{
	for (int i = 0; i < 2; i++)
	{
		d3d::Release<ID3DXMesh*>(Objs[i]);
	}
}

bool Display(float timeDelta)
{
	if (Device)
	{
		static float angle = (3.0f * D3DX_PI) / 2.0f;
		static float height = 0.0f;

		if (::GetAsyncKeyState(VK_LEFT) & 0x8000f)
			angle -= 0.5f * timeDelta;

		if (::GetAsyncKeyState(VK_RIGHT) & 0x8000f)
			angle += 0.5f * timeDelta;

		if (::GetAsyncKeyState(VK_UP) & 0x8000f)
			height += 5.0f * timeDelta;

		if (::GetAsyncKeyState(VK_DOWN) & 0x8000f)
			height -= 5.0f * timeDelta;

		D3DXVECTOR3 pos(cosf(angle) * 7.0f, height, sinf(angle) * 7.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXMATRIX V;
		D3DXMatrixLookAtLH(&V, &pos, &target, &up);

		Device->SetTransform(D3DTS_VIEW, &V);

		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		Device->BeginScene();

		for (int i = 0; i < 2; i++)
		{
			// set material and world matrix for ith object, then render
			// the ith object.
			Device->SetMaterial(&Mtrls[i]);
			Device->SetTransform(D3DTS_WORLD, &Worlds[i]);
			Objs[i]->DrawSubset(0);
		}

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
