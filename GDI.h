#pragma once
#include <windows.h>
#include <gdiplus.h>
#include <objidl.h>
#include <string.h>
#include <tchar.h>
#include <stdexcept>

#pragma comment(lib,"gdiplus.lib")

using namespace Gdiplus;

class GDI
{
private:
	unsigned long _token;

public:
	GDI();
	~GDI();
};

