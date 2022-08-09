// Ch4 Compound Types

#if 0
// string.cpp
#include <iostream>
int main(void)
{
	using namespace std;
	 char dog[8] = { 'b', 'e', 'a', 'u', 'x', ' ' , 'I', 'I'}; // not a string
	 char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'}; // a string
	 
	 cout << dog << endl;
	 cout << cat << endl;
	 
	 return 0;
}
#endif
/*
	 A string is a series of characters stored in consecutive bytes of memory.
	 C- style strings have a special feature; The last character of every string is the null character.
	 
	 a string constant with double quotes is not interchangeable with a character constant with single quotes
	 'S' is just another way of writing 83.
	 "S" is not a charcter constant, consisting of two characters ( S and \0 )
*/
 #if 0
 
 #include <iostream>
 int main()
 {
	 using namespace std;
	 
	 cout << "I'd give my right arm to be" " a great violinist. \n" ;
	 cout << "I'd give my right arm to be a great violinist. \n" ;
	 cout << "I'd give my right ar"
	 "m to be a great violinist. \n"; // separated only by spaces, tabs, and newlines
	 
	 return 0;
 }
 #endif


//Line-Oriented Input with getline()
//cin.getline(name, 20) no more than 19 characters
// instr2.cpp
#if 0

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
#endif
 
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
 
 #if 0
 // instr3. cpp
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
#endif
 //pg.139
 
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
 
  #if 0
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
 #endif
 
   #if 0
/*   
	  // C++11 Structure Initialization
	  inflatable duck {"Daphne", 0.12, 9.92};	// can omit =
   */
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
  #endif
  
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
  
  #if 0 // arrstruc.cpp
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
  #endif
  
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
 // 160pg
/*  
 To Allocate memory, Use the library function, malloc() in C
 in C++, Use the new operator.
 
 int * pn = new int;
 -> there is no name which pn points to; data object
 
 typeName * pointer_name = new typeName;
  */
  
 #if 0 // use_new.cpp
 #include <iostream>
 int main()
 {
	 using namespace std;
	 int nights = 1001;
	 int * pt = new int;		// allocate space for an int
	 *pt = 1001;					// store a value there
	 
	 cout << "nights value = ";
	 cout << nights << " : location " << &nights << endl;
	 cout << "int ";
	 cout << "value = " << *pt << " : location = " << pt << endl;
	 
	 double * pd = new double;		// allocate space for a double
	 *pd = 1000001.0;
	 
	 cout << "double ";
	 cout << "value = " << *pd << " : location = " << pd << endl;
	 cout << "location of pointer pd: " << &pd << endl;
	 
	 cout << "size of pt = " << sizeof(pt);							// size of pt = 4
	 cout << " : size of *pt = " << sizeof(*pt) << endl;		// size of *pt = 4
	 
	 cout << "size of pd = " << sizeof pd;						// size of pd = 4
	 cout << ": size of *pd = " << sizeof(*pd) << endl;		// size of *pd = 8
	 
	 return 0;
 }
 #endif
 
/*   
  the size of a pointer-to-int is the same as the size of a pointer-to-double; Both are just addresses.
  
  new uses a different block of memory than do the ordinary variable definitions that we have been using.
  values stored in a memory region called the stack, whereas the memory allowcated by new is in a region called the heap or free store.
  
  the delete operator, enables to return memory to the memory pool when finished to use it. (Only used when declared by new)
  
  Using new to Create Dynamic Arrays
  Allocating the array during compile time is called static binding.
  dynamic binding; create an array during runtime / select an array size after the program is running.
  dynamic array; the array is created while the program is running.
   */ //164pg
/*    
   //arraynew.cpp
   #include <iostream>
   int main()
   {
	   using namespace std;
	   double * p3 = new double [3];		// space for 3 doubles. a block of 3 doubles.
	   p3[0] = 0.2;
	   p3[1] = 0.5;
	   p3[2] = 0.8;
	   
	   cout << "p3[1] is " << p3[1] << ".\n";
	   
	   p3 = p3 + 1;											
	   cout << "Now p3[0] is " << p3[0] << " and ";
	   cout << "p3[1] is " << p3[1] << ".\n" ;
	   p3 = p3 - 1;
	   
	   delete [] p3;
	   
	   return 0;
   }
    */
/* 	
// Listing 4.19 addpntrs.cpp
#include <iostream>
int main()
{
	using namespace std;
	double wages[3] = {10000.0, 20000.0, 30000.0};
	short stacks[3] = {3, 2, 1};
	
	// two ways to get the address of an array
	double * pw = wages;		// name of an array = address
	// the adress of the first element of the wages array; wages = &wages[0]
	short * ps = &stacks[0];	// use address operator
	//이러면 stacks array에 들어간 index 0 의 value의 주소인건가?
	
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;		// type double, pw changes its value by 8
	cout << "add 1 to the pw pointer:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
	
	cout << "ps = " << ps << ", *ps = " << *ps << endl;				// Expected: ps = 3
	ps = ps + 1;		// type short, ps changes its value by 2
	cout << "add 1 to the ps pointer:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";		// Expected; ps = 2
	
	cout << "access two elements with array notation\n";
	cout << "stacks[0] = " << stacks[0]
	<< ", stacks[1] = " << stacks[1] << endl;					// C++ compiler treats this as *(stacks+1)
	cout << "access two elements with pointer notation\n";
	cout << "*stacks = " << *stacks
	<< ", *(stacks+1) = " << *(stacks+1) << endl;

	cout << sizeof(wages) << " = size of wages array\n";
	cout << sizeof(pw) << " = size of pw pointer\n";
	
	return 0;
}
 */
 /* 
 The Address of an Array
 ex)
 short tell[10];
 tell = &tell[0]
 &tell = address of whole array
 
 ex)
 short (*pas)[20] = &tell; // pas points to array of 20 shorts
 
 ex)
 int tacos[10] = {5,2,8,4,1,2,2,4,6,8};
 int *pt = tacos;				// let address of tacos[0] = 3000
 pt = pt + 1;						// now pt is 3004 (if int is 4 bytes)
 int *pe = &tacos[9];		// *pe = 8 / pe = 3036
 pe = pe - 1;						// pe = 3032 => *pe = 6
 int diff = pe - pt;			// diff = 7; (3032 - 3004) / 4bytes
 
 ex)
 int * pt = new int [10];	// pt points to block of 10 ints; dynamic array
 *pt = 5;								// element number 0 to 5
 pt[0] = 6;								// reset element number 0 to 6; *pt = pt[0]
 pt[9] = 44;
 int coats[10];
 *(coats + 4) = 12;				// set coats[4] = 12
  */
  
  #if 0		//Listing 4.20 ptrstr.cpp
  #include <iostream>
  #include <cstring>
  int main()
  {
	  using namespace std;
	  char animal[20] = "bear";
	  const char * bird = "wren";		// bird holds address of string
	  char * ps;										// uninitialized
	  
	  cout << animal << " and ";
	  cout << bird << "\n";
	  // cout << ps;
	  
	  cout << "Enter a kind of animal: ";
	  cin >> animal;								// ok if input < 20 chars
	  // cin >> ps; 									// ps doesn't point to allocated space
	  
	  ps = animal;									// ps to point to string
	  cout << ps << "!\n";					// Expcted: ps = animal[0] = b
	  cout << "Before using strcpy():\n";
	  cout << animal << " at " << (int *) animal << endl;
	  cout << ps << " at " << (int *) ps << endl;		// Expected: the address of ps is not same as the address of animal
	  
	  ps = new char[strlen(animal) + 1]; // get new storage
	  strcpy(ps, animal); 							// copy string
	  
	  cout << "After using strcpy():\n";
	  cout << animal << " at " << (int *) animal << endl;
	  cout << ps << " at " << (int *) ps << endl;
	  delete [] ps;
	  
	  return 0;
  }
  #endif
  
  /* RESULT */
/*   bear and wren
Enter a kind of animal: Lion
Lion!
Before using strcpy():
Lion at 0x3a96bffca0
Lion at 0x3a96bffca0
After using strcpy():
Lion at 0x3a96bffca0
Lion at 0x196d2346ae0 */
/* 
when using strcpy()
ex)
char food[20] = "carrots"; //initialization
strcpy(food, "flan");

strcpy(food, "a picnic basket abced abadfjlajfljqlj ");
// the rest of the string into the memory bytes immediately following the array, which can overwrite other memory the program is using.

Instead former, should use the function like this
strcpy(food, "a picnic basket filled with many goodies", 19);
food[19] = '\0'; // the null character
 */ // 178 pg
 
 /* 0810
 Using new to Create Dynamic Structures
 
 struct things
 {
	 int good;
	 int bad;
 }
 
 things grubnose = {3, 453};		// grubnose is a structure
 things * pt = &grubnose;			// pt points to the grubnose structure
 */
 
 #if 0		// Listing 4.21	newstrct.cpp
 #include <iostream>
 struct inflatable		// structure def
 {
	 char name[20];
	 float volume;
	 double price;
 };
 int main()
 {
	 using namespace std;
	 inflatable * ps = new inflatable;		// allot memory for structure
	 
	 cout << "Enter name of inflatable item: ";
	 cin.get(ps->name, 20);					// method 1 for member access
	 
	 cout << "Enter volume in cubic feet: ";
	 cin >> (*ps).volume;							// method 2 for member access
	 
	 cout << "Enter price: $";
	 cin >> ps->price;
	 
	 cout << "Name: " << (*ps).name << endl;
	 cout << "Volume: " << ps->volume << " cubic feet\n";
	 cout << "Price : $" << ps->price << endl;
	 
	 delete ps;												// free memory used by structure
	 return 0;
 }
 #endif
 
 #if 0		//delete.cpp
 #include <iostream>
 #include <cstring>
 using namespace std;
 char * getname (void);			// function prototype
 int main ()
 {
	 char * name;						// create pointer but no storage
	 
	 name = getname();				// assign address of string to name
	 cout << "In main()" << endl;
	 cout << name << " at " << (int *) name << "\n";
	 delete [] name;
	 
	 name = getname();				// reuse freed memory
	 cout << name << " at " << (int *) name << "\n";
	 delete [] name;
	 return 0;
 }
 
 char * getname()						// return pointer to new string (name)
 {
	 char temp[80];
	 cout << "Enter last name: ";
	 cin >> temp;
	 
	 char * pn = new char[strlen(temp) + 1];			// Including null character, needs strlen(temp) + 1 characters
	 strcpy(pn, temp);					// copy string into smaller space
	 
	 cout << "In getname()" << "\ntemp : " << temp << " at " << (int *) temp << endl;
	 cout << "pn : " << pn << " at " << (int *) pn << endl;
	 
	 return pn;								// temp lost when function ends
 }
 #endif
 
 /*
 C++ has three ways of managing memory for data
 automatic storage
 static storage
 dynamic storage
 In Ch 9, there is fourth form called thread storage
 
 Automatic Storage; the variables exists automatically when the function is invoked, expire when the function terminates
 Static Storage; storage exists throughout the execution of an entire program.
	1) define it externally		2) use the keyword static
Dynamic Storage; The new and delete oprators -> free store or heap
*/

#if 0 			// Listing 4.23 mixtypes.cpp
#include <iostream>

struct antarctica_years_end
{
	int year;
};

int main()
{
	antarctica_years_end s01, s02, s03;		// s01, s02, s03 are structures
	
	s01.year = 1998;
	antarctica_years_end * pa = &s02;			// create a pointer to s02 structure
	pa -> year = 1999;
	
	antarctica_years_end trio[3];		// array of 3 structures
	trio[0].year = 2003;						// trio[0] is a structure
	
	std::cout << trio-> year << std::endl;		// trio->year same as trio[0].year
	// (trio+1) -> year is same as trio[1].year
	// an array name is a pointer
	
	const antarctica_years_end * arp[3] = {&s01, &s02, &s03};
	std::cout << arp[1] -> year << std::endl;
	
	const antarctica_years_end ** ppa = arp;			// arp is the name of an array
	// ppa has to a pointer to a pointer to const antarctica_years_end
	auto ppb = arp;								 // C++11 automatic type deduction
	// or else use const antarctica_years_end ** ppb = arp;
	std::cout << (*ppa) -> year << std::endl;				// ppa points to the first member of arp; &s01
	// (*ppa)-> year = s01.year
	std::cout <<(*(ppb+1)) -> year << std::endl;
	
	return 0;
}
#endif

/* The vector Template Class
similar to the string class in that it is a dynamic array.
the vector class does automatically manage memory ( new / delete )
vector<typeName> vt(n_elem);
*/

/* The array Template Class (C+11)
array<typeName, n_elem> arr;
*/

#if 0 			// Listing 4.24 choices.cpp
#include <iostream>
#include <vector>			// STL C++98
#include <array>			// C++11
int main()
{
	using namespace std;
	
	// C, original C++
	double a1[4] = {1.2, 2.4, 3.6, 4.8};
	
	// C++98 STL
	vector<double> a2(4);		// create vector with 4 elements
	// no simple way to initialize in C98
	a2[0] = 1.0/3.0;
	a2[1] = 1.0/5.0;
	a2[2] = 1.0/7.0;
	a2[3] = 1.0/9.0;
	
	// C++11 -- create and initialize array object
	array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
	array<double, 4> a4;
	a4 = a3;
	
	// use array notation
	cout << "a1[2] : " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2] : " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;
	
	// misdeed
	a1[-2] = 20.2;			// same as a1.at(-2) = 20.2;
	cout << "a1[-2] : " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2] : " << a1[2] << " at " << &a1[2] << endl;
	cout << "a4[2] : " << a1[2] << " at " << &a1[2] << endl;
	
	return 0;
} // 195pg
#endif