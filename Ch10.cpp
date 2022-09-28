// Ch 10. Objects and Classes

#if 0		// Listing 10.1	stock00.h
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock	// class declaration
{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot() { total_val = shares * share_val; }
	public:
		void acquire(const std::string & co, long n , double pr);
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};		// note semicolon at the end

#endif
#endif

/*
	the class name; the name of this user-defined type
	keyword private; can be accessed only through the public member functions (data hiding)
	keyword public; constitue the public interface for the class
*/

#if 0		// Listing10.2	stock00.cpp
// version 00
#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. " << "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. " << "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! " << "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	std::cout << "Company: " << company << " Shares: " << shares << '\n' << " Share Price: $" << share_val << " Total Worth: $" << total_val << '\n';
}
#endif


#if 0		// Listing10.3	usestock0.cpp
// compile with stock00.cpp
#include <iostream>
#include "stock00.h"

int main()
{
	Stock fluf_cat;
	fluf_cat.acquire("NanoSmart", 20, 12.50);
	fluf_cat.show();

	fluf_cat.buy(15, 18.125);
	fluf_cat.show();

	fluf_cat.sell(400, 20.00);
	fluf_cat.show();

	fluf_cat.buy(300000, 40.125);
	fluf_cat.show();

	fluf_cat.sell(300000, 0.125);
	fluf_cat.show();

	return 0;
}
#endif

// Listing 10.4
// stock10.h
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock
{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot() { total_val = shares * share_val; }
	public:
		Stock();			// default constructor
		Stock(const std::string & co, long n = 0, double pr = 0.0);
		~Stock();			// noisy destructor
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};

#endif

#if 0			// Listing10.5	stock10.cpp
#include <iostream>
#include "stock10.h"

// constructors
Stock::Stock()
{
	std::cout << "Default constructor called\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	company = co;

	if (n < 0)
	{
		std::cout << "Number of shares can't be nagative; " << company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

// class destructor
Stock::~Stock()
{
	std::cout << "Bye, " << company << "!\n";
}

// other methods
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be nagative. " << "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can’t be negative. "
		<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can’t sell more than you have! "
		<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::ios_base;
	// set format to #.###
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Company: " << company << " Shares: " << shares << '\n';
	cout << " Share Price: $" << share_val;
	// set format to #.##
	cout.precision(2);
	cout << " Total Worth: $" << total_val << '\n';

	// restore original format
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
#endif

#if 0			// Listing10.6		usestock1.cpp
#include <iostream>
#include "stock10.h"

int main()
{
	{
		using std::cout;
		cout << "Using constructors to create new objects\n";
		Stock stock1("NanoSmart", 12, 20.0); // syntax 1
		stock1.show();
		Stock stock2 = Stock ("Boffo Objects", 2, 2.0); // syntax 2
		stock2.show();

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;
		cout << "Listing stock1 and stock2:\n";
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object\n";
		stock1 = Stock("Nifty Foods", 10, 50.0); // temp object
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done\n";
	}
	return 0;
}
#endif