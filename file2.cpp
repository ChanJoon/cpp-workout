// Listing 9.3	file2.cpp
#include <iostream>
#include <cmath>
#include "coordin.h"

// conver rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;
	
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle  = atan2(xypos.y, xypos.x);
	return answer;
}

// show polar coordinates, converting angle to degrees
void show_polar (polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;
	
	cout << "distance = " << dapos.distance;
	cout << ", angle = " << dapos.angle * Rad_to_deg;
	cout << " degress\n";
}