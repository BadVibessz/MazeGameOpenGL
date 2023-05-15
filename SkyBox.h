#pragma once

#include "TexturizedCube.h"

class SkyBox
{

private:
	TexturizedCube _cube = TexturizedCube();

	uint _backTexture, _frontTexture,
		_leftTexture, _rightTexture,
		_bottomTexture, _topTexture;

public:

	SkyBox() = default;

	SkyBox(
		uint leftTexture,
		uint rightTexture,
		uint bottomTexture,
		uint topTexture,
		uint backTexture,
		uint frontTexture
	);
	void Draw(float size)const;

};



