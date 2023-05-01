#pragma once
#include <glut.h>
#include <math.h>
#include <vector>

#include "Point.h"
#include "Wall.h"
#include "Geometry.h"

#define PI 3.1415926535897932

class MovementHandler
{

private:
	myNamespace::Point _position;
	std::vector<Wall> _walls;
	float cameraRadius = 3.f;

	bool IsValidPoisition(myNamespace::Point position) const;

	myNamespace::Point GetNextPosition(float speed, float angle);

public:

	bool usingCollision = true;

	float xRotationSpeed;
	float zRotationSpeed;
	float movementSpeed;

	float xRotationAngle;
	float zRotationAngle = 90;

	MovementHandler(myNamespace::Point position = myNamespace::Point(0, 0, 0),
		float xRotationSpeed = 0.5f,
		float zRotationSpeed = 0.5f,
		float movementSpeed = 0.5f);

	myNamespace::Point GetPosition() const;


	void AddWalls(std::vector<Wall> walls);

	void LookUp();
	void LookDown();
	void LookLeft();
	void LookRight();

	void MoveForward();
	void MoveBackwards();
	void MoveRight();
	void MoveLeft();

};

