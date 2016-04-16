#include "CBall.h"



CBall::CBall()
{
	hBrush = CreateSolidBrush(RGB(0, 255, 0));
}


CBall::~CBall()
{
	DeleteObject(hBrush);
}

void CBall::Draw(HDC dc)
{
	HBRUSH hOldBrush;
	hOldBrush = SelectBrush(dc, hBrush);
	Ellipse(dc, 10, 10, 30, 30);
	SelectBrush(dc, hOldBrush);
}
