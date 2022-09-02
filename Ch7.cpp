/* Ch7. Functions: C++'s Programming Modules */

// Fuction Review
#if 0					// Listing 7.1 calling.cpp
#include <iostream>

void simple();			// function prototype

int main()
{
	using namespace std;
	cout << "main() call function : \n";
	simple();				// function call
		cout << "main() is finished \n";
		
	return 0;
}

void simple()
{
	using namespace std;
	cout << "a simple function.\n";
}
#endif

/*
typeName functionName(parameterList)
{
	statement
	return value;			// optional; type cast to typeName
}
*/

// Prototyping and Calling a Function
#if 0				// Listing 7.2 protos.cpp
#include <iostream>
void cheers(int);
double cube(double x);
int main()
{
	using namespace std;
	
	cheers(5);											// function call
	cout << "Give a number: ";
	
	double side;
	cin >> side;
	double volume = cube(side);		// function call
	cout << "A " << side << "-foot cube has a volume of " ;
	cout << volume << " cubic feet.\n";
	cheers(cube(2));								// prototype protection at work
	return 0;
}

void cheers(int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << "Cheers";
	cout << endl;
}

double cube(double x)
{
	return x * x * x;
}
#endif

/*
Why Prototypes?
	1. A prototype descibes the function to the compiler.
	2. the compiler knows how many bytes to retrive and how to interpret them.(in main)
	3. Not efficient. if not declared. (the compiler will searching the rest of the file)
	4. reduce the chances of program errors. -> return value / type and number of arguments
Function Arguments and Passing by Value
	created variable; formal parameter passed to the function; actual parameter
*/

// Multiple Arguments & Local variables
// Listing 7.3 twoarg.cpp
#include <iostream>
using namespace std;
void n_chars(char, int);
int main()
{
	int times;
	char ch;
	
	cout << "Enter a character: ";
	cin >> ch;
	while (ch != 'q')			// q to quit
	{
		cout << "Enter an interger: ";
		cin >> times;
		n_chars(ch, times);		// function with 2 arguments
		cout << "\nEnter another char or pree the q to quit: ";
		cin >> ch;
	}
	cout << "The value of times is " << times << ".\n";
	
	return 0;
}

void n_chars(char c, int n)
{
	while (n-- > 0)				// continue until n reaches 0
		cout << c;
}