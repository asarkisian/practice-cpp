/////////////////////////////////////////////////////
// Filename: <scanner.h>

///////////////////////////////////////////////
#ifndef ___SCANNER_H___
#define ___SCANNER_H___
///////////////////////////////////////////////

///////////////////////////////////////////////
#include "typedefs.h"
///////////////////////////////////////////////

///////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
///////////////////////////////////////////////

///////////////////////////////////////////////
class scanner
{
public:

	scanner( );  //default constructor
	scanner( std::string file ); // parameterised constructor
	~scanner( );

	void displayIntro();         // Displays Program information
	void hexdump( );             // Converts scan file to HEX 
	bool InputToBuffer( );       // Inputs the file in HEX format into my_hexBuf
	void StaticHeuristic();      // Calculate the Static Heuristic Value
	void DynamicHeuristic( );    // Calculate the Dynamic Heuristic value
	UINT calculateCRC(); // Calculate CRC value for the file being scanned for integrity check
	void GenericScan();          // Integrity check using CRC
	void ClassicScan( );         // Classic Scan using Strings
	void displayEnd();           // Scan completed
	
private:
	std::string my_scannedFile; // File being scanned	

	
	std::vector<int> my_hexBuffer; // INT buffer that stores the file

	std::vector<std::string> my_hexBuf; //String buffer that stores the file in HEX format
};
///////////////////////////////////////////////

///////////////////////////////////////////////
#endif
///////////////////////////////////////////////