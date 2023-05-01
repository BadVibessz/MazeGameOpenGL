#include "Geometry.h"

myNamespace::Point Geometry::Add(myNamespace::Point a, myNamespace::Point b)
{
	return myNamespace::Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

myNamespace::Point Geometry::Subtract(myNamespace::Point a, myNamespace::Point b)
{
	return myNamespace::Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

float Geometry::DotProduct(myNamespace::Point a, myNamespace::Point b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

myNamespace::Point Geometry::Project(myNamespace::Point a, myNamespace::Point b)
{
	float k = DotProduct(a, b) / DotProduct(b, b);
	return myNamespace::Point(k * b.x, k * b.y, k * b.z);
}

float Geometry::Distance(myNamespace::Point a, myNamespace::Point b)
{
	float x = b.x - a.x;
	float y = b.y - a.y;
	float z = b.z - a.z;

	return sqrt(x * x + y * y + z * z);
}

float Geometry::DistanceSegmentToPoint(myNamespace::Point A, 
	myNamespace::Point B, myNamespace::Point C)
{
	// Compute vectors AC and AB
	auto AC = Subtract(C, A);
	auto AB = Subtract(B, A);

	// Get point D by taking the projection of AC onto AB then adding the offset of A
	auto D = Add(Project(AC, AB), A);

	auto AD = Subtract(D, A);

	// D might not be on AB so calculate k of D down AB (aka solve AD = k * AB)
	// We can use either component, but choose larger value to reduce the chance of dividing by zero
	float k = fabs(AB.x) > fabs(AB.y) ? AD.x / AB.x : AD.y / AB.y;

	// Check if D is off either end of the line segment
	if (k <= 0.0)
		return Distance(C, A);

	if (k >= 1.0)
		return Distance(C, B);

	return Distance(C, D);
}
