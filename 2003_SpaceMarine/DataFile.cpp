//-------------------------------------------------
// DataFile.cpp

#pragma warning(disable : 4800)

#include "DataFile.h"
#include "myAssert.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::back_inserter;
using std::copy;
using std::find;
using std::find_if;
using std::getline;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::string;
using std::vector;
using std::ws;

//------- Helper Function -------
bool isHeading(const string& line)
{
	return (line[0] == '[');
}

DataFile::DataFile(const string& fileName)
{
	ifstream file(fileName.c_str());
	releaseAssert(file);
	string line;
	while(file >> ws && getline(file, line))
	{
		my_file.push_back(line);
	}
}

rowIterator_t DataFile::begin(const string& heading) const
{
	return(find(my_file.begin(), my_file.end(), heading) + 1);
}

rowIterator_t DataFile::end(const string& heading) const
{
	return(find_if(begin(heading), my_file.end(), isHeading));
}

string stringToken(const string& inS, int index)
{
	istringstream row(inS);
	vector<string> tokenList;
	istream_iterator<string> rowBegin(row);
	istream_iterator<string> rowEnd;
	copy(rowBegin, rowEnd, back_inserter(tokenList));
	return(tokenList.at(index));
}

int intToken(const string& inS, int index)
{
	istringstream token(stringToken(inS, index));
	int num = 0;
	token >> num;
	return(num);
}
//-------------------------------------------------