#include "MovementHandler.h"


bool MovementHandler::IsValidPoisition(myNamespace::Point position) const
{
	for (auto wall : _walls)
	{
		// todo: calc dist between wall direction vector and position

		auto coords = wall.GetCoordinates();

		auto A = myNamespace::Point(coords[0], coords[1], coords[2]);
		auto B = myNamespace::Point(coords[3], coords[4], coords[5]);

		if (Geometry::DistanceSegmentToPoint(A, B, position) <= cameraRadius)
			return false;
	}

	return true;
}

myNamespace::Point MovementHandler::GetNextPosition(float angle, float speed)
{
	myNamespace::Point nextPoisition;

	nextPoisition.x = _position.x + sin(angle) * speed;
	nextPoisition.y = _position.y + cos(angle) * speed;
	nextPoisition.z = 0;

	return nextPoisition;
}

MovementHandler::MovementHandler(myNamespace::Point position,
	float xRotationSpeed, float zRotationSpeed, float movementSpeed)
{
	this->_position = position;
	this->xRotationSpeed = xRotationSpeed;
	this->zRotationSpeed = zRotationSpeed;
	this->movementSpeed = movementSpeed;
}

myNamespace::Point MovementHandler::GetPosition() const
{
	return myNamespace::Point(_position.x, _position.y, _position.z);
}

void MovementHandler::LookUp()
{
	zRotationAngle = zRotationAngle + zRotationSpeed > 180 ? 180
		: zRotationAngle + zRotationSpeed;
}

void MovementHandler::LookDown()
{
	zRotationAngle = zRotationAngle - zRotationSpeed < 0 ? 0
		: zRotationAngle - zRotationSpeed;
}

void MovementHandler::AddWalls(std::vector<Wall> walls)
{
	_walls.insert(_walls.end(), walls.begin(), walls.end());
}

void MovementHandler::LookLeft()
{
	xRotationAngle = xRotationAngle + xRotationSpeed;
}

void MovementHandler::LookRight()
{
	xRotationAngle = xRotationAngle - xRotationSpeed;
}

void MovementHandler::MoveForward()
{
	float angle = -xRotationAngle / 180 * PI;

	auto nextPoisition = GetNextPosition(angle, movementSpeed);

	if(!usingCollision) _position = nextPoisition;
	else if(IsValidPoisition(nextPoisition))
		_position = nextPoisition;
}

void MovementHandler::MoveBackwards()
{
	float angle = -xRotationAngle / 180 * PI;

	auto nextPoisition = GetNextPosition(angle, -movementSpeed);
	if (!usingCollision) _position = nextPoisition;
	else if (IsValidPoisition(nextPoisition))
		_position = nextPoisition;
}

void MovementHandler::MoveRight()
{
	float angle = (-xRotationAngle / 180 * PI) + PI * 0.5;

	auto nextPoisition = GetNextPosition(angle, movementSpeed);
	if (!usingCollision) _position = nextPoisition;
	else if (IsValidPoisition(nextPoisition))
		_position = nextPoisition;
}

void MovementHandler::MoveLeft()
{
	float angle = (-xRotationAngle / 180 * PI) - PI * 0.5;

	auto nextPoisition = GetNextPosition(angle, movementSpeed);
	if (!usingCollision) _position = nextPoisition;
	else if (IsValidPoisition(nextPoisition))
		_position = nextPoisition;
}
