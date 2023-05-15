#pragma once

#include <vector>
#include "Wall.h"
#include "SkyBox.h"

using uint = unsigned int;

class World
{
public:
	float externalWallSize = 0;
	float worldSize = 0;


	World() = default;
	World(float externalWallSize, float worldSize);

	Wall GetFloor(unsigned int textureId) const;
	std::vector<Wall> GetExternalWalls(uint textureId) const;
	std::vector<Wall> GetInternalWalls(std::vector<uint> textures) const;
	std::vector<Wall> GetExit(uint textureId) const;

	SkyBox GetSkyBox(uint leftTexture,uint rightTexture,uint bottomTexture,
		uint topTexture,uint backTexture,uint frontTexture);


};

