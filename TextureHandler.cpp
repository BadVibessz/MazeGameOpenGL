#include "TextureHandler.h"

// wstring - wide string (more than 1 byte per character)
unsigned int TextureHandler::LoadTexture(std::wstring const& filename) 
{
	// ��������� ����������� ��� ������ GDI+
	Bitmap bmp(filename.c_str());
	if (bmp.GetLastStatus() != Gdiplus::Ok)
		throw std::runtime_error("Error loading texture file");

	// ���������� ������ �������� ��� ������������� 
	// � ������� Bitmap::Lock � �������� gluBuild2DMipmaps
	PixelFormat pixelFormat = 0;
	GLint textureFormat = 0;
	GLint colorComponents = 0;
	GLint internalFormat = 0;

	// ���� �� � ����������� �����-�����?
	if ((bmp.GetPixelFormat() & PixelFormatAlpha) != 0)
	{
		colorComponents = 4;
		pixelFormat = PixelFormat32bppARGB;
		textureFormat = GL_BGRA_EXT;
		internalFormat = GL_RGBA;
	}
	else
	{
		colorComponents = 3;
		textureFormat = GL_BGR_EXT;
		pixelFormat = PixelFormat24bppRGB;
		internalFormat = GL_RGB;
	}

	// ������� � ��������� ������������� ������� �����������, 
	// ������ � ������ ������� �� ����� ��������
	Rect lockRect(0, 0, bmp.GetWidth(), bmp.GetHeight());

	// �������� ������ ������ ��� ������ � ������ ���������� �����������
	BitmapData bitmapData;
	bmp.LockBits(&lockRect, ImageLockModeRead,
		pixelFormat, &bitmapData);

	GLuint textureId = 0;
	// ���������� ���� ���������� ������������� ����������� �������
	glGenTextures(1, &textureId);

	// ������ �������� ���������� ������ � ������ ���������������
	// (� ��� ��� ���� �� ������� ������� �����������)
	glBindTexture(GL_TEXTURE_2D, textureId);

	// ������ ���������� ����������� ��� 0 ������ �����������
	glTexImage2D(
		GL_TEXTURE_2D,
		0,		// ������� �����������
		internalFormat,
		bitmapData.Width,
		bitmapData.Height,
		0,	// ������ ����� �������� (0 - ��� �����, 1 - ����� � 1 �������)
		textureFormat,
		GL_UNSIGNED_BYTE,	// ������ ���������� ����� �������� ���� ����
		bitmapData.Scan0	// ����� ������ ������ �����������
	);

	// ������ ��������� ���������� �������� ��� ���������� � ��� ����������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// ��������� ������ � ������� ������
	bmp.UnlockBits(&bitmapData);

	// ���������� ������������� ���������� �����������
	return textureId;
}
