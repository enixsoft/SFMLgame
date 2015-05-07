#pragma once
#include <math.h>

class Point {
private:
	float xval, yval;
public:
	// Constructor uses default arguments to allow calling with zero, one,
	// or two values.
	Point(float x = 0.0, float y = 0.0) {
		xval = x;
		yval = y;
	}

	// Extractors.
	float getX() { return xval; }
	float getY() { return yval; }

	// Distance to another point.  Pythagorean thm.
	float dist(Point other) {
		float xd = xval - other.xval;
		float yd = yval - other.yval;
		return sqrt(xd*xd + yd*yd);
	}

	// Add or subtract two points.
	Point add(Point b)
	{
		return Point(xval + b.xval, yval + b.yval);
	}
	Point sub(Point b)
	{
		return Point(xval - b.xval, yval - b.yval);
	}

	// Move the existing point.
	void move(float a, float b)
	{
		xval += a;
		yval += b;
	}

	// Print the point on the stream.  The class ostream is a base class
	// for output streams of various types.

};
