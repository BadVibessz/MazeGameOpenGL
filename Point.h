#pragma once

namespace myNamespace
{
	class Point
	{

	public:
		float x, y, z;

		Point() = default;

		Point(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

	};
}



