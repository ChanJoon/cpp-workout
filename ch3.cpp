/* Ch3. Dealing with Data

interger types: unsigned long, long, unsigned int, int, unsigned short, short, char, unsigned char, signed char, bool

unsigned long long, long long

floating-point types: float, double, long double

'Naming Convention' : intMyWeight, b: Boolean, p: pointer, c: single character.

short: 16 bits
int: 32 bits
long: 32 bits
long long: 64 bits

byte = 8-bit


*/

/* //limits.cpp
#include <iostream>
#include <climits>

int main(void)
{
	using namespace std;
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	
	cout << "int is " << sizeof(n_int) << " bytes." << endl;
	cout << "short is " << sizeof n_short << " bytes." << endl;
	cout << "long is " << sizeof(n_long) << " bytes." << endl;
	cout << "long long is " << sizeof(n_llong) << " bytes." << endl;
	cout << endl;
	
	cout << "Maximum values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl;
	
	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;
	
	return 0;
} 
 */


/* Interger Literals
base 10 / base 8 / base 16

base 10; if the first digit is in the range 1-9
base 8(octal 8진법) : if the first digit is 0 & the second digit is in the range 1-7 ex) 042
base 16(hexadecimal 16진법): if the first two character is 0x or 0X ex) 0x42 = 66 (4x16+2x1)
a-f / A-F = 10-15 ex) 0xF = 15, 0xA5 = 165(10x16 + 5x1)
*/

/* //hexoct2.cpp
#include <iostream>
using namespace std;

int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;
	
	cout << "chest =  " << chest << " (decimal for 42)" << endl;
	cout << hex;
	cout <<  "waist =  " << waist << " (hexadecimal for 42)" << endl;
	cout << oct;
	cout << "inseam =  " << inseam << " (octal for 42)" << endl;
	cout << dec;
	cout << "chest =  " << chest << " (decimal for 42)" << endl;
	
	cout.put();
	
	return 0;
}
*/

/* the suffixes
l or L : long
u or U : unsigned int
ul or Ul uL UL : unsigned long
ll or LL : long long
ull Ull uLL ULL : unsigned long long
*/

/* // bondini.cpp
#include <iostream>
int main(void)
{
	using namespace std;
	int k\u00F6rper;
	
	cout << "\aOperation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
	
	long code;
	cin >> code;
	cout << "\aYou entered " << code << "...\n";
	cout << "\aCode verifed! Proceed with Plan Z3!\n";
	
	cout << "Let them eat g\u00E2teau.\n";
	
	return 0;
} */


/*
the program store floating-point type in double(default)
1.234f  		// a float
2.34E20F 	// a float
2.34E26 		// a double
2.2L 			// a long double
*/

/* // arith.cpp
#include <iostream>
int main()
{
	using namespace std;
	//float hats, heads;
	long double hats, heads;
	
	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
	cout << "Enter a number: ";
	cin >> hats;
	cout << "Enter a another number: ";
	cin >> heads;
	
	cout << "hats = " << hats << "; heads = " << heads << endl;
	cout << hats + heads << endl;
	cout << hats - heads << endl;
	cout << hats * heads << endl;
	cout << hats / heads << endl;
	return 0;
} */

/* // divide.cpp
#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << 9 / 5 << endl;
	cout <<  9.0 / 5.0 << endl;
	cout << 9L / 5L << endl;
	cout << 9.0f / 5.0f << endl;
	
	return 0;
} */

/* // list-initialization C++11 not permit narrowing
#include <iostream>
int main()
{
	const int code = 66;
	int x = 66;
	char c1 {31325}; // narrowing, not allowed
	char c2 = {66};
	char c3 {code};
	char c4 = {x}; // not allowed
	x = 31325;
	char c5 = x;
	
	return 0;
} */

/*
Conversions in Operand
long double > double > float > integer types

both signed or unsigned : lower converted to higher
signed and unsigned : signed > unsigned unless unsigned operand is of higher rank
