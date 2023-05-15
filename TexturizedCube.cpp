#include "TexturizedCube.h"

void TexturizedCube::Draw(float size) const
{

	/*

	   Y
	   |
	   |
	   |
	   +---X
	  /
	 /
	Z
	   3----2
	  /    /|
	 /    / |
	7----6  |
	|  0 |  1
	|    | /
	|    |/
	4----5
	*/

	// ћассив координат вершин
	static const float vertices[8][3] =
	{
		{-size, -size, -size},	// 0
		{+size, -size, -size},	// 1
		{+size, +size, -size},	// 2
		{-size, +size, -size},	// 3
		{-size, -size, +size},	// 4
		{+size, -size, +size},	// 5
		{+size, +size, +size},	// 6
		{-size, +size, +size},	// 7
	};

	struct CubeFace
	{
		unsigned char vertex0;
		unsigned char vertex1;
		unsigned char vertex2;
		unsigned char vertex3;
		float tex0s, tex0t;
		float tex1s, tex1t;
		float tex2s, tex2t;
		float tex3s, tex3t;
		uint texture;
	};

	// ћассив координат граней (в пор€дке, совпадающем с 
	// пор€дком объ€влени€ их в массиве цветов)
	// индексы вершин граней перечисл€ютс€ в пор€дке их обхода

	// против часовой стрелки (если смотреть на грань снаружи)
	static const CubeFace faces[] =
	{
		{4, 7, 3, 0, 0, 1, 0, 0, 1, 0, 1, 1, _leftTexture},		// грань x<0
		{5, 1, 2, 6, 1, 1, 0, 1, 0, 0, 1, 0, _rightTexture},	// грань x>0
		{4, 0, 1, 5, 0, 1, 0, 0, 1, 0, 1, 1, _bottomTexture},	// грань y<0
		{7, 6, 2, 3, 0, 0, 1, 0, 1, 1, 0, 1, _topTexture},		// грань y>0
		{0, 3, 2, 1, 0, 1, 0, 0, 1, 0, 1, 1, _frontTexture},	// грань z<0
		{4, 5, 6, 7, 0, 0, 1, 0, 1, 1, 0, 1, _backTexture},		// грань z>0
	};
	static unsigned const faceCount = 6;

	for (unsigned faceIndex = 0; faceIndex < faceCount; ++faceIndex)
	{
		CubeFace const& face = faces[faceIndex];

		glBindTexture(GL_TEXTURE_2D, face.texture);

		// –исуем 4 вершины квадрата
		glBegin(GL_QUADS);
		{
			glTexCoord2f(face.tex0s, face.tex0t);
			glVertex3fv(vertices[face.vertex0]);

			glTexCoord2f(face.tex1s, face.tex1t);
			glVertex3fv(vertices[face.vertex1]);

			glTexCoord2f(face.tex2s, face.tex2t);
			glVertex3fv(vertices[face.vertex2]);

			glTexCoord2f(face.tex3s, face.tex3t);
			glVertex3fv(vertices[face.vertex3]);
		}
		glEnd();
	}

}

void TexturizedCube::SetTextures(uint leftTexture, uint rightTexture,
	uint bottomTexture, uint topTexture, uint backTexture, uint frontTexture)
{

	_leftTexture = leftTexture;
	_rightTexture = rightTexture;
	_bottomTexture = bottomTexture;
	_topTexture = topTexture;
	_backTexture = backTexture;
	_frontTexture = frontTexture;
}
