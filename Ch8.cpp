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
// 409 pg\

// Default Arguments
#if 0		// Listing 8.9	left.cpp
#include <iostream>
const int ArSize = 80;
char * left(const char * str, int n = 1);
int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "Enter a string:\n";
	cin.get(sample, ArSize);
	
	char * ps = left(sample, 4);
	cout << ps << endl;
	delete [] ps;
	
	ps = left(sample);
	cout << ps << endl;
	delete [] ps;
	
	return 0;
}

char * left(const char * str, int n)
{
	if(n < 0)
		n = 0;
	char * p = new char[n+1];
	int i;
	for (i = 0; i < n && str[i]; i++)		// str[i] reaches the null character, the loop terminates.
		p[i] = str[i];		// copy characters
	while (i <= n)
		p[i++] = '\0';	// set rest of string to '\0'
	return p;
}
#endif

/*	set n to the smaller of the passed value and the string length.
	int len = strlen(str);
	n = (n < len) ? n : len;
	char * p = new char[n+1];
*/

#if 0			// Listing 8.10	leftover.cpp
#include <iostream>
unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);

int main()
{
	using namespace std;
	char * trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char * temp;
	
	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete [] temp;		// point to temporary storage
	}
	return 0;
}

// This function returns the first ct digits of the number num
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;
	
	if (ct == 0 || num == 0)
		return 0;
	while(n /= 10)
		digits++;
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}

// This function return a pointer to a new string
char * left(const char * str, int n)
{
	if(n<0)
		n = 0;
	char * p = new char[n+1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}
#endif

// When to Use Function Overloading
// the same task but with different forms of data.

/* Generic programming; Function Templates
	template <typename AnyType>
	void Swap(AnyType &a, AnyType &b)
	{
		AnyType temp;
		temp = a;
		a = b;
		b = temp;
	}
*/
// 419 pg

#if 0			// Listing 8.11	funtemp.cpp
#include <iostream>
// function template prototype
template <typename T>	// or class T
void Swap(T &a, T &b);

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper: \n";
	Swap(i, j);
	cout << "Now i, j = " << i << ", " << j << ".\n";
	
	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x,y); // generates void Swap(double &, double &)
	cout << "Now x, y = " << x << ", " << y << ".\n";
	
	// cin.get();
	return 0;
}

// function template definition
template <typename T>
void Swap(T &a, T &b)
{
	T temp;		// temp a variable of type T
	temp = a;
	a = b;
	b = temp;
}
#endif

#if 0			// Listing 8.13	twoswap.cpp
#include <iostream>
template <typename T>
void Swap(T &a, T &b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

// explicit specialization
template <> void Swap<job> (job &j1, job &j2);
void Show(job &j);

int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	
	cout << "Using compiler-generated int swapper: \n";
	Swap(i, j);		// generates void Swap(int &, int &)
	cout << "Now i, j = " << i << ", " << j << ".\n";
	
	job sue = {"Susan Yaffee", 73000.60, 7};
	job sidney = {"Sidney Taffee", 78060.72, 9};
	cout << "Before job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "After job swapping:\n";
	Show(sue);
	Show(sidney);
	// cin.get();
	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<job> (job &j1, job &j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job &j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}
#endif

/* Instantiations and Specializations
	When the compiler uses the template to generate a function definition for a particular type, the result is termed an instantiation
	
	Implicit instantiations, explicit instantiations, and explicit specializations collectively are termed specializations.
*/
// 430pg

// A Partial Ordering Rules Example
#if 0			// Listing 8.14		tempover.cpp
#include <iostream>

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];
	
	// set pointers to the amount members of the structures in mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	
	cout << "Listing Mr. E's counts of things:\n";
	// things is an array of int
	ShowArray(things, 6);		// uses template A
	cout << "Listing Mr.E's debts:\n";
	// pd is an array of pointers to double
	ShowArray(pd, 3);
	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}
#endif

// Making Your Own Choices
#if 0// Listing 8.15		choices.cpp
#include <iostream>

template<class T>		// or template <typename T>
T lesser(T a, T b)			// #1
{
	return a < b ? a : b;
}

int lesser (int a, int b)	// #2
{
	a = a < 0? -a : a;
	b = b < 0? -b : b;
	return a < b ? a : b;
}

int main()
{
	using namespace std;
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;
	
	cout << lesser(m, n) << endl;
	cout << lesser(x, y) << endl;
	cout << lesser<>(m, n) << endl;
	cout << lesser<int>(x, y) << endl;
	
	return 0;
}
#endif