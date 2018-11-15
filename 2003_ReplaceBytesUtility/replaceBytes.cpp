///////////////////////////////////////////////////
// Project: ReplaceIt ( RI )
// File:    replaceBytes.cpp
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#include "replaceBytes.h"
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#include <cctype>
#include <fstream>
#include <iostream>
#include <windows.h>
///////////////////////////////////////////////////

///////////////////////////////////////////////////
using std::cerr;
using std::cout;
using std::domain_error;
using std::endl;
using std::fstream;
using std::getline;
using std::ios;
using std::string;
using std::vector;
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// Constructor(s)
///////////////////////////////////////////////////
ReplaceBytes::ReplaceBytes( )
{
}
///////////////////////////////////////////////////

///////////////////////////////////////////////////
ReplaceBytes::ReplaceBytes( file_t inS, file_t inD )
:Replace( inS, inD, BYTE_MODE ),
 my_lines( new vector <line_t*> )
{
	// Execute all
	clearScreen( );
	displayIntro( );
	loadDataFile( );
	replaceKeywords( );
	outputResults( );
	completedStatus( );
}
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// Destructor(s)
///////////////////////////////////////////////////
ReplaceBytes::~ReplaceBytes( )
{
	// Release the data file
	for( uint_t i = ( 0 ); i < my_lines->size( ); ++i)
	{
		delete my_lines->at( i );

	} // end of for-loop

	// Release vector(s) acquired from heap
	delete my_lines;
}
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// Public Modifier(s)
///////////////////////////////////////////////////
void ReplaceBytes::loadDataFile( )
{
	cout << STATUS_LOAD << endl;

	// Create file object
	fstream fin;
	file_t the_sourceFile = sourceFile( );

	// Temporary string to hold the line
	line_t tempLine = ( "" );

	// Open data file
	fin.open( the_sourceFile.c_str( ), ios::in );

	// Unable to open template file
	if( !fin )
	{
		throw domain_error( ERROR_102 );

	} // end of if

	// Keep going around the loop until all data has been copied
	while( !fin.eof( ) )
	{
		getline( fin, tempLine );

		// Store all the lines in the vector
		my_lines->push_back( new line_t( tempLine ) );

		// If the end of the file has been reached, break out of the loop
		if( fin.eof( ) )
		{
			break;

		} // end of if
		
	} // end of while-loop

	// Display all the lines for *TEST only
	//displayDataLines( );
		
	// Close file once done using it
	fin.close( );

} // end of loadDataFile( )
///////////////////////////////////////////////////

///////////////////////////////////////////////////
void ReplaceBytes::replaceKeywords( )
{
	cout << STATUS_REPLACE << endl;

	string findKeyword = ( "" ), replaceKeyword = ( "" );
	string::size_type my_position = ( 0 );
	string the_templateFile = templateFile( );

	for( uint_t i = ( 0 ); i < my_lines->size( ); ++i )
	{
		fstream fin;
		
		fin.open( the_templateFile.c_str( ), ios::in );

		// Unable to open template file
		if( !fin )
		{
			throw domain_error( ERROR_103 );

		} // end of if

		// Open the template file to grab the find/replace values
		while( !fin.eof( ) )
		{
			fin >> findKeyword >> replaceKeyword;

			// Found the SPACE keyword and then replace it with an actual space " " 
			if( replaceKeyword == SPACE )
			{
				// Reset the replaceKeyword to the space character

				replaceKeyword = " ";
				
				for( uint_t x = ( 0 ); x < findKeyword.size( ); ++x )
				{
					if( ( findKeyword.size( ) - x == 1 ) )
					{
						break;

					} // end of if

					replaceKeyword += " ";

				} // end of for-loop

			} // end of if

			// Try to find the search string within the data file line(s)
			my_position = ( my_lines->at( i )->find( findKeyword, 0 ) );
		
			// If it found it, we will replace the bytes
			if( my_position != string::npos )
			{
				// Found string, replacing bytes
				my_lines->at( i )->replace( my_position, ( replaceKeyword.size( ) ), replaceKeyword ); 

			} // end of if
				
		} // end of while-loop

		// Close file once done using it
		fin.close( );

	} // end of for-loop

} // end of replaceKeywords( )
///////////////////////////////////////////////////

///////////////////////////////////////////////////
void ReplaceBytes::outputResults( )
{
	cout << STATUS_OUTPUT << endl;

	fstream fout;
	string the_destFile = destFile( );

	fout.open( the_destFile.c_str( ), ios::out );

	// Unable to write to destination file
	if( !fout )
	{
		throw domain_error( ERROR_104 );

	} // end of if

	for( uint_t i = 0; i < my_lines->size( ); ++i )
	{
		fout << *my_lines->at( i ) << endl;

	} // end of for-loop

} // end of outputResults( )
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// Public Accessor(s)
///////////////////////////////////////////////////
line_t ReplaceBytes::dataLines( uint_t elemNum ) const
{
	return( *my_lines->at( elemNum ) );

} // end of dataLines( )
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// Private Modifier(s)

///////////////////////////////////////////////////
// Private Accessor(s)
///////////////////////////////////////////////////
void ReplaceBytes::displayDataLines( ) const // TEST
{
	for( uint_t i = ( 0 ); i < my_lines->size( ); ++i )
	{
		cout << MD5 << dataLines( i ) << endl;		

	} // end of for-loop

} // end of displayDataLines( )
///////////////////////////////////////////////////