#include "World.h"

World::World(float externalWallSize, float worldSize)
{
	this->externalWallSize = externalWallSize;
	this->worldSize = worldSize;
}

std::vector<Wall> World::GetExternalWalls(uint textureId) const
{
	return
	{
		// white brick
		Wall({ externalWallSize,externalWallSize,0,
		externalWallSize,-externalWallSize,0,
		externalWallSize,-externalWallSize,50,
		externalWallSize,externalWallSize,50 },
		textureId,
		{ 0,0, 10,0, 10,-2, 0,-2 }),

		Wall({ externalWallSize,-externalWallSize,0,
		-externalWallSize,-externalWallSize,0,
		-externalWallSize,-externalWallSize,50,
		externalWallSize,-externalWallSize,50 },
		textureId,
		{ 0,0, 10,0, 10,-2, 0,-2 }),

		Wall({ -externalWallSize,-externalWallSize,0,
		-externalWallSize,externalWallSize,0,
		-externalWallSize,externalWallSize,50,
		-externalWallSize,-externalWallSize,50 },
		textureId,
		{ 0,0, 10,0, 10,-2, 0,-2 }),

		Wall({ -externalWallSize,externalWallSize,0,
		externalWallSize,externalWallSize,0,
		externalWallSize,externalWallSize,50,
		-externalWallSize,externalWallSize,50 },
		textureId,
		{ 0,0, 10,0, 10,-2, 0,-2 })
	};
}

std::vector<Wall> World::GetExit(uint textureId) const
{
	return
	{
		// exit
		Wall({ externalWallSize / 2 - 10, externalWallSize - 30, 0,
		externalWallSize / 2 - 10, externalWallSize - 15, 0,
		externalWallSize / 2 - 10, externalWallSize - 15, 25,
		externalWallSize / 2 - 10,externalWallSize - 30, 25},
		textureId,
		{ 0,0, 1,0, 1,-1, 0,-1 }),

		Wall({ externalWallSize / 2 + 5, externalWallSize - 30, 0,
		externalWallSize / 2 + 5, externalWallSize - 15, 0,
		externalWallSize / 2 + 5, externalWallSize - 15, 25,
		externalWallSize / 2 + 5,externalWallSize - 30, 25},
		textureId,
		{ 0,0, 1,0, 1,-1, 0,-1 }),


		Wall({ externalWallSize / 2 - 10, externalWallSize - 30, 0,
		externalWallSize / 2 + 5, externalWallSize - 30, 0,
		externalWallSize / 2 + 5, externalWallSize - 30, 25,
		externalWallSize / 2 - 10,externalWallSize - 30, 25},
		textureId,
		{ 0,0, 1,0, 1,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 10, externalWallSize - 15, 0,
		externalWallSize / 2 + 5, externalWallSize - 15, 0,
		externalWallSize / 2 + 5, externalWallSize - 15, 25,
		externalWallSize / 2 - 10,externalWallSize - 15, 25},
		textureId,
		{ 0,0, 1,0, 1,-1, 0,-1 })
	};
}

SkyBox World::GetSkyBox(uint leftTexture, uint rightTexture, uint bottomTexture, uint topTexture, uint backTexture, uint frontTexture)
{
	return SkyBox(leftTexture, rightTexture, bottomTexture,
		topTexture, backTexture, frontTexture);
}

std::vector<Wall> World::GetInternalWalls(std::vector<uint> textures) const
{
	float height = 15;

	return
	{

		// mossy wood
		Wall({ externalWallSize, -externalWallSize + 15, 0,
		externalWallSize - 50, -externalWallSize + 15, 0,
		externalWallSize - 50, -externalWallSize + 15, height,
		externalWallSize, -externalWallSize + 15, height },
		textures[0],
		{ 0,0, 3,0, 3,-3, 0,-3 }),

		Wall({externalWallSize - 50, -externalWallSize + 15, 0,
		externalWallSize - 50, -externalWallSize + 15 + 70, 0,
		externalWallSize - 50, -externalWallSize + 15 + 70, height,
		externalWallSize - 50, -externalWallSize + 15, height },
		textures[0],
		{ 0,0, 3,0, 3,-3, 0,-3 }),

		Wall({externalWallSize - 50, -externalWallSize + 15 + 70, 0,
		externalWallSize - 25, -externalWallSize + 15 + 70, 0,
		externalWallSize - 25, -externalWallSize + 15 + 70, height,
		externalWallSize - 50, -externalWallSize + 15 + 70, height },
		textures[0],
		{ 0,0, 3,0, 3,-3, 0,-3 }),

		Wall({externalWallSize - 25, -externalWallSize + 15 + 70, 0,
		externalWallSize - 25, -externalWallSize + 35, 0,
		externalWallSize - 25, -externalWallSize + 35, height,
		externalWallSize - 25, -externalWallSize + 15 + 70, height },
		textures[0],
		{ 0,0, 3,0, 3,-3, 0,-3 }),

		Wall({externalWallSize - 25, -externalWallSize + 35, 0,
		externalWallSize - 35, -externalWallSize + 35, 0,
		externalWallSize - 35, -externalWallSize + 35, height,
		externalWallSize - 25, -externalWallSize + 35, height },
		textures[0],
		{ 0,0, 3,0, 3,-3, 0,-3 }),

		Wall({externalWallSize - 35, -externalWallSize + 35, 0,
		externalWallSize - 35, -externalWallSize + 15 + 70, 0,
		externalWallSize - 35, -externalWallSize + 15 + 70, height,
		externalWallSize - 35, -externalWallSize + 35, height },
		textures[0],
		{ 0,0, 3,0, 3,-3, 0,-3 }),



		// concrete
		Wall({ externalWallSize / 2, -externalWallSize, 0,
		externalWallSize / 2, externalWallSize / 2, 0,
		externalWallSize / 2, externalWallSize / 2, 50,
		externalWallSize / 2, -externalWallSize, 50 },
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 100, externalWallSize / 2, 0,
		externalWallSize - 25, externalWallSize / 2, 0,
		externalWallSize - 25, externalWallSize / 2, 50,
		externalWallSize / 2 - 100, externalWallSize / 2, 50 },
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize - 25, externalWallSize / 2, 0,
		externalWallSize - 25, externalWallSize / 2 + 60, 0,
		externalWallSize - 25, externalWallSize / 2 + 60, 50,
		externalWallSize - 25, externalWallSize / 2, 50 },
		textures[1],
		{ 0,0, 1,0, 1,-1, 0,-1 }),

		Wall({ externalWallSize - 25, externalWallSize / 2 + 60, 0,
		externalWallSize - 35, externalWallSize / 2 + 60, 0,
		externalWallSize - 35, externalWallSize / 2 + 60, 50,
		externalWallSize - 25, externalWallSize / 2 + 60, 50 },
		textures[1],
		{ 0,0, 0.25,0, 0.25,-1, 0,-1 }),

		Wall({ externalWallSize - 35, externalWallSize / 2, 0,
		externalWallSize - 35, externalWallSize / 2 + 60, 0,
		externalWallSize - 35, externalWallSize / 2 + 60, 50,
		externalWallSize - 35, externalWallSize / 2, 50 },
		textures[1],
		{ 0,0, 1,0, 1,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 100, externalWallSize / 2, 0,
		externalWallSize / 2 - 100, -externalWallSize + 50, 0,
		externalWallSize / 2 - 100, -externalWallSize + 50, 50,
		externalWallSize / 2 - 100, externalWallSize / 2, 50 },
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 100, -externalWallSize + 50, 0,
		externalWallSize / 2 - 250, -externalWallSize + 50, 0,
		externalWallSize / 2 - 250, -externalWallSize + 50, 50,
		externalWallSize / 2 - 100, -externalWallSize + 50, 50 },
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 250, -externalWallSize + 50, 0,
		externalWallSize / 2 - 250, -externalWallSize + 55, 0,
		externalWallSize / 2 - 250, -externalWallSize + 55, 50,
		externalWallSize / 2 - 250, -externalWallSize + 50, 50 },
		textures[1],
		{ 0,0, 0.2,0, 0.2,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 100, -externalWallSize + 55, 0,
		externalWallSize / 2 - 250, -externalWallSize + 55, 0,
		externalWallSize / 2 - 250, -externalWallSize + 55, 50,
		externalWallSize / 2 - 100, -externalWallSize + 55, 50 },
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 250, -externalWallSize + 90, 0,
		externalWallSize / 2 - 250, externalWallSize - 55, 0,
		externalWallSize / 2 - 250, externalWallSize - 55, 50,
		externalWallSize / 2 - 250,-externalWallSize + 90, 50},
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 250, -externalWallSize + 90, 0,
		externalWallSize / 2 - 245, -externalWallSize + 90, 0,
		externalWallSize / 2 - 245, -externalWallSize + 90, 50,
		externalWallSize / 2 - 250,-externalWallSize + 90, 50},
		textures[1],
		{ 0,0, 0.2,0, 0.2,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 245, -externalWallSize + 90, 0,
		externalWallSize / 2 - 245, externalWallSize - 55, 0,
		externalWallSize / 2 - 245, externalWallSize - 55, 50,
		externalWallSize / 2 - 245,-externalWallSize + 90, 50},
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 250, externalWallSize - 55, 0,
		externalWallSize / 2 + 25, externalWallSize - 55, 0,
		externalWallSize / 2 + 25, externalWallSize - 55, 50,
		externalWallSize / 2 - 250,externalWallSize - 55, 50},
		textures[1],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 + 25, externalWallSize - 55, 0,
		externalWallSize / 2 + 25, externalWallSize, 0,
		externalWallSize / 2 + 25, externalWallSize, 50,
		externalWallSize / 2 + 25,externalWallSize - 55, 50},
		textures[1],
		{ 0,0, 1,0, 1,-1, 0,-1 }),


		// brick
		Wall({ externalWallSize / 2 - 100, externalWallSize / 4 - 50, 0,
		externalWallSize / 2 - 10, externalWallSize / 4 - 50, 0,
		externalWallSize / 2 - 10, externalWallSize / 4 - 50, height,
		externalWallSize / 2 - 100, externalWallSize / 4 - 50, height },
		textures[2],
		{ 0,0, 4,0, 4,-2, 0,-2 }),

		Wall({ externalWallSize / 2 - 10, externalWallSize / 4 - 50, 0,
		externalWallSize / 2 - 10, externalWallSize / 4 - 10, 0,
		externalWallSize / 2 - 10, externalWallSize / 4 - 10, height,
		externalWallSize / 2 - 10, externalWallSize / 4 - 50, height },
		textures[2],
		{ 0,0, 4,0, 4,-2, 0,-2 }),


		Wall({ externalWallSize / 2 - 10, externalWallSize / 4 - 10, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 - 10, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 - 10, height,
		externalWallSize / 2 - 10, externalWallSize / 4 - 10, height },
		textures[2],
		{ 0,0, 4,0, 4,-2, 0,-2 }),

		Wall({ externalWallSize / 2 - 85, externalWallSize / 4 - 10, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 - 15, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 - 15, height,
		externalWallSize / 2 - 85, externalWallSize / 4 - 10, height },
		textures[2],
		{ 0,0, 1,0, 1,-2, 0,-2 }),

		Wall({ externalWallSize / 2 - 10, externalWallSize / 4 - 15, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 - 15, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 - 15, height,
		externalWallSize / 2 - 10, externalWallSize / 4 - 15, height },
		textures[2],
		{ 0,0, 4,0, 4,-2, 0,-2 }),


		Wall({ externalWallSize / 2, externalWallSize / 4 + 15, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 + 15, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 + 15, height,
		externalWallSize / 2, externalWallSize / 4 + 15, height },
		textures[2],
		{ 0,0, 4,0, 4,-2, 0,-2 }),

		Wall({ externalWallSize / 2 - 85, externalWallSize / 4 + 15, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 + 40, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 + 40, height,
		externalWallSize / 2 - 85, externalWallSize / 4 + 15, height },
		textures[2],
		{ 0,0, 4,0, 4,-2, 0,-2 }),

		Wall({ externalWallSize / 2, externalWallSize / 4 + 40, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 + 40, 0,
		externalWallSize / 2 - 85, externalWallSize / 4 + 40, height,
		externalWallSize / 2, externalWallSize / 4 + 40, height },
		textures[2],
		{ 0,0, 4,0, 4,-2, 0,-2 }),

		// wooden
		Wall({ externalWallSize / 2 - 200, -externalWallSize + 50, 0,
		externalWallSize / 2 - 200, -externalWallSize + 150, 0,
		externalWallSize / 2 - 200, -externalWallSize + 150, height,
		externalWallSize / 2 - 200, -externalWallSize + 50, height },
		textures[3],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 200, -externalWallSize + 150, 0,
		externalWallSize / 2 - 135, -externalWallSize + 150, 0,
		externalWallSize / 2 - 135, -externalWallSize + 150, height,
		externalWallSize / 2 - 200, -externalWallSize + 150, height },
		textures[3],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 135, -externalWallSize + 150, 0,
		externalWallSize / 2 - 135, -externalWallSize + 75, 0,
		externalWallSize / 2 - 135, -externalWallSize + 75, height,
		externalWallSize / 2 - 135, -externalWallSize + 150, height },
		textures[3],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 135, -externalWallSize + 75, 0,
		externalWallSize / 2 - 190, -externalWallSize + 75, 0,
		externalWallSize / 2 - 190, -externalWallSize + 75, height,
		externalWallSize / 2 - 135, -externalWallSize + 75, height },
		textures[3],
		{ 0,0, 3,0, 3,-1, 0,-1 }),

		Wall({ externalWallSize / 2 - 190, -externalWallSize + 75, 0,
		externalWallSize / 2 - 190, -externalWallSize + 80, 0,
		externalWallSize / 2 - 190, -externalWallSize + 80, height,
		externalWallSize / 2 - 190, -externalWallSize + 75, height },
		textures[3],
		{ 0,0, 1,0, 1,-1, 0,-1 }),


		Wall({ externalWallSize / 2 - 135, -externalWallSize + 80, 0,
		externalWallSize / 2 - 190, -externalWallSize + 80, 0,
		externalWallSize / 2 - 190, -externalWallSize + 80, height,
		externalWallSize / 2 - 135, -externalWallSize + 80, height },
		textures[3],
		{ 0,0, 3,0, 3,-1, 0,-1 }),




	};
}

Wall World::GetFloor(unsigned int textureId) const
{
	// dirt
	return Wall({ worldSize,worldSize,0,
		worldSize,-worldSize,0,
		-worldSize,-worldSize,0,
		-worldSize,worldSize,0 },
		textureId,
		{ 0,0, 50,0, 50,-50, 0,-50 });
}
