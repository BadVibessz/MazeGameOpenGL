#pragma once
#include <vector>
#include <glut.h>

using uint = unsigned int;


class TexturizedCube
{

private:
	uint _backTexture, _frontTexture,
		_leftTexture, _rightTexture,
		_bottomTexture, _topTexture;

	std::vector<float> _textureCoordinates = {0,0, 1,0, 1,1, 0,1};

public:
	TexturizedCube() = default;

	void Draw(float size = 1)const;
	void SetTextures(uint leftTexture, uint rightTexture, uint bottomTexture, \
		uint topTexture, uint backTexture, uint frontTexture);

	






};


