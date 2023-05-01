#pragma once
#include <algorithm>
#include <vector>


class Wall
{
private:
	std::vector<float> _coordinates;
	unsigned int _textureId;
	std::vector<float> _textureCoordinates;

	// todo: textures


public:
	Wall(std::vector<float> coord, unsigned int textireId,
		std::vector<float> textureCoordinates);

	Wall() = default;

	std::vector<float> GetCoordinates() const;
	std::vector<float> GetTextureCoordinates() const;
	unsigned int GetTextureId() const;

};

