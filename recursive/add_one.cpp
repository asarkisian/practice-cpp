#include <iostream>

using std::cout;
using std::endl;

const int NUM1_MAX = 12;

int add_one(const int num1) {

	if (num1 > NUM1_MAX)
		return(0);

	cout << "Number: " << num1 << endl;

	return(add_one(num1 + 1));
}

int main() {

	add_one(1);

	return(0);
}
