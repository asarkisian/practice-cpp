#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int main() {

	stringstream stream;

	int num1 = 5;
	int num2;
	string num2_string = "5";
		
	stream << num2_string;

	stream >> num2;

	cout << "Integers: " << num1 + num2 << endl;
	cout << "Stream: " << stream.str() << endl;

	return(0);
}
