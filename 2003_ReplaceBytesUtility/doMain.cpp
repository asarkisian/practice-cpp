///////////////////////////////////////////////////
// Project: ReplaceIt ( RI )
// File:    doMain.cpp
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#include "replace.h"
#include "replaceBytes.h"
#include "replaceWords.h"
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#include <iostream>
///////////////////////////////////////////////////

///////////////////////////////////////////////////
using std::domain_error;
///////////////////////////////////////////////////

///////////////////////////////////////////////////
void doMain( int argc, char** argv )
{
	if( argc == NO_ARGUMENTS )
	{
		// No arguments provided, please try again!
		throw domain_error( ERROR_100 );

	} // end of if
	else if( argc > MAX_ARGUMENTS )
	{
		// Too many arguments, please try again!
		throw domain_error( ERROR_101 );

	} // end of else-if

	// Convert all switches/paths/parameters to lower-case
	for( int i = ( 0 ); i < argc; ++i )
	{
		for( uint_t x = ( 0 ); x < strlen( argv[i] ); ++x )
		{
			argv[i][x] = tolower( argv[i][x] );

		} // end of for-loop

	} // end of for-loop

	result_t isByteMode = ( false );
	result_t isWordMode = ( false );

	// Set the default source and destination to the same file unless specified otherwise
	argument_t source		= ( argv[1] );
	argument_t destination	= ( argv[1] );

	// Check to see if the destination is different than the source
	if( argc > DEST_ARGUMENT )
	{ 
		destination = ( argv[2] ); 

	} // end of if	

	// Check to see if the user specified byte-mode or word-mode
	for( int i = ( 0 ); i < argc; ++i )
	{
		if( strcmp( argv[i], BYTE_MODE ) == 0 )
		{
			isByteMode = ( true );

		} // end of if
		else if( strcmp( argv[i], WORD_MODE ) == 0 )
		{
			isWordMode = ( true );

		} // end of else-if

	} // end of for-loop

	// Check to make sure at least one mode was selected
	if( !isByteMode && !isWordMode )
	{
		// No mode was selected, please try again!
		throw domain_error( ERROR_105 );

	} // end of if

	if( isByteMode )
	{
		// ReplaceBytes object to find and replace searchStrings 
		Replace* replaceBytes = ( new ReplaceBytes( source, destination ) );
		delete replaceBytes;

	} // end of if
	else
	{
		// ReplaceWords object to find and replace searchStrings 
		Replace* replaceWords = ( new ReplaceWords( source, destination ) );
		delete replaceWords;

	} // end of else

	// Go back to main( )
	return;

} // end of doMain( )
///////////////////////////////////////////////////