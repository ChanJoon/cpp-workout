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

#if 0 // Listing 9.2	file1.cpp
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
#endif

#if 0		// Listing 9.3	file2.cpp
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
#endif


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

/* Static Duration Variables
	external linkage; accessible across files
	internal linkage; accessible to functions within a single file
	no linkage; accessible to just one function or to one block within a function
*/

/* Initializing Static Variables
	zero-initialized
	constant expression initialization
	dynamic initialization
	
	#include <cmath>
	int x;
	int y = 5;
	long z = 13 * 13;
	const double pi = 4.0 * atan(1.0);
	
	The One Definition Rule
	// file01.cpp
	extern int cats = 20;
	int dogs = 22;
	int fleas;
	...
	// file02.cpp
	// use cats and dogs from file01.cpp
	extern int cats;
	extern int dogs;
	...
	// file98.cpp
	// use cats, dogs, and fleas from file01.cpp
	extern int cats;
	extern int dogs;
	extern int fleas;
*/

#if 0			// Listing 9.5	external.cpp
// compile with supoort.cpp
#include <iostream>
using namespace std;

// external variable
double warming = 0.3;
// function prototype
void update(double dt);
void local();

int main()
{
	cout << "Global warming is " << warming << " degress.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degrees.\n";
	local();
	cout << "Global warming is " << warming << " degrees.\n";
	return 0;
}

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
	cout << "But global warming = " << ::warming;		// scope-resolution operator
	cout << " degress.\n";
}
#endif

/*
> g++ external1.cpp support.cpp -o extern1
> .\extern1.exe
	Global warming is 0.3 degress.
	Updating global warming to 0.4 degress.
	Global warming is 0.4 degrees.
	Local warming = 0.8 degrees.
	But global warming = 0.4 degress.
	Global warming is 0.4 degrees.
*/
// 470pg

// Static Storage Duration, No Linkage
#if 0			// Listing 9.9 static.cpp
#include <iostream>
// constants
const int ArSize = 10;

// function prototype
void strcount(const char * str);

int main()
{
	using namespace std;
	char input[ArSize];
	char next;
	
	cout << "Enter a line:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while(next != '\n')	// while string didn't fit
			cin.get(next);			// dispose of remainder
		strcount(input);
		
		cout << "Enter next line (empty line to quit):\n";
		cin.get(input, ArSize);
	}
	cout << "End\n";
	return 0;
}

void strcount(const char * str)
{
	using namespace std;
	static int total = 0;
	int count = 0;
	
	cout << "\"" << str << "\" contains ";
	while (*str++)
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
#endif

/* Initialization with the new Operator C++11

The new standard allows the following; using braces
	struct where {double x; double y; double z;};
	where * one = new where {2.5, 5.3, 7.2};
	int * ar = new int [4] {2,4,6,7};
also can for sigle-valued variables:
	int *pin = new int {};
	double * pdo = new double {99.99};
*/

// The Placement new Operator
#if 0			// Listing 9.10	newplace.cpp
#include <iostream>
#include <new>
const int BUF = 512;
const int N = 5;
char buffer[BUF];		// chunk of memory

int main()
{
	using namespace std;
	double *pd1, *pd2;
	int i;
	cout << "Calling new and placement new:\n";
	
	pd1 = new double[N];					// use heap
	pd2 = new (buffer) double[N];	// use buffer array
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "Memory addresses:\n" << " heap : " << pd1 << " static: " << (void *) buffer << endl;
	cout << "Memory contents: \n";
	for(i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	
	cout << "\nCalling new and placement new a second time:\n";
	double *pd3, *pd4;
	pd3 = new double[N];					// fine new address
	pd4 = new (buffer) double[N];	// overwrite old data
	for (i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "Memory contents: \n";
	for(i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}
	
	cout << "\nCalling new and placement new a third time:\n";
	delete [] pd1;
	
	pd1= new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
	cout << pd1[i] << " at " << &pd1[i] << "; ";
	cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	
	delete [] pd1;
	delete [] pd3;
	return 0;
}
#endif
// 481pg
// Namespace ~491pg

#if 0			// Listing 9.11	namesp.h
#include <string>
// create the pers and debts namespaces
namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void getPerson (Person &);
	void showPerson (const Person &);
}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};
	void getDebt(Debt &);
	void showDebt(const Debt &);
	double sumDebts(const Debt ar[], int n);
}

// Listing 9.12	namesp.cpp
#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;
	void getPerson(Person & rp)
	{
		cout << "Enter first name: ";
		cin >> rp.fname;
		cout << "Enter last name: ";
		cin >> rp.lname;
	}
	void showPerson(const Person & rp)
	{
		std::cout << rp.lname << ", " << rp.fname;
	}
	
	namespace debts
	{
		void getDebt(Debt & rd)
		{
			getPerson(rd.name);
			std::cout << "Enter debt: ";
			std::cin >> rd.amount;
		}
		void showDebt(const Debt & rd)
		{
			showPerson(rd.name);
			std::cout << ": $" << rd.amount << std::endl;
		}
		double sumDebts(const Debt ar[], int n)
		{
			double total = 0;
			for (int i = 0; i < n; i++)
				total += ar[i].amount;
			return total;
		}
	}
}

// Listing 9.13 usenmsp.cpp
// usenmsp.cpp
#include <iostream>
#include "namesp.h"

void other(void);
void another(void);
int main(void)
{
	using debts::Debt;
	
	using debts::showDebt;
	Debt golf = { {"Benny", "Goatsniff"}, 120.0};
	showDebt(golf);
	other();
	another();
	
	return 0;
}

void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;
	Person dg = {"Doodles", "Glister"};
	showPerson(dg);
	
	cout << endl;
	Debt zippy[3];
	 int i;
	 for (i = 0; i < 3; i++)
		 getDebt(zippy[i]);
	 for (i = 0; i < 3; i++)
		 showDebt(zippy[i]);
	 cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
	 return;
}

void another(void)
{
	using pers::Person;
	Person collector = {"Milo", "Rightshift"};
	pers::showPerson(collector);
	std::cout << std::endl;
}
#endif