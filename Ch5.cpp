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