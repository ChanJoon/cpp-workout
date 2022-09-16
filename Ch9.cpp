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