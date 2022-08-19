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