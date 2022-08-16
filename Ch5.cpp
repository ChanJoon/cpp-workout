/*
Ch5. Loops and Relational Expressions

Introducing for Loops

for (initializaion; test-expression; update-expression)
	body
*/

#if 0			// Listing 5.3 express.cpp
#include <iostream>
int main()
{
	using namespace std;
	int x;
	 
	 cout << (x=100) << endl;
	 cout.setf(ios_base::boolalpha);			// a newer C++ feature
	 
	 cout << "The expression x < 3 has the value ";
	 cout << (x<3) << endl;
	 
	 cout << "The expression x > 3 has the value ";
	 cout << (x>3) << endl;
	 
	 return 0;
}
#endif

#if 0			// Listing 5.4 formore.cpp
#include <iostream>
const int ArSize = 16;
int main()
{
		long long factorials[ArSize];
		factorials[1] = factorials[0] = 1LL;
		
		for (int i=2; i < ArSize; i++)
				factorials[i] = i * factorials[i-1];
		for (int i = 0; i < ArSize; i++)
			std::cout << i << "! = " << factorials[i] << std::endl;
		return 0;
}
#endif

#if 0 			// Listing 5.6 forstr1.cpp
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "Enter a word : ";
	string word;
	cin >> word;
	
	// display letters in reverse order
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << "\nBye.\n";
	return 0;
}
#endif

// Syntax Tricks - Comma operator
#if 0			// Listing 5.9 forstr2.cpp
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "Enter a word: ";
	string word;
	cin >> word;
	
	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	cout << word << "\nDone\n";
	return 0;
}
#endif
// 215 pg

#if 0			// Listing 5.11 compstr1.cpp
#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	char word[5] = "?ate";
	
	for (char ch = 'a'; strcmp(word, "mate"); ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "After loop ends, word is " << word << endl;
	return 0;
}
#endif

/* Differences between for and while loops
1. an ommitted test condition in a for loop is interpreted as true.
2. the initializing statement in a for loop to declare a variable that is local to the loop
3. for loops for counting loops / while loops when don't know how many times a loop will execute.
*/

/* Building a Time-Delay Loop
long wait = 0;
while (wait < 10000)
		wait++;
Problem: have to change the counting limit when you change computer processor speed.

clock()
1. doesn't necessarily return the time in seconds
2. return type might be long on some systems, unsigned long on others,,,
 
 -> ctime header file
 CLOCKS_PER_SEC
 clock_t
*/

#if 0			// Listing 5.14 waiting.cpp
#include <iostream>
#include <ctime>
int main()
{
	using namespace std;
	cout << "Enter the delay time, in seconds : ";
	
	float secs;
	cin >> secs;
	
	clock_t delay = secs * CLOCKS_PER_SEC;	// conver to clock ticks
	cout << "starting \a\n";
	clock_t start = clock();
	
	while (clock() - start < delay)
		;
	cout << "done \a\n";
	return 0;
}
#endif

/* Type Aliases
1) the pre-processor
#define BYTE char			// preprocessor replaces BYTE with char

2) C++ keyword typedef
typedef char byte;			// makes byte an alias for char
*/

/* The Range-Based for Loop (C++11)
1)
double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
for (double x : prices)
	cout << x << std::endl;

2)
for (double &x : prices)
	x = x * 0.80;

3)
for (int x : {3, 5, 2, 8, 6})
	cout << x << " ";
cout << '\n';
*/ //233 pg

#if 0			// Listing 5.16 textin1.cpp
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	
	cout << "Enter characters; enter # to quit:\n";
	cin >> ch;
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;
	}
	cout << endl << count << " characters read\n";
	return 0;
}
#endif
/*
1) cin skips over spaces and newline characters.
2) the input to cin is buffered. until press Enter, the characters typed don't get sent.
*/
# if 0			// Listing 5.17	textin2.cpp
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	
	cout << "Enter characters; enter # to quit:\n";
	cin.get(ch);
	while(ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
	return 0;
}
#endif

#if 0		// Listing 5.18 textin3.cpp
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cin.get(ch);
	while(cin.fail() == false)		//test for EOF
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
	return 0;
}
#endif

// cin.put(char(ch)) works for int types
#if 0			// Listing 5.19 textin4.cpp
#include <iostream>
int main(void)
{
	using namespace std;
	int ch;
	int count = 0;
	
	while( (ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " characters read\n";
	return 0;
}
#endif