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
 
 // Other Forms of String Literals
/* 
	wchart_t title[] = L"Chief Astrogator"; // w_chart string
	char16_t name[] = u"Felonia Ripova"; // char_16 string
	char32_5 car[] = U"Humber Super Snipe"; // char_32 string
*/ 
/* 
	// R Frefix
	cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';

	output)
	Jim "King" Tutt uses \n instead of endl. // "( and )" as delimiters
 */
/*  
	 // if want to display ) , "
	 cout << R"+*("(Who wouldn't?)", she whispered.)+*" << endl;
	 
	 output)
	 "(Who wouldn't?)", she whispered.
  */
/*   
	  // Introducing Structure
	  // a single structure can hold items of more than one daya type. ( vs array.)
	  struct inflatable	// structure delaration _ struct { name(or tag) }
	  {
		  char name[20];
		  float volume;
		  double price;	// structure members
	  };
	  
	  // Unlike C structure, when declare structure variables:
	  struct inflatable goose; 		// keyword struct required in C
	  inflatable vincent;				// keyword struct not required in C++
	  
	  // hat.volume => the 'volume' member of the structure variable 'hat'
 */
/*  
 // 4.11 structur.cpp -- a simple structure
 #include <iostream>
 struct inflatable		// structure declaration; external declaration - can be used in all functions in file
 {
	 char name[20];
	 float volume;
	 double price;
 };
 
 int main()
 {
	 using namespace std;
	 inflatable guest = {		// local declaration - can be used only in this function
		 "Glorious Gloria",	// name
		 1.88,						// volume
		 29.99						// price
	 };		// guest is a structure variable of type inflatable
	 
	 inflatable pal = {"Audacious Arthur", 3.12, 32.99};
	 
	 cout << "Expand your guest list with " << guest.name;
	 cout << " and " << pal.name << "!\n";
	 
	 cout << "You can have both for $";
	 cout << guest.price + pal.price << "!\n";
	 
	 return 0;
 }
 // also, pal.name[0] = 'A'
  */
/*   
	  // C++11 Structure Initialization
	  inflatable duck {"Daphne", 0.12, 9.92};	// can omit =
   */
/*   
  // 4.12 asign_st.cpp -- assigning structure. structures as arguments of a return value.
  #include <iostream>
  struct inflatable
  {
	  char name[20];
	  float volume;
	  double price;
  };
  int main()
  {
	  using namespace std;
	  inflatable bouquet = 
	  {
		  "sunflowers",
		  0.20,
		  12.49
	  };
	  inflatable choice;
	  cout << "bouquet: " << bouquet.name << " for $";
	  cout << bouquet.price << endl;
	  
	  choice = bouquet;
	  cout << "choice: " << choice.name << " for $";
	  cout << choice.price << endl;
	  
	  return 0;
  }
   */
/*    
	// Combine the definition of a structure form & the creation of structure variables.
	struct perks
	{
	   int key_number;
	   char car[12];
	} mr_smith, ms_jones;	// two perks variables
	// or
	struct perks
	{
	   int key_number;
	   char car[12];
	} mr_glitz = {7, "Packard"};

	// no type name
	struct		// no tag
	{
	   int x;
	   int y;
	} position;		// a structure variable -> position.x, position.y
*/
   // pg.147