// Adventures in Functions

// C++ Inline Functions
#if 0			// Lisiting 8.1 inline.cpp
#include <iostream>

// an inline function definition
inline double square(double x) { return x * x; }

int main()
{
	using namespace std;
	double a, b;
	double c = 13.0;
	
	a = square(5.0);
	b = square(4.5 + 7.5);
	
	cout << "a = " << a << ", b = " << b << "\n";
	cout << "c = " << c;
	cout << ", c squared = " << square(c++) << "\n";
	cout << "c = " << c << endl;
	return 0;
}
#endif

/* Inline Versus Macros
	C uses the preprocessor #define statement to provide macros
	
	#define SQUARE(X) X*X
	
	a = SQUARE(4.5 + 7.5); is replaced by b = 4.5 + 7.5 * 4.5 + 7.5;
	b = SQUARE(c++); is replace by d = c++ * c++;
	
	then #define SQUARE(X) ( (X)*(X) )
	Still, SQUARE(c++) increments c twice
*/

// Reference Variables
#if 0			// Listing 8.2	firstref.cpp
#include <iostream>
int main()
{
	using namespace std;
	int rats = 101;
	int & rodents = rats;		// rodents an alias for rats; a reference
	// & not the address operator. reference-to-int
	// same value and same memory location.
	
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	
	// some implementations require type casting the following
	// addresses to type unsigned
	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;
	
	return 0;
}
#endif

/* References as Function Parameters
	Passing by reference allows a called function to access variables in the calling function.
	the usual approach of passing variables ( using pointers ) :  swapping the contest of copies of the original variables
	but references : the function can work with the original data.
*/

#if 0			// Listing 8.4	swaps.cpp
#include <iostream>
void swapr(int & a, int & b);		// aliases
void swapp(int * p, int * q);		// addresses
void swapv(int a, int b);				// new variables

int main()
{
	using namespace std;
	int wallet1 = 300;
	int wallet2 = 350;
	
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;
	
	cout << "Using references to swap contents:\n";
	swapr(wallet1, wallet2); // pass variables
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;
	
	cout << "Using pointers to swap contents again:\n";
	swapp(&wallet1, &wallet2); // pass addresses of variables
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;
	
	cout << "Trying to use passing by value:\n";
	swapv(wallet1, wallet2); // pass values of variables
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;
	
	return 0;
}

void swapr(int & a, int & b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

void swapp(int * p, int * q)
{
	int temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}
#endif