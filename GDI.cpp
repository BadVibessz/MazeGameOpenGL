#include "GDI.h"



GDI::GDI()
{
	GdiplusStartupInput input;
	GdiplusStartupOutput output;

	// �� ������� ���������������� GDI+
	if (GdiplusStartup(&_token, &input, &output) != Gdiplus::Ok)
		throw std::runtime_error("Failed to initialize GDI+");
}

GDI::~GDI()
{
	Gdiplus::GdiplusShutdown(_token);
}
