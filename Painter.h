#pragma once
#include <vector>
#include <glut.h>

#include "Wall.h"

class Painter
{
public:
	static void DrawWall(const Wall& wall);
	static void DrawWalls(const std::vector<Wall>& walls);

	static void DrawFog(float density = 0.05, float r = 0, float g = 0, float b = 0);

};

