#pragma once
#include <math.h>
//pomocna class point 
class Point {
private:
	float xval, yval;
public:
	// v konstruktory sa nachadzaju aj defaultne hodnoty
	Point(float x = 0.0, float y = 0.0) {
		xval = x;
		yval = y;
	}

	// gettery
	float getX() { return xval; }
	float getY() { return yval; }

	// vzdialenost od ineho bodu
	float dist(Point other) {
		float xd = xval - other.xval;
		float yd = yval - other.yval;
		return sqrt(xd*xd + yd*yd);
	}

	// scitaj alebo odcitaj dva body
	Point add(Point b)
	{
		return Point(xval + b.xval, yval + b.yval);
	}
	Point sub(Point b)
	{
		return Point(xval - b.xval, yval - b.yval);
	}

	//presun bod na iny
	void movePoint(float a, float b)
	{
		xval += a;
		yval += b;
	}


};
