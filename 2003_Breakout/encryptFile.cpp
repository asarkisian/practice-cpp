#include "encryptFile.h"

encryptFile* encryptIt;

std::string __fastcall encryptFile::encryptIt(std::string encryptObject){
  //Encrypts the file
	for(unsigned int index(0); index<(encryptObject.length()); ++index){
  		encryptObject[index] = (~encryptObject[index]);
		encryptObject[index] ^=(index);
	}

	return(encryptObject);
}

std::string __fastcall encryptFile::decryptIt(std::string encryptObject){
  //Decrypts the file
	for(unsigned int index(0); index<(encryptObject.length()); ++index){
		encryptObject[index] = (~encryptObject[index]);
		encryptObject[index] ^=(index);
	}

	return(encryptObject);
}
