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


// Listing10.3	usestock0.cpp
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