/////////////////////////////////////////////////////
// Filename: <detwriter.h>

///////////////////////////////////////////////
#ifndef ___DETWRITER_H___
#define ___DETWRITER_H___
///////////////////////////////////////////////

///////////////////////////////////////////////
#include <string>
#include <vector>
///////////////////////////////////////////////

///////////////////////////////////////////////
class detWriter
{
public:

	detWriter( );
	detWriter( std::string fileName, std::string threatName );

	~detWriter( );

	void acceptInfectedFile( );
	void createStringDisplay( );
	void createCRCDet( );

	void createDisplayFile( );
	void outputToBrowser( );

	void promptUserForString( );
	void createResultFile( );

private:

	// This string is from the entire file
	std::vector<std::string*>* my_stringDet;

	// This string is chosen by the user
	std::string my_detectionString;
	
	int my_detectionCRC;

	std::string my_infectedFileName;
	std::string my_stringOutputFile;
	std::string my_threatName;
};
///////////////////////////////////////////////

///////////////////////////////////////////////
#endif
///////////////////////////////////////////////