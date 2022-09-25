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