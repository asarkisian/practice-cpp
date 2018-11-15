#include <iostream>

using std::cout;
using std::endl;

const int NUM1_MAX = 12;
const int NUM2_MAX = 12;

int mult_tables(int num1, int num2) {

	if (num2 > NUM2_MAX)
	{
		num1 += 1;
		num2 = 1;
		endl(cout);
	}

	if (num1 > NUM1_MAX)
		return(0);

	cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;

	return(mult_tables(num1, num2 + 1));
}

int main() {

	mult_tables(0, 0);

	return(0);
}
