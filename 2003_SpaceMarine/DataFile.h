//-------------------------------------------------
// DataFile.h

#ifndef DATAFILE_H
#define DATAFILE_H

#include <string>
#include <vector>

typedef std::vector<std::string>::const_iterator rowIterator_t;

class DataFile
{
public:
	DataFile(const std::string& fileName);

	rowIterator_t begin(const std::string& heading) const;
	rowIterator_t end(const std::string& heading) const;

private:
	std::vector<std::string> my_file;
};

std::string stringToken(const std::string& inS, int index);
int intToken(const std::string& inS, int index);

#endif
//-------------------------------------------------