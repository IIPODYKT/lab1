#pragma once
#include <windows.h>
#include <windowsx.h>
class CBall
{
	HBRUSH hBrush;
public:
	CBall();
	~CBall();
	void Draw(HDC dc);
};

