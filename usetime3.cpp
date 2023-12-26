// usetime3.cpp
#include <iostream> // Even if <iostream> is included in header, a user don't need to know which files are included in the class code
#include "mytime3.h"

int main()
{
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	std::cout << "Aida and Tosca:\n";
	std::cout << aida << "; " << tosca << std::endl;
	
	temp = aida + tosca;
	std::cout << "Aida + Tosca: " << temp << std::endl;

	temp = aida * 1.17;
	std::cout << "Aida * 1.17: " << temp << std::endl;

	std::cout << "10.0 * Tosca: " << 10.0 * tosca << std::endl;

	return 0;
}

/*
$ ./usetime3 
Aida and Tosca:
3 hours, 35 minutes; 2 hours, 48 minutes
Aida + Tosca: 6 hours, 23 minutes
Aida * 1.17: 4 hours, 11 minutes
10.0 * Tosca: 28 hours, 0 minutes
*/