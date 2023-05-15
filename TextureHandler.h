#pragma once
#include <string>
#include "GDI.h"
#include "glut.h"

using namespace Gdiplus;


class TextureHandler
{
public:
	static unsigned int LoadTexture(std::wstring const& filename);
};

