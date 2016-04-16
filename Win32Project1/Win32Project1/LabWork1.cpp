#include <Windows.h>
#include "Cball.h"
HINSTANCE g_hInstance;
int g_nCmdShow;
HWND g_mainWnd;
CBall b1;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL InitAppClass()
{
	ATOM class_id;
	WNDCLASS wc;
	memset(&wc, 0, sizeof(wc));
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = g_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = L"LabWork1";
	class_id = RegisterClass(&wc);

	if (class_id != 0)
		return TRUE;

	return FALSE;
}
BOOL InitWindow()
{
	g_mainWnd = CreateWindow(L"LabWork1", L"Лабораторная работа №1", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, 0, 0, g_hInstance, 0);
	if (!g_mainWnd) return FALSE;
	ShowWindow(g_mainWnd, g_nCmdShow);
	UpdateWindow(g_mainWnd);

	return TRUE;
}

WPARAM StartMessageLoop()
{
	MSG msg;

	while (GetMessage(&msg, 0, 0, 0))
		DispatchMessage(&msg);

	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_PAINT:
	{
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hWnd, &ps);
		b1.Draw(hDC);
		EndPaint(hWnd, &ps);
		return 0;
	}
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
int WINAPI WinMain(HINSTANCE  hInstance, HINSTANCE  hPrevInstance, LPSTR	lpCmdLine, int nCmdShow)
{
	g_hInstance= hInstance;
	g_nCmdShow= nCmdShow;
	if (!InitAppClass())
		return 0;
	if (!InitWindow())
		return 0;
	return StartMessageLoop();
}
