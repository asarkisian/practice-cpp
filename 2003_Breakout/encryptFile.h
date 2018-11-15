#ifndef ENCRYPTFILE_H
#define ENCRYPTFILE_H

#include <string>

class encryptFile{
	public:
		std::string __fastcall encryptIt(std::string encryptObject);
		std::string __fastcall decryptIt(std::string encryptObject);
};

extern encryptFile* encryptIt;

#endif
