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

// Reference Properties and Oddities
#if 0			// Listing 8.5		cubes.cpp
#include <iostream>
double cube(double a);
double refcube(double &ra);
int main()
{
	using namespace std;
	double x = 3.0;
	
	cout << cube(x);
	cout << " = cube of " << x << endl;
	cout << refcube(x);
	cout << " = cube of " << x << endl;
	return 0;
}

double cube(double a)
{
	a *= a * a;
	return a;
}

double refcube(double &ra)
{
	ra *= ra * ra;
	return ra;
}
#endif

/* Use const When You Can
	- Using const protects you against programming erros that inadvertently alter data.
	- Using const allows a function to process both const and non-const actual arguments, whereas a function that omits const in the prototype only can accept non-const data.
	- Using a const reference allows the function to generate and use a temporary variable appropriately.
*/

// Using References with a Structure
#if 0			// Listing 8.6		strc_ref.cpp
#include <iostream>
#include <string>
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
	// partial initializations – remaining members set to 0
	free_throws one = {"Ifelsa Branch", 13, 14};
	free_throws two = {"Andor Knott", 10, 16};
	free_throws three = {"Minnie Max", 7, 9};
	free_throws four = {"Whily Looper", 5, 9};
	free_throws five = {"Long Long", 6, 14};
	free_throws team = {"Throwgoods", 0, 0};
	
	// no initialization
	free_throws dup;
	
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
	
	// use return value as argument
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	
	// use return value in assignment
	dup = accumulate(team,five);
	std::cout << "Displaying team:\n";
	display(team);
	std::cout << "Displaying dup after assignment:\n";
	display(dup);
	set_pc(four);
	
	// ill-advised assignment
	accumulate(dup,five) = four;
	// accumulate(dup, five);
	// dup = four;						// overwrite
	std::cout << "Displaying dup after ill-advised assignment:\n";
	display(dup);
	return 0;
}

void display(const free_throws & ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << " Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f *float(ft.made)/float(ft.attempts);
	else
		ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
	// return free_throws & => not return a copy but a reference
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
#endif

/* Being Careful About What a Return Reference Refers To

const free_throws & clone2(free_throws & ft)
{
	free_throws newguy;
	newguy = ft;
	return newguy;				// return reference to copy
}
SHOULD avoid returning pointers to temporary variables
THEN return a reference that was passed as an argument to the function.

A second method is to use new to create new storage.

const free_throws & clond(free_throws & ft)
{
	free_throws * pt;
	*pt  = ft;
	return *pt;
}
then use this function
	free_throws & jolly = clone(three);
this makes jolly a reference to the new structure. but should use delete to free memory.
*/
// 400 pg

// Using References with a Class Object
#if 0				// Listing 8.7 strquote.cpp
#include <iostream>
#include <string>
using namespace std;

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);		// has side effect
const string & version3(string & s1, const string & s2);		// bad design

int main()
{
	string input;
	string copy;
	string result;
	
	cout << "Enter a string: ";
	getline(cin, input);
	copy = input;
	
	cout << "Your string as entered: " << input << endl;
	result = version1(input, "***");		// the contents of the return location are copied to the string named result; temp -> result (type string)
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;
	
	result = version2(input, "###");
	// it's safe to return s1 as a reference.
	// version2(input, "###");			// input altered directly
	// result = input;								// reference to s1 is reference to input
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;
	cout << "Resetting original string.\n";
	input = copy;
	
	result = version3(input, "@@@");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;
	
	return 0;
}

string version1(const string & s1, const string & s2)
{
	string temp;
	
	temp = s2 + s1 + s2;
	return temp;
}

const string & version2(string & s1, const string & s2)		// has side effect
{
	// directly alters the original string
	s1 = s2 + s1 + s2;
	return s1;
}

const string & version3(string & s1, const string & s2)		// bad design
{
	string temp;
	
	temp = s2 + s1 + s2;
	// unsafe to return reference to local varaible
	return temp;
}
#endif

// Another Object Lesson: Objects, Inheritance, and References
#if 0				// Listing 8.8 filefunc.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main()
{
	ofstream fout;
	const char * fn = "ep-data.txt";
	fout.open(fn);
	
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}
	
	double objective;
	cout << "Enter the focal length of your telescope objective in mm: ";
	cin >> objective;
	
	double eps[LIMIT];
	cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "Done\n";
	return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);			// save initial formatting state
	os.precision(0);
	os << "Focal length of objective: " << fo << " mm\n";
	os.setf(ios::showpoint);			// set various formatting states.
															// fixed decimal-point notation.
	os.precision(1);
	
	os.width(12);
	os << "f.l. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int (fo/fe[i] + 0.5) << endl;	
	}
	os.setf(initial);				// restore initial formatting state
}
#endif

/* A function uses passed data without modifying it:
	- If the data object is small(i.g. a built-in data type or a small structure), =>pass it by value.
	- If the data object is an array
	=>use a pointer. Make the pointer to pointer to const.
	- If the data object is a good-sized structure
	=> use a const pointer of a const reference. Make the pointer or reference const.
	- If the data object is a class object,
	=> use a const reference. the standard way to pass class object arguments is by reference.
	
A function modifies data in the calling function:
	- If the data object is a built-in data type
	=> use a pointer.
	- If the data object is an array
	=> use your only choise: a pointer
	- If the data is a structure
	=> use a reference or a pointer.
	- If the data object is a class object
	=> use a reference	
*/
// 409 pg