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
 
/*  
 getline() 은 사용자의 Enter 입력도 \0으로 받아들인다.
 get()은 문자만 받으므로 개행이 되지 않는다.
 cin.get(name, ArSize);
 cin.get();
 cin.get(dessert, Arsize); //이렇게 해야 첫 줄을 읽은 후 건너뛰고 다음 줄을 읽음.
 
 따라서 cin.get(name, Arsize).get(); 와 같이 사용
 물론, cin.getline(name1,ArSize).getline(name2, ArSize); 이렇게 한 줄로 여러 배열에서 읽기 가능
 get()을 사용하는 이유는, error를 확인하기 더 쉽기 때문이다.
 다 입력되지 않고 배열이 찬 것인지 혹은 엔터키를 입력한 것인지 다음 get()에 들어온 chararcter를 확인하여 구분할 수 있다.
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
	wchart_t title[] = L"Chief Astrogator"; // w_chart string -> Unicode
	참고: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ruvendix&logNo=220829609686
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
/*    
  // arrstruc.cpp
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
	  inflatable guests[2] =
	  {
		  {"Bambi", 0.5, 21.99},
		  {"Godzilla", 2000, 565.99}
	  };
	  
	  cout << guests[0].name << " and " << guests[1].name
	  << "\nhave a combined volume of "
	  << guests[0].volume + guests[1].volume;
	  
	  return 0;
  }
   */
/*    
   // Bit Fields in Structures
   struct torgle_register
   {
	   unsigned int SN : 4; // 4 bits
	   unsigned int : 4; // 4 bits unused
	   bool goodIn : 1;
	   bool goodTorgle : 1;
   }
   torgle_register tr = {14, true, false};
   
   if (tr.goodIn) // true
   */
/*    
   Unions
   union is a data format that can hold different data types
   
   Enumerations
   enum provides an alternative to const for creating symbolic constants
    */
/* 
// Pointer Example

#include <iostream>
using namespace std;

int get_line_parameter (int x1, int y1, int x2, int y2, double *slope, double *yintercept)
{
	if (x1 == x2) return -1;
	else
	{
		*slope = (double)(y2-y1) / (double) (x2-x1);
		*yintercept = y1 - (*slope) *x1;
		return 0;
	}
}
int main(void)
{
	double s, y;
	if( get_line_parameter(3, 3, 6, 6, &s, &y) == -1) cout << "Error";
	else cout << "Slope : " << s << "\ny intercept : " << y;
	
	return 0;
}
 */
 
 