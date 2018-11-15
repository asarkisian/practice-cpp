/////////////////////////////////////////////////////
// Filename: <scanner.cpp>

///////////////////////////////////////////////
#include "scanner.h"
///////////////////////////////////////////////

///////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
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
#define SCANNER_START "/-\\/-\\/-\\( Starting scan )/-\\/-\\/-\\"
#define SCANNER_END	"/-\\/-\\/-\\( Scan completed )/-\\/-\\/-\\"
#define SLEEP_TIME 30
///////////////////////////////////////////////

///////////////////////////////////////////////
scanner::scanner( )
:my_scannedFile( "" )
{
}
///////////////////////////////////////////////

///////////////////////////////////////////////
scanner::scanner( std::string file )            
:my_scannedFile( file )                        // Assigning the name of the file to be scanned to my_scannedFile
{
	this->displayIntro( );
	this->hexdump( );              // Converts the file being scanned to HEX and stores it into a buffer
	this->InputToBuffer( );        // Inputs the file in HEX format to the buffer
	this->calculateCRC();          // Calculate CRC value of file being scanned	
	this->GenericScan();           // Generic Analysis(Integrity check using CRC from detection.txt)
	this->ClassicScan();           // Classic Scan using String signatures from detection.txt	
	this->displayEnd();
}
///////////////////////////////////////////////

///////////////////////////////////////////////
scanner::~scanner( )
{
}
///////////////////////////////////////////////


///////////////////////////////////////////////
void scanner::displayIntro()

{   system("cls");
	cout << "Simple AntiVirus Scanner created by Armond Sarkisian\n"
	     << "----------------------------------------------------\n" << endl;

	for(unsigned int i = 0; i < strlen(SCANNER_START); ++i)
	{
		cout << SCANNER_START[i];
				
		Sleep(SLEEP_TIME);
	}
	cout << endl << endl;


}
///////////////////////////////////////////////

///////////////////////////////////////////////
void scanner::hexdump( )
{
    fstream ifile(my_scannedFile.c_str(),
        ios_base::in | ios_base::binary);
    char *ibuff = new char[IBUFSIZE];    
    int i;
	
    if(!ifile.is_open())
    {
		throw domain_error( "Could not open file for reading" );
    }

	if( !ibuff )
    {
        cout << "Cannot Allocate buffers\n";
        ifile.close();
        return;
    }

    while(!ifile.eof())
    {
        memset(ibuff,0,IBUFSIZE);
        ifile.read(ibuff,IBUFSIZE);

        if(ibuff[0] == 0 && ifile.eof())
            break;

        for(i = 0; i < IBUFSIZE; i++)
			my_hexBuffer.push_back((int) ibuff[i] );
    }

    ifile.close( );
}
///////////////////////////////////////////////

///////////////////////////////////////////////
bool scanner::InputToBuffer( )
{
    string line;                            
   	fstream fout, fin;                        
	fout.open( "scan_file.txt", std::ios::out );

	if( !fout )
	{
		throw domain_error( "Error opening file" );
	}

	for( unsigned int i = 0; i < my_hexBuffer.size( ); ++i )                       // Parse the entire HEX Buffer <INT> 
	{   if (i!=0 && i%16 ==0) {fout<<endl;}                                        // Created a newline after every 16 HEX pair
		fout << setfill('0') << setw(2) << hex <<my_hexBuffer.at( i )<<" ";        // Output to file in the <HEX> format
	}

	fout.close( );

	fin.open( "scan_file.txt", std::ios::in );

	if( !fin )
	{
		throw domain_error( "Error opening file" );
	}

	while( getline( fin, line ) )
	{
		my_hexBuf.push_back( string( line ) );
	}

	fin.close( );

	return 0;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
unsigned int scanner::calculateCRC()
{
	ifstream in( my_scannedFile.c_str( ), std::ios::in | std::ios::binary ); // Open the file to be scanned my_scannedFile
                 
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

	unsigned int scan_file_CRC = static_cast<unsigned int>( nCRC ); 
     
	delete [] buffer;    
	return scan_file_CRC;       
           
}
///////////////////////////////////////////////
	
///////////////////////////////////////////////
void scanner::GenericScan()//
{
	unsigned int my_crc = calculateCRC( );

	std::string my_string_crc = "[CRC]";

	my_string_crc +=IntToString( my_crc );

	fstream fin;
	fin.open( "detection.dat", std::ios::in );

	if( !fin )
	{
		throw domain_error( "Could not find definition file" );
	}

	unsigned int i = 0;
	string file_line;
	string::size_type pos3;

	while( !fin.eof( ) )
	{
		getline( fin, file_line );

		pos3 = file_line.find("[CRC]", 0);
		if(pos3 == std::string::npos)                        
		{
		}
		else
		{
			if( my_string_crc == file_line )
			{
				cout << "Generic CRC Found for ";

				string displayThreat;
				
				getline( fin, displayThreat );

				cout << displayThreat << endl;
			}
		}
	}	

	fin.close( );
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void scanner::ClassicScan( )
{

	fstream fin;
	fin.open( "detection.dat", std::ios::in );

	if( !fin )
	{
		throw domain_error( "Could not find definition file" );
	}

	string file_line;
	string::size_type pos3, pos2;
	std::string string_section, threatName;

	while( !fin.eof( ) )
	{
		getline( fin, file_line );


		pos3 = file_line.find( "////", 0);
		if(pos3 == string::npos)                                    
		{
		}
		else
		{
			getline( fin, string_section );

			string_section.erase( string_section.begin( ), string_section.begin( ) + 8 );
			
			for( unsigned int a = 0 ; a < my_hexBuf.size( ); ++a )
			{
				pos2 = my_hexBuf.at( a ).find( string_section, 0 );

				if( pos2 == string::npos )
				{
				}
				else
				{
					getline( fin, threatName );
					getline( fin, threatName );

					cout << "String detection found for " << threatName << endl;
				}
			}
		}
	}

	fin.close( );
}
///////////////////////////////////////////////

///////////////////////////////////////////////
void scanner::displayEnd()
{   
	cout << endl << endl;

	for(unsigned int i = 0; i < strlen(SCANNER_END); ++i)
	{
		cout << SCANNER_END[i];
				
		Sleep(SLEEP_TIME);
	}
	cout<<endl<<endl;
}
///////////////////////////////////////////////