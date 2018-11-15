//-------------------------------------------------
// main.cpp

#include "myAssert.h"
#include <iostream>
#include <stdexcept>
using std::cerr;
using std::endl;

// Function Declarations
void doMain();
void doTests();

int main()
{
    try
	{
        debugStatement(doTests());
		doMain();
	}
	catch(const std::exception& e)
	{
	    cerr << '\n' << e.what() << '\n';
	}
	catch(...)
	{
		cerr << "\nUnknown internal error\n";
	}
	std::cout << endl;
	return(EXIT_SUCCESS);
}
//-------------------------------------------------