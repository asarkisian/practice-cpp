//**************************************
//     
// Name: Simple Encryption (XOR)
// Description:This is a very simple enc
//     ryption using XOR. I have actually inclu
//     ded three methods. The first is a user p
//     assword which the user enters and the sa
//     me password must be entered in to decryp
//     t. You have the option to encrypt using 
//     all modes. This program was originally c
//     reated on the unix os.
// By: Armond_Sarkisian
//
//
//This code is copyrighted and has// limited warranties.Please see http://
//     www.Planet-Source-Code.com/vb/scripts/Sh
//     owCode.asp?txtCodeId=6482&lngWId=3//for details.//**************************************
//     
//--------------------------------------
//krypt.cpp
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

class krypt
{
public:

	//Constructor
	krypt();

	//Modifiers
	void inputFrom(string);
	void outputTo(string);
	void modeA();
	void modeB();
	void userMode();

	//Accessors
	void displayHelp(int) const;

	//public data
	char myDash;
	char mySwitch;

	bool isEncrypt;
	bool isDecrypt;
	bool isStepup;
	bool isUserCode;
	bool isCompliment;
	bool isInputFileAvailable;
	bool isOutputFileAvailable;

	int userCode;

	friend void checkSwitch(char);

private:
	//private data
	string inputFileName;
	string outputFileName;
	string fileBody;

	char tempChar;
}k;

krypt::krypt()
:inputFileName(" "), 
 myDash(' '), 
 mySwitch(' '), 
 isEncrypt(false),
 isDecrypt(false), 
 isCompliment(false), 
 isStepup(false), 
 isUserCode(false),
 isInputFileAvailable(false), 
 isOutputFileAvailable(false)
{}

void krypt::displayHelp(int helpCode) const
{

	switch(helpCode)
	{
	case 107:
	{
		cout << "krypt: cannot encrypt and decrypt at the same time" << endl;
		break;
	}
	case 106:
	{
		cout << "krypt: user code must be in the range 1-6" << endl;
		break;
	}
	case 105:
	{
		cout << "krypt: " << k.outputFileName << ": Unable to write to file" << endl;
		break;
	}
	case 104:
	{
		cout << "krypt: " << k.inputFileName << ": No such file or directory" << endl;
		break;
	}
	case 103:
	{
		cout << "krypt: too many non-option arguments" << endl;
		break;
	}
	case 102:
	{
		cout << "krypt: unrecognized option `" << k.mySwitch << "\'" << endl;
		break;
	}
	case 101:
	{
		cout << "krypt: too few non-option arguments" << endl;
		break;
	}
	case 100:
	{
		cout << "Try `krypt --help\' for more information." << endl;
		break;
	}
	}//end of switch
}

void krypt::modeA()
{
	int fileLength = (int)k.fileBody.size();

	for(int i = 0; i < fileLength; ++i)
	{
		k.fileBody[i] ^= i;
	}
}

void krypt::modeB()
{
	int fileLength = (int)k.fileBody.size();

	for(int i = 0; i < fileLength; ++i)
	{
		k.fileBody[i] = ~k.fileBody[i];
	}
}

void krypt::userMode()
{

	int fileLength = (int)k.fileBody.size();

	if(isEncrypt == true && isDecrypt == false)
	{
		for(int i = 0; i < fileLength; ++i)
		{
			k.fileBody[i] = k.fileBody[i] + userCode;
		}
	}
	else if(isEncrypt == false && isDecrypt == true)
	{
		for(int i = 0; i < fileLength; ++i)
		{
			k.fileBody[i] = k.fileBody[i] - userCode;
		}
	}
}

void krypt::inputFrom(string value)
{
	k.inputFileName = value;
	
	ifstream fin(value.c_str());
	if(!fin)
	{
		k.displayHelp(104);
		exit(1);
	}

	while(fin.get(k.tempChar))
	{
		k.fileBody += k.tempChar;
	}
}

void krypt::outputTo(string value)
{
	k.outputFileName = value;

	ofstream fout(value.c_str());
	if(!fout)
	{
		k.displayHelp(105);
		exit(1);
	}
	
	fout << k.fileBody;
}

void checkSwitch(char value)
{
	if(value == 's' || value == 'c' || value == 'x' || value == 'd' || value == 'e')
	{
		if(value == 's')
		{
			k.isStepup = true;
		}
		
		if(value == 'c')
		{
			k.isCompliment = true;
		}

		if(value == 'x')
		{
			k.isUserCode = true;
		}

		if(value == 'e')
		{
			k.isEncrypt = true;
		}
		else if(value == 'd')
		{
			k.isDecrypt = true;
		}

		if(k.isEncrypt == true && k.isDecrypt == true)
		{
			k.displayHelp(107);
			k.displayHelp(100);
			exit(1);
		}
	}//end of if
	else
	{
		k.displayHelp(102);
		k.displayHelp(100);
		exit(1);
	}
}

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		k.displayHelp(101);
		k.displayHelp(100);
		exit(1);
	}

	string helpOptions = argv[1];
	
	if(helpOptions == "--help")
	{
		cout << "Usage: krypt OPTION... FILE1 FILE2" << endl;
		cout << "Encrypt/Decrypt a file from source file to target file.\n\n";
		cout << " -c,modeA encryption" << endl;
		cout << " -s,modeB encryption" << endl;
		cout << " -x#,modeC encryption (user code required)" << endl;
		cout << " -e,encrypt the file" << endl;
		cout << " -d,decrypt the file\n\n";
		cout << "--help" << endl;
		cout << "--version\n\n";
		cout << "Use one -e or -d to encrypt or decrpyt. You must use at least one: -c -s -x#.\n";
		cout << "Report bugs to <armond.sarkisian@gmail.com>." << endl;
		exit(1);
	}//end of if
	else if(helpOptions == "--version")
	{
		cout << "Copyright (C) 2003 Armond Sarkisian.\n\n";
		exit(1);
	}

	int numberOfFiles = 0, sourceFileNum = 0, targetFileNum = 0;
	string tempSourceFileName = " ", tempTargetFileName = " ";
	
	for(int i = 1; i < argc; ++i)
	{
		k.myDash = argv[i][0];
		k.mySwitch = argv[i][1];
		if(k.myDash == '-')
		{
			checkSwitch(k.mySwitch);
			if(k.mySwitch == 'x')
			{
				string tempUserCode;
				int numbers = 0, x = 2;

				while(argv[i][x] >= '0' && argv[i][x] <= '9')
				{
					if(numbers < 0 || numbers > 5)
					{
							k.displayHelp(106);
							k.displayHelp(100);
							exit(1);
					}
					
					tempUserCode += argv[i][x];
					
					++x;
					++numbers;
				}
			
				if(numbers == 0)
				{
					k.displayHelp(106);
					k.displayHelp(100);
					exit(1);
				}
			
				k.userCode = atoi(tempUserCode.c_str());
			}
		}//end of if
		else if(k.myDash != '-')
		{
			++numberOfFiles;

			if(numberOfFiles > 2)
			{
				k.displayHelp(103);
				k.displayHelp(100);
				exit(1);
			}
			if(numberOfFiles == 1)
			{
				sourceFileNum = i;
				tempSourceFileName = argv[i];
				k.isInputFileAvailable = true;
			}
            else if(numberOfFiles == 2)
            {
				targetFileNum = i;
				tempTargetFileName = argv[i];
				k.isOutputFileAvailable = true;
			}
		}//end of else if
	}//end of if
                		
	if(k.isInputFileAvailable == false || k.isOutputFileAvailable == false)
	{
		k.displayHelp(101);
		k.displayHelp(100);
		exit(1);
	}

	if((k.isStepup == true || k.isCompliment == true || k.isUserCode == true)
	&& (k.isEncrypt == true || k.isDecrypt == true))
	{
		k.inputFrom(tempSourceFileName);

		if(k.isEncrypt == true && k.isDecrypt == false)
		{
			if(k.isUserCode == true)
			{
				k.userMode();
			}

			if(k.isCompliment == true)
			{
				k.modeB();
			}

			if(k.isStepup == true)
			{
				k.modeA();
			}
		}
		else if(k.isEncrypt == false && k.isDecrypt == true)
		{
			if(k.isCompliment == true)
			{
			k.modeB();
			}

			if(k.isStepup == true)
			{
				k.modeA();
			}

			if(k.isUserCode == true)
			{
				k.userMode();
			}
		}

		k.outputTo(tempTargetFileName);
	}//end of if
	else
	{
		k.displayHelp(101);
		k.displayHelp(100);
		exit(1);
	}

	return( EXIT_SUCCESS );
}
//--------------------------------------