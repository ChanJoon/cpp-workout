// Ch4 Compound Types

/* // string.cpp
#include <iostream>
int main(void)
{
	using namespace std;
	 char dog[8] = { 'b', 'e', 'a', 'u', 'x', ' ' , 'I', 'I'}; // not a string
	 char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'}; // a string
	 
	 cout << dog << endl;
	 cout << cat << endl;
	 
	 return 0;
} */

/*
 A string is a series of characters stored in consecutive bytes of memory.
 C- style strings have a special feature; The last character of every string is the null character.
 
 a string constant with double quotes is not interchangeable with a character constant with single quotes
 'S' is just another way of writing 83.
 "S" is not a charcter constant, consisting of two characters ( S and \0 )
 
 */
 
/*  #include <iostream>
 int main()
 {
	 using namespace std;
	 
	 cout << "I'd give my right arm to be" " a great violinist. \n" ;
	 cout << "I'd give my right arm to be a great violinist. \n" ;
	 cout << "I'd give my right ar"
	 "m to be a great violinist. \n"; // separated only by spaces, tabs, and newlines
	 
	 return 0;
 }
  */

/* 
//Line-Oriented Input with getline()
//cin.getline(name, 20) no more than 19 characters
// instr2.cpp
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	
	cout << "Enter your name \n";
	cin.getline(name, ArSize); //read through newline
	cout << "Enter your favorite dessert \n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	
	return 0;
}
 */
 
/*  // instr3. cpp
 #include <iostream>
 int main()
 {
	 using namespace std;
	 const int ArSize = 20;
	 char name[ArSize];
	 char dessert[ArSize];
	 
	 cout << "Enter your name:\n";
	 cin.get(name, ArSize).get(); //read string, newline
	 cout << "Enter your favorite dessert:\n";
	 cin.get(dessert, ArSize).get();
	 cout << "I have some delicious " << dessert;
	 cout << " for you, " << name << ".\n";
	 cin.getline(name,ArSize).getline(dessert, ArSize);
	 cout << name << " want to eat ";
	 cout << dessert << "." << endl;
	 
	 return 0;
 }
  */
/*  
// strtype3.cpp
#include <iostream>
#include <string>
#include <cstring>
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";
	
	str1 = str2;
	strcpy(charr1, charr2);
	
	str1 += " paste";
	strcat(charr1, " juice");
	
	int len1 = str1.size();		// obtain length of str1
	int len2 = strlen(charr1);	// obtain length of charr1
	
	cout << "The string " << str1 << " contains "
			<< len1 << " characters.\n";
	cout << "The string " << charr1 << " contains "
			<< len2 << " characters.\n";
			
	return 0;
}
 */ //pg.139
 