// randwalk.cpp -- using the Vector class
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main()
{
	using namespace std;

	srand(time(0));

	double dir;
	VECTOR::Vector step;
	VECTOR::Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target, dstep;

	cout << "Enter target distance (q to quite): ";

	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			dir = rand() % 360;
			step.reset(dstep, dir, VECTOR::Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, location:\n";
		cout << result << endl;
		
		result.polar_mode();
		cout << " or\n" << result << endl;
		
		cout << "Average outward distance per step = " << result.magval() / steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quite): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}