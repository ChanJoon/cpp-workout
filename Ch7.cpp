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
// Lising 7.11	trave1.cpp
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
// 345pg