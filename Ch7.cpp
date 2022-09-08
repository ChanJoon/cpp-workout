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
#if 0			// Listing 7.3 twoarg.cpp
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
#endif		// 316pg

# if 0			// Lising 7.4 lotto.cpp
#include <iostream>

long double probability(unsigned numbers, unsigned picks);
int main()
{
	using namespace std;
	double total, choices;
	
	cout << "Enter the total number of choices on the game card and \n"
				 "the number of picks allowed: \n";
	 while( (cin >> total >> choices) && choices <= total)
	 {
		 cout << "You have one chance in ";
		 cout << probability(total, choices);
		 cout << " of winnig.\n";
		 cout << "Next two numbers (q to quit): ";		// if 'q' entered, false returned
	 }
	 
	 return 0;

}
	 
 long double probability(unsigned numbers, unsigned picks)
 {
	 long double result = 1.0;
	 long double n;
	 unsigned p;
	 
	 for (n = numbers, p = picks; p > 0; n--, p--)
		 result = result * n / p;
	 return result;
 }
 #endif
 
 // Functions and Arrays
 #if 0			// Listing 7.5	arrfun1.cpp
 #include <iostream>
 const int ArSize = 8;
 int sum_arr(int arr[], int n);
 int main()
 {
	 using namespace std;
	 int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
	 
	 int sum = sum_arr(cookies, ArSize);
	 cout << "Total cookies eaten: " << sum << "\n";
	 return 0;
 }
 
 int sum_arr(int arr[], int n)			// int arr[] == int * arr
 {
	 int total = 0;
	 for (int i = 0; i < n; i++)
		 total += arr[i];
	 return total;
 }
 #endif
 
 // arr[i] == *(ar + i)			values in two notations
 // &arr[i] == ar + i				addressed in two notations
 
 /* Protecting the Array with const
 void show_array (const double ar[], int n);
  => treats the array as read-only data.
	  void show_array (const double ar[], int n)
	  {
		  using namespace std;
		  for (int i = 0; i < n; i++)
		  {
			  cout << "Property #" << (i + 1) << ": $";
			  cout << ar[i] << endl;
		  }
	  }
*/

#if 0			// Listing 7.7 arrfun3.cpp
#include <iostream>
const int Max = 5;

int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
	using namespace std;
	double properties[Max];
	
	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (! (cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; enter a # : ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

int fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}

void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	}
}

void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}
#endif

/* Functions and Two-Deimensinal Arrays

int sum(int (*ar2)[4], int size);
int sum(int ar2[][4], int size);

int sum(int ar2[][4], int size)
{
	int total = 0;
	for (int r = 0; r < size; r++)
		for (int c = 0; c < 4; c++)
			total += ar2[r][c];
	return total;
}

ar2[r][c] == *(*(ar2 + r) + c) 			// same thing

ar2							// pointer to first row of an array of 4 int
ar2 + r					// pointer to row r (an array of 4 int)
*(ar2 + r)				// row r (an array of 4 int, hence the name of an array,
								// thus a pointer to the first int in the row, i.e., ar2[r]

* (ar2 + r) + c		// pointer int number c in row r, i.e., ar2[r] + c
*(*(ar2 + r) + c)	// value of int number c in row r, i.e, ar2[r][c]
*/

// Functions with C-Style String Arguments
#if 0			// Lising 7.9	strgfun.cpp
#include <iostream>
unsigned int c_in_str(const char * str, char ch);
int main()
{
	using namespace std;
	char mmm[15] = "minumum";
	// some systems require preceding char with static to
	// enable array initialization
	
	const char *wail = "ululate";		// wail point to string
	
	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	
	cout << ms << " m characters in " << mmm << endl;
	cout << us << " u characters in " << wail << endl;
	return 0;
}

// this function counts the number of ch characteres
unsigned int c_in_str(const char * str, char ch)
{
	unsigned int count = 0;
	
	while (*str)			// quit when *str is '\0'
	{
		if (*str == ch)
			count ++;
		str++;					// move pointer to next char
	}
	return count;
}
#endif

// Functions That Return C-Style Strings
#if 0			// Listing 7.10	strgback.cpp
#include <iostream>
char * buildstr(char c, int n);
int main()
{
	using namespace std;
	int times;
	char ch;
	
	cout << "Enter a character: ";
	cin >> ch;
	cout << "Enter a integer: ";
	cin >> times;
	
	char *ps = buildstr(ch, times);
	cout << ps << endl;
	
	delete [] ps;						// free memory
	ps = buildstr('+', 20);	// reuse pointer
	
	cout << ps << "-DONE-" << ps << endl;
	delete [] ps;						// free memory
	return 0;
}

// builds string made of n c characters
char * buildstr(char c, int n)
{
	char * pstr = new char[n + 1];
	pstr[n] = '\0';
	while (n-- > 0)
		pstr[n] = c;
	return pstr;
}
#endif

/* Program Notes
while(n-- > 0)
	pstr[n] = c;

the while loop test condition compares 1 to 0, the test to be true, and continues.
decrements n to 0, so pstr[0] is the last element set to c.
*/

// Passing and Returning Structures
#if 0				// Lising 7.11	trave1.cpp
#include <iostream>
struct travel_time
{
	int hours;
	int mins;
};
const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
	using namespace std;
	travel_time day1 = {5, 45};
	travel_time day2 = {4, 55};
	
	travel_time trip = sum(day1, day2);
	cout << "Two-day total: ";
	show_time(trip);
	
	travel_time day3 = {4, 32};
	cout << "Three-day total: ";
	show_time(sum(trip, day3));
	
	return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
	travel_time total;
	
	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;
	
	return total;
}

void show_time(travel_time t)
{
	using namespace std;
	cout << t.hours << " hours, " << t.mins << " minutes.\n";
}
#endif
// 345pg

#if 0		// Lising 7.12 strctfun.cpp
#include <iostream>
#include <cmath>

// structure
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

//prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;
	
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers: ";
	}
	cout << "Done.\n";
	return 0;
}

// convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;
	
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}
// show polar coordinates, converting angle to degrees
void show_polar(polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;
	
	cout << "distance = " << dapos.distance;
	cout << ", angle = " << dapos.angle * Rad_to_deg;
	cout << " degress\n";
}
#endif

/* Passing Structure Addresses
To save time and space, use pointers to structures.
 - When calling the function, pass it the address of the structure &pplace (rather than pplace)
 - Declare the formal parameter to be a pointer-to-structure
 - use the indirect membership operator -> (rather than the membership operator dot)
 
 void show_polar(const polar * pda)
 {
	 using namespace std;
	 const double radToDeg = 57.2958;
	 
	 cout << "distance" << pda -> distance;
	 cout << ", angle" << pda->angle * radToDeg;
	 cout << " degrees\n";
 }
 
 To take full advantage of pointer efficiency, use a pointer instead of a return value.
 2 pointers to the function; the structure to be converted & that to hold the conversion.
 then, the first argument is const pointer, the second is not const.
 */
 
 #if 0			// Listing 7.13 strtptr.cpp
 #include <iostream>
 #include <cmath>
 // structure
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

//prototypes
void rect_to_polar(const rect *pxy, polar *pda);
void show_polar(const polar * pda);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;
	
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		rect_to_polar(&rplace, &pplace);		// pass addresses
		show_polar(&pplace);							// pass addresses
		cout << "Next two numbers: ";
	}
	cout << "Done.\n";
	return 0;
}

// convert rectangular to polar coordinates
void rect_to_polar(const rect *pxy, polar *pda)
{
	using namespace std;
	pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}
// show polar coordinates, converting angle to degrees
void show_polar(const polar * pda)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;
	
	cout << "distance = " << pda->distance;
	cout << ", angle = " << pda->angle * Rad_to_deg;
	cout << " degress\n";
}
#endif

#if 0			// Listing 7.14	topfive.cpp
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 5;
void display(const string sa[], int n);
int main()
{
	string list[SIZE];
	cout << "Enter your " << SIZE << " favorite astronomical sight:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i  + 1 << ": ";
		getline(cin,list[i]);
	}
	cout << "Your list:\n";
	display(list, SIZE);
	
	return 0;
}

void display(const string sa[], int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ": " << sa[i] << endl;
}
#endif

// Functions and array Objects
#if 0			// Lising 7.15 arrobj.cpp
#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};

void fill(std::array<double, Seasons> * pa);
void show(std::array<double, Seasons> da);

int main()
{
	std::array<double, Seasons> expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

void fill(std::array<double, Seasons> * pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> (*pa)[i];
	}
}

void show(std::array<double, Seasons> da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
#endif
// 357pg

// Recursion
#if 0		// Listing 7.16 recur.cpp
#include <iostream>
void countdown(int n);

int main()
{
	countdown(4);
	return 0;
}

void countdown(int n)
{
	using namespace std;
	cout << "Counting down... " << n << " (n at " << &n << ")" << endl;
	if (n > 0)
		countdown(n-1);
	cout << n << ": Kaboom!" << "         (n at " << &n << ")" << endl;
}
#endif

// 재귀함수; 함수 안에서 자신을 호출하는 함수
// if문이 false가 되면 들어간 level만큼 나오게 된다.

// Recursion with Multiple Recursive Calls
// divide-and-conquer strategy
#if 0			// Listing 7.17 ruler.cpp
#include <iostream>
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);
int main()
{
	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;
	
	for (i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < Len - 2; j++)
			ruler[j] = ' ';		//reset to blank ruler
	}
}

void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}
#endif

/* Pointers to Fuctions

double (*pf) (int);		// pf points to a function that returns double
double *pf (int);		// pf() a function that returns a pointer-to-double

double (*pf) (int);		// pf points to a fuction, one int argument, return type double

double pam (int);
double (*pf) (int);
pf = pam;
double x = pam(4);		// call pam() using the function name
double y = (*pf)(5);		// call pam() using the pointer pf
double z = pf(5);			// ALSO CALL pam() using the pointer pf

	How can pf and (*pf) be equivalent? One school of thought maintains that because pf is a pointer to a function, *pf is a function;
	hence, you should use (*pf)() as a function call. A second school maintains that because the name of a function is a pointer to that function, a pointer to that function should act like the name of a function;
	hence you should use pf() as a function call. C++ takes the compromise view that both forms are correct, or at least can be allowed
*/

#if 0		// Listing 7.18	fun_ptr.cpp
#include <iostream>
double betsy(int);
double pam(int);
void estimate(int lines, double (*pf)(int));

int main()
{
	using namespace std;
	int code;
	
	cout << "How many lines of code do you need? ";
	cin >> code;
	
	cout << "Here's Betsy's estimate:\n";
	estimate(code, betsy);
	
	cout << "Here's Pam's estimate:\n";
	estimate(code, pam);
	
	return 0;
}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
	using namespace std;
	cout << lines << " lines with take ";
	cout << (*pf)(lines) << " hour(s)\n";
}
#endif

/* Variations on the Theme of Function Pointers		365~370pg SHOULD REVIEW LATER
	const double * f1(const double ar[], int n);
	const double * f2(const double [], int n);
	const double * f3(const double *, int);
The signatures are the same.
*/
// 366pg

#if 0			// Lising 7.19	arfupt.cpp
#include <iostream>
// various notations, same signatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
	using namespace std;
	double av[3] = {1112.3, 1542.6, 2227.9};

	// pointer to a function
	const double *(*p1)(const double *, int) = f1;
	auto p2 = f2; // C++11 automatic type deduction
	// pre-C++11 can use the following code instead
	// const double *(*p2)(const double *, int) = f2;
	
	cout << "Using pointers to functions:\n";
	cout << " Address Value\n";
	cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
	cout << p2(av,3) << ": " << *p2(av,3) << endl;
	// The return values are type const double * (address of a double value)
	// To see the actual value stored at the addresses, apply the * operator to these addresses

	// pa an array of function pointers
	// auto doesn't work with list initialization
	const double *(*pa[3])(const double *, int) = {f1,f2,f3};
	// Why put the [3] there? pa is an array of three things
	// Operator precedence ranks [] higher than *, so *pa[3] says pa is an array of three pointers.
	
	// but it does work for initializing to a single value
	// pb a pointer to first element of pa
	auto pb = pa;
	// pre-C++11 can use the following code instead
	// const double *(**pb)(const double *, int) = pa;
	
	cout << "\nUsing an array of pointers to functions:\n";
	cout << " Address Value\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av,3) << ": " << *pa[i](av,3) << endl;
	cout << "\nUsing a pointer to a pointer to a function:\n";
	cout << " Address Value\n";
	for (int i = 0; i < 3; i++)
		cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;
	
	// what about a pointer to an array of function pointers
	cout << "\nUsing pointers to an array of pointers:\n";
	cout << " Address Value\n";
	
	// easy way to declare pc
	auto pc = &pa;
	// pre-C++11 can use the following code instead
	// const double *(*(*pc)[3])(const double *, int) = &pa;
	cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
	
	// hard way to declare pd
	const double *(*(*pd)[3])(const double *, int) = &pa;
	// **&pa == *pa == pa[0]
	
	// store return value in pdb
	const double * pdb = (*pd)[1](av,3);
	cout << pdb << ": " << *pdb << endl;
	// alternative notation
	cout << (*(*pd)[2])(av,3) << ": " << *(*(*pd)[2])(av,3) << endl;
	// cin.get();
	return 0;
}
// some rather dull functions
const double * f1(const double * ar, int n)
{
	return ar;
}
const double * f2(const double ar[], int n)
{
	return ar+1;
}
const double * f3(const double ar[], int n)
{
	return ar+2;
}
#endif
// Ch.7 Ended