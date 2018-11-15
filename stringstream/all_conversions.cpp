#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int main() {

	stringstream stream;
	string sentence = "";

	stream << "Hello, World!" << endl;
	getline(stream, sentence);
	stream << endl << 1 << endl;
	stream << 1.1 << endl;
	stream << true << endl;
	stream << 'c' << endl;
	stream << "c" << endl;

	cout << "Stream: " << stream.str() << endl;
	cout << "Sentence: " << sentence << endl;

	return(0);
}
