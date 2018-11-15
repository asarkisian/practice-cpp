/////////////////////////////////////////////////////
// Filename: <detwriter.cpp>

///////////////////////////////////////////////
#include "detwriter.h"
///////////////////////////////////////////////

///////////////////////////////////////////////
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory.h>
#include <stdexcept>
#include <string>
#include <string.h>
#include <windows.h>
///////////////////////////////////////////////


///////////////////////////////////////////////
using namespace std;
///////////////////////////////////////////////

///////////////////////////////////////////////
extern string IntToString(UINT num);
extern int Get_CRC(unsigned char* buffer, ULONG bufsize);
extern void InitCrcTable(void);
extern ULONG FileSize(ifstream &);
///////////////////////////////////////////////

///////////////////////////////////////////////
#define IBUFSIZE 16
///////////////////////////////////////////////

///////////////////////////////////////////////
void hexdump(const string& filename)
{
    fstream ifile(filename.c_str(),
        ios_base::in | ios_base::binary);
    char *ibuff = new char[IBUFSIZE];
    char *obuff = new char[(IBUFSIZE*2)+1];
    int i;
	
	fstream fout;
	fout.open( "stringOutput.htm", std::ios::out );
	if( !fout )
	{
		throw domain_error( "Could not create result file!" );
	}

    if(!ifile.is_open())
    {
        cout << "Cannot Open " << filename.c_str()
             << " for reading\n";
        return;
    }
    if(!ibuff || !obuff)
    {
        cout << "Cannot Allocate buffers\n";
        ifile.close();
        return;
    }

    while(!ifile.eof())
    {
        memset(obuff,0,(IBUFSIZE*2)+1);
        memset(ibuff,0,IBUFSIZE);
        ifile.read(ibuff,IBUFSIZE);

        if(ibuff[0] == 0 && ifile.eof())
            break;

        for(i = 0; i < IBUFSIZE; i++)
        {
            if(ibuff[i] >= ' ')
                obuff[i] = ibuff[i];
            else
                obuff[i] = '.';

			fout << "<font face=courier color=blue>";

			// <-------------------------HTML formatting for output to the browser------------------->

			fout << setfill('0') << setw(2) << hex << (int)ibuff[i] << "</font>&nbsp";
        }
        fout << "&nbsp;&nbsp;&nbsp;<font face=courier color=red>" << obuff << "</font><br>";
    }
	        // <-------------------------End of HTML formatting ------------------------------------->

	fout.close( );
    ifile.close( );
}
///////////////////////////////////////////////

///////////////////////////////////////////////
detWriter::detWriter( )
:my_detectionString( "" ),
 my_detectionCRC( 0 ),
 my_infectedFileName( "" ),
 my_stringOutputFile( "stringOutput.htm" ),
 my_threatName( "" )
{
	my_stringDet = new vector<string*>;   // Detection string stored in [STRING] 
}
///////////////////////////////////////////////

///////////////////////////////////////////////
detWriter::detWriter( std::string infectedFileName, std::string threatName )
:my_detectionString( "" ),
 my_detectionCRC( 0 ),
 my_infectedFileName( infectedFileName ), // Assigns the value of infectedFileName to my_infectedFileName
 my_stringOutputFile( "stringOutput.htm" ),
 my_threatName( threatName )              // Assigns the value of threatName to my_threatName
{
	my_stringDet = new vector<string*>;   // Detection string stored in [STRING] 

	this->acceptInfectedFile( );          // Accepts the infected file to be analyzed   
	this->createStringDisplay( );         // Creates the HTML file to be displayed 
	this->createCRCDet( );                // Creates [CRC]
	this->outputToBrowser( );             // Outputs HTML file to the IE browser
	this->promptUserForString( );         // User selects the the detecton string [STRING]   
	this->createResultFile( );            // Creates detection.dat
}
///////////////////////////////////////////////

///////////////////////////////////////////////
detWriter::~detWriter( )
{
	for( unsigned int i = ( 0 ); i < my_stringDet->size( ); ++i ) delete my_stringDet->at( i );
	delete my_stringDet;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void detWriter::acceptInfectedFile( )
{
	fstream fin;  //file handle declared
	fin.open( my_infectedFileName.c_str( ), std::ios::in );

	if( !fin )
	{
		throw domain_error( "Infected File Could Not Be Opened" );
	}

	fin.close( );
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void detWriter::createStringDisplay( )
{
	hexdump( my_infectedFileName.c_str( ) ); // Converts the file being analyzed to HEX
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void detWriter::createCRCDet( )
{
	ifstream in( my_infectedFileName.c_str( ), std::ios::in | std::ios::binary );

	if( !in )
	{
		throw domain_error( "Error opening file" );
	}

	ULONG BufSize = FileSize(in);
	int nCRC;
	unsigned char *buffer = new unsigned char[BufSize];

	in.seekg(ios::beg);
	in.read((char*)buffer, BufSize);

	InitCrcTable();

	nCRC = Get_CRC(buffer, BufSize);

	my_detectionCRC = nCRC;

	delete [] buffer;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void detWriter::createDisplayFile( )
{
	fstream fout;
	fout.open( my_stringOutputFile.c_str( ), std::ios::out );
	if( !fout )
	{
		throw domain_error( "Error Writing To Display HTML File" );
	}

	for( unsigned int i = ( 0 ); i < my_stringDet->size( ); ++i )
	{
		for( unsigned int x = ( 0 ); x < my_stringDet->at( i )->size( ); ++x )
		{
			fout << my_stringDet->at( i )->at( x );
		}

		fout << "<br>";
	}
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void detWriter::outputToBrowser( )
{
	// Now you have the windows folder in szFolderName
	//char szFolderName[MAX_PATH];
	//GetWindowsDirectory(szFolderName, MAX_PATH);

	// Create the editor path
	string my_log = ("");
	//my_log += szFolderName[0];
	//my_log += szFolderName[1];
	my_log += _strlwr("\\program files\\internet explorer\\iexplore.exe");
	my_log += ' ';

	char full_logPath[100];

	// Convert relative log path to absolute for ie to open
	_fullpath(full_logPath, my_stringOutputFile.c_str( ), _MAX_PATH );

	// Append absolute path
	my_log += full_logPath;

	// Executes the EDITOR and displays the log file for the current run
	WinExec(my_log.c_str(), SW_SHOWMAXIMIZED); // Display in a maximized screen
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void detWriter::promptUserForString( )  
{
	std::cout << "Please copy\\paste the string here: ";
	getline( std::cin, my_detectionString );
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void detWriter::createResultFile( ) 								
{
	fstream fout;
	fout.open( "detection.dat", std::ios::out | std::ios::app );
	if( !fout )
	{
		throw domain_error( "Error Writing To Result Detection File" );
	}

	fout << "////////////////////////////////////////////////////" << endl;
	fout << "[STRING]" << my_detectionString << std::endl;                         
	fout << "[CRC]" << static_cast<UINT>( my_detectionCRC ) << std::endl;
	fout << "[THREAT]" << my_threatName << std::endl;                       
}
///////////////////////////////////////////////