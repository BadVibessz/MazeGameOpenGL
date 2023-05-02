#include "TextureHandler.h"

// wstring - wide string (more than 1 byte per character)
unsigned int TextureHandler::LoadTexture(std::wstring const& filename) 
{
	// Загружаем изображение при помощи GDI+
	Bitmap bmp(filename.c_str());
	if (bmp.GetLastStatus() != Gdiplus::Ok)
		throw std::runtime_error("Error loading texture file");

	// Определяем формат пикселей для использования 
	// с методом Bitmap::Lock и функцией gluBuild2DMipmaps
	PixelFormat pixelFormat = 0;
	GLint textureFormat = 0;
	GLint colorComponents = 0;
	GLint internalFormat = 0;

	// Есть ли в изображении альфа-канал?
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

	// Размеры и положение прямоугольной области изображения, 
	// доступ к данным которой мы хотим получить
	Rect lockRect(0, 0, bmp.GetWidth(), bmp.GetHeight());

	// Получаем прямой доступ для чтения к данным растрового изображения
	BitmapData bitmapData;
	bmp.LockBits(&lockRect, ImageLockModeRead,
		pixelFormat, &bitmapData);

	GLuint textureId = 0;
	// генерируем один уникальный идентификатор текстурного объекта
	glGenTextures(1, &textureId);

	// делаем активным текстурный объект с данным идентификатором
	// (с ним еще пока не связано никакое изображение)
	glBindTexture(GL_TEXTURE_2D, textureId);

	// Задаем текстурное изображение для 0 уровня детализации
	glTexImage2D(
		GL_TEXTURE_2D,
		0,		// уровень детализации
		internalFormat,
		bitmapData.Width,
		bitmapData.Height,
		0,	// ширина рамки текстуры (0 - нет рамки, 1 - рамка в 1 пиксель)
		textureFormat,
		GL_UNSIGNED_BYTE,	// каждая компонента цвета занимает один байт
		bitmapData.Scan0	// адрес первой строки изображения
	);

	// Задаем параметры фильтрации текстуры при уменьшении и при увеличении
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Завершаем работу с данными растра
	bmp.UnlockBits(&bitmapData);

	// Возвращаем идентификатор созданного изображения
	return textureId;
}
