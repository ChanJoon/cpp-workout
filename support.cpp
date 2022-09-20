// Listing 9.6	support.cpp
// compile with external.cpp
#include <iostream>
extern double warming;

// function prototype
void update(double dt);
void local();

using std::cout;
void update(double dt)
{
	extern double warming;
	warming += dt;
	cout << "Updating global warming to " << warming;
	cout << " degress.\n";
}

void local()
{
	double warming = 0.8;
	
	cout << "Local warming = " << warming << " degrees.\n";
	cout << "But global warming = " << ::warming;
	cout << " degress.\n";
}