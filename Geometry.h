#pragma once
#include <math.h>

#include "Point.h"


class Geometry
{
public:
	static myNamespace::Point Add(myNamespace::Point a, myNamespace::Point b);
	static myNamespace::Point Subtract(myNamespace::Point a, myNamespace::Point b);
	static float DotProduct(myNamespace::Point a, myNamespace::Point b);
	static myNamespace::Point Project(myNamespace::Point a, myNamespace::Point b);
	static float Distance(myNamespace::Point a, myNamespace::Point b);
	static float DistanceSegmentToPoint(myNamespace::Point A, 
		myNamespace::Point B, myNamespace::Point C);

};

