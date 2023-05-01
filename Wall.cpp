#include "Wall.h"

Wall::Wall(std::vector<float> coord, unsigned int textireId,
	std::vector<float> textureCoordinates)
{
	_coordinates = std::vector<float>(coord);
	_textureCoordinates = std::vector<float>(textureCoordinates);
	_textureId = textireId;
}

std::vector<float> Wall::GetCoordinates() const
{
	return std::vector<float>(_coordinates);
}

std::vector<float> Wall::GetTextureCoordinates() const
{
	return std::vector<float>(_textureCoordinates);
}

unsigned int Wall::GetTextureId() const
{
	return _textureId;
}


