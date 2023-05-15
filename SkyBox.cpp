#include "SkyBox.h"

SkyBox::SkyBox(uint leftTexture, uint rightTexture, uint bottomTexture, uint topTexture, uint backTexture, uint frontTexture)
{

	_leftTexture = leftTexture;
	_rightTexture = rightTexture;
	_bottomTexture = bottomTexture;
	_topTexture = topTexture;
	_backTexture = backTexture;
	_frontTexture = frontTexture;

	_cube.SetTextures(leftTexture, rightTexture, bottomTexture,
		topTexture, backTexture, frontTexture);

}


/*
����� ������������ ���������� ���������, ��� �������
��� ������ ���������� ���������� ��������� �� ������� ��������� 0-1,
������������ �������� ������� �� ��������� ����� ����������� �����������.
������ ����� ����������� � ������������ ������ OpenGL 1.1, ������������ �
Visual Studio, �� �������� � ���� ���������� � �������������� �
��������� ����� ����� ������������ ������������
*/
#ifndef GL_CLAMP_TO_EDGE_EXT
#define GL_CLAMP_TO_EDGE_EXT 0x812F
#endif

void SkyBox::Draw(float size) const
{

	// ������������� ����������� ������ ������������ ����
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);

	// ��������� ������� �������
	glPushMatrix();

	// ��������� ������ ������������� � 4 ������� ������� (�������� 12-14)
	// ���� ������� ���� 0, �� ������� ������ �������� ��������.
	GLfloat modelView[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, modelView);
	modelView[12] = modelView[13] = modelView[14] = 0;
	glLoadMatrixf(modelView);

	// ������ ���
	_cube.Draw(size);

	// ��������������� ������� �������
	glPopMatrix();

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
}
