/* Ch 6. Branching Statements and Logical Operators */

#if 0		// Listing 6.6 more_and.cpp
#include <iostream>
const char * qualify[4] =
{
	"10,000-meter race.\n",
	"mug tug-of-war.\n",
	"masters canoe jousting.\n",
	"pie-throwing fesival.\n"
};
int main()
{
	using namespace std;
	int age;
	cout << "Enter your age in years : ";
	cin >> age;
	int index;
	
	if (age > 17 && age < 35)
		index = 0;
	else if (age >= 35 && age < 50)
		index = 1;
	else if (age >= 50 && age < 65)
		index = 2;
	else
		index = 3;
	
	cout << "You qualify for the " << qualify[index];
	return 0;
}
#endif

// The logical AND operator has a higher precedence than the logical OR operator.

#if 0		// Listing 6.8 cctypes.cpp -- using ctype.h / isalpha
#include <iostream>
#include <cctype>
int main()
{
	using namespace std;
	cout << "Enter text for analysis, and type @"
				" to terminate input.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;
	
	cin.get(ch);
	while(ch != '@')
	{
		if(isalpha(ch))				// is it an alphabetic character?
			chars++;
		else if(isspace(ch))		// is it a whitespace character?
			whitespace++;
		else if(isdigit(ch))		// is it a digit?
			digits++;
		else if(ispunct(ch))	// is it a punctuation?
			punct++;
		else
			others++;
		cin.get(ch);
	}
	
	cout << chars << " letters, "
			<< whitespace << " whitespace, "
			<< digits << " digits, "
			<< punct << " punctuation, "
			<< others << " others.\n";
	return 0;
}
#endif

/* Table 6.4 The cctype Character Functions
 - isalnum()
 - isalpha()
 - isblank()
 - iscntrl()			// if the argument is a control character
 - isdigit()
 - isgraph()			// if the argument is any printing character other than a space.
 - islower()
 - isprint()			// if the argument is any printing character, including a space.
 - ispunct()
 - isspace()
 - isupper()
 - isxdigit()			// if the argument is a hexadecimal digit character(0-9, a-f, A-F)
 - tolower()
 - toupper()
 */
 
 /* The ?: Operators
 called the conditional operator
 expression1 ? expression2 : expression3
*/

#if 0		// Listing 6.10	switch.cpp
#include <iostream>
using namespace std;
void showmenu();
void report();
void comfort();

int main()
{
	showmenu();
	int choice;
	cin >> choice;
	while(choice != 5)
	{
		switch(choice)
		{
			case 1	:	cout << "\a\n";
							break;
			case 2	:	report();
							break;
			case 3	:	cout << "The boss was in all day.\n";
							break;
			case 4	:	comfort();
							break;
			default :	cout << "That's not a choice.\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "Bye!\n";
	return 0;
}

void showmenu()
{
	cout << "Please enter 1, 2, 3, 4, or 5:\n"
				"1) alarm\t\t2) report\n"
				"3) alibi\t\t4) comfort\n"
				"5) quit\n";
}

void report()
{
	cout << "It's been an excellent week for business.\n"
				"Sales are up 120%. Expenses are down 35%.\n";
}
void comfort()
{
	cout << "Yout employees think you are the finest CEO\n"
				"in the industry. The board of directors think\n"
				"you are the finest CEO in the industry.\n";
}
#endif


// Using Enumerators as Labels

#if 0		// Listing 6.11 enum.cpp
#include <iostream>
// create named constants for 0 - 6
enum {red, orange, yellow, green, blue, violet, indigo};

int main()
{
	using namespace std;
	cout << "Enter color code (0-6): ";
	int code;
	cin >> code;
	while(code >= red && code <=indigo)
	{
		switch(code)
		{
			case red			:	cout << "red\n"; break;
			case orange	:	cout << "orange\n"; break;
			case yellow		:	cout << "yellow\n"; break;
			case green		:	cout << "green\n"; break;
			case blue		:	cout << "blue\n"; break;
			case violet		: 	cout << "violet\n"; break;
			case indigo		:	cout << "indigo\n"; break;
		}
		cout << "Enter color code (0-6) : ";
		cin >> code;
	}
	cout << "Bye\n";
	return 0;
}
#endif

// Number-Reading Loops

#if 0			// Listing 6.13 cinfish.cpp
#include <iostream>
const int Max = 5;
int main()
{
	using namespace std;
	double fish[Max];
	cout << "Please enter the weights of your fish.\n";
	cout << "You may enter up to " << Max << " fish <q to terminate>.\n";
	cout << "fish #1: ";
	
	int i = 0;
	while ( i < Max && cin >> fish[i])
		// if a word entered, The value of double fish[i] not changed => return false
	{
		if (++i < Max)
			cout << "fish #" << i+1 << ": ";
	}
	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[j];
	if (i == 0)
		cout << "No fish\n";
	else 
		cout << total / i << " = average weight of " << i << " fish\n";
	cout << "Done.\n";
	return 0;
}
#endif

/*
if (!cin)		// input termianted by non-numeric response
{
	cin.clear();		// reset input
	cin.get();			// read q
}
cin.get();				// read EOL after last input
cin.get();				// wait for user to press <Enter>
*/

#if 0		// Listing 6.14 cingolf.cpp
#include <iostream>
const int Max= 5;
int main()
{
	using namespace std;
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << Max << " rounds.\n";
	
	int i;
	for(i=0; i < Max;i++)
	{
		cout << "round #" << i+1 << ": ";
		while (! (cin >> golf[i]) )
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
	}
	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];
	cout << total / Max << " = average score " << Max << " rounds\n";
	return 0;
}
#endif

/* Writing to a Text File
Console output:
	<iostream> header file
	The iostream header file defines an ostream class for handling output.
	The iosteram header file declares an ostream variable, or object, called cout.
	
File output:
	<fstream> header file
	The fstream header file defines an ofstream class for handling output.
	Need to associate a specific ofstream object with a specific file; one way to do so is to use the open() method.
	
1. Include the fstream header file.
2. Create an ofstream object.
3. Associate the ofstream object with a file.
4. Use the ofstream object in the same manner you would use cout.
*/

#if 0					// Listing 6.15 outfile.cpp
#include <iostream>
#include <fstream>

int main()
{
	using namespace std;
	
	char automobile[50];
	int year;
	double a_price;
	double d_price;
	
	ofstream outFile;						// create object for output
	outFile.open("carinfo.txt");		// associate with a file
	
	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;
	
	// display information on screen with cout
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;
	
	// now do exact same things using outFile instead of cout
	outFile << fixed;											// 소수점 자리 고정
	outFile.precision(2);									// 2자리까지 표현 (fixed와 쓰여 소수점 아래 2자리)
	outFile.setf(ios_base::showpoint);		// 소수점 표기	ex) 31.10 or 24.00
	
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;
	
	outFile.close();
	return 0;
}
#endif

#if 0			// Listing 6.16 sumafile.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>				// support for exit()

const int SIZE = 60;
int main()
{
	using namespace std;
	char filename[SIZE];
	ifstream inFile;			// object for handling file input
	
	cout << "Enter name of data file:	";
	cin.getline(filename, SIZE);
	inFile.open(filename);						// filename.txt -> ifstream object
	
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;
	
	inFile >> value;
	while	(inFile.good())			// while input good and not at EOF
	{
		++count;
		sum += value;
		inFile >> value;
	}
	if (inFile.eof())					// if inFile get EOF(end-of-file)
		cout << "End of file reached. \n";
	else if (inFile.fail())			
		cout << "Input terminated by data mismatch\n";
	else
		cout << "Input terminated for unknown reason.\n";
	
	if (count ==0)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	inFile.close();
	return 0;
}
#endif