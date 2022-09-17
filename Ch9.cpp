/* Ch9. Memory Models and Namespaces

Separate Compilation
	Instead of placing the structure declaration in each file, you can place them in a header file. then include header file in each source code.
	Also, place the function prototypes in the header file.
	
	Divide the original progrma into three parts:
	- A header file that contains the structure declarations and prototypes for functions that uses those structures.
	- A source code file that contains the code for the structure-related functions.
	- A source code file that contains the code that calls the structure-related functions.
	
	Commonly found in header files:
	- Function prototypes
	- Symbolic constants defined using #define or const
	- Structure declarations
	- Class declarations
	- Template declarations
	- Inline functions
*/

// Listing 9.1		coordin.h
// structure templates
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif

// Listing 9.2	file1.cpp
#include <iostream>
#include "coordin.h"
using namespace std;
int main()
{
	rect rplace;
	polar pplace;
	
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}

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


/* In Terminal,
	> g++ file1.cpp file2.cpp -o files
	> ./files
	로 여러개의 cpp을 같이 컴파일 하고 link all the resulting "files.exe" files together.
	
	> g++ -c files1.cpp
	> g++ -c files2.cpp
	> g++ file1.o file2.o
	> ./.a out
	로 각각 컴파일하여 object code file을 만들고 실행 파일을 만들 수도 있다.
*/

// 459pg