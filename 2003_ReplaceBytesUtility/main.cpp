///////////////////////////////////////////////////
// Project: ReplaceIt ( RI )
// File:    main.cpp
///////////////////////////////////////////////////

/************** PROGRAM INFORMATION ***************
*
* Author:      Sarkisian, Armond
* Program:     ReplaceIt ( RI )
* Purpose:     To search and replace a string with
*              a user provided string
* Date/Time:   25, May 2005 : 14:05 ( PST )
* Version:     2.0
* Revision:    0.00
*
**************************************************/

/*************** REVISION HISTORY *****************
* Full Name:   Armond Sarkisian
* Date/Time:   25, May 2005 : 14:12 ( PST )
* Comments :   Began coding ReplaceBytes ( RB ) v1.0
* Version  :   0.0   
* Revision :   0.00
***************************************************
* Full Name:   Armond Sarkisian
* Date/Time:   25, May 2005 : 17:37 ( PST )
* Comments :   Completed coding ReplaceBytes
* Version  :   1.0   
* Revision :   0.00
***************************************************
* Full Name:   Armond Sarkisian
* Date/Time:   27, May 2005 : 12:36 ( PST )
* Comments :   Fixed an issue with the vectors where
               it was deleting the last element
* Version  :   1.0   
* Revision :   0.01
***************************************************
* Full Name:   Armond Sarkisian
* Date/Time:   28, May 2005 : 11:05 ( PST )
* Comments :   Removed fin >> ws because it was
               taking and removing the white spaces
			   that is why it was causing the last
			   line to appear twice
* Version  :   1.0   
* Revision :   0.02
***************************************************
* Full Name:   Armond Sarkisian
* Date/Time:   01, June 2005 : 13:44 ( PST )
* Comments :   Noticed a problem with the way it is
               replacing words. This program only
			   has the capability of replacing bytes
			   but not actual words. If I wanted to
			   replace "Armond" with "Jim", it would
			   result in "Jimond." I will be adding
			   functionality that will allow the
			   user to choose between byte-mode and
			   word-mode. This new feature will be
			   utilized via a command-line switch.
			   Since this program will now have the
			   capability of replacing actual words
			   instead of generic bytes, I will be
			   changing the project name to 
			   "ReplaceIt."
* Version  :   2.0 
* Revision :   0.00
***************************************************/

///////////////////////////////////////////////////
#include "defines.h"
#include "globals.h"
///////////////////////////////////////////////////

///////////////////////////////////////////////////
#include <iostream>
///////////////////////////////////////////////////

///////////////////////////////////////////////////
using std::cerr;
using std::exception;
using std::flush;
///////////////////////////////////////////////////

///////////////////////////////////////////////////
void doMain( int, char** );
///////////////////////////////////////////////////

///////////////////////////////////////////////////
int main( int argc, char** argv )
{
	try
	{
		doMain( argc, argv );

	} // end of try
	catch( const exception& e )
	{
		// Will display the help screen
		programUsage( );

		cerr << '\n' << EXCEPTION << e.what( ) << '\n';

	} // end of catch
	catch( ... )
	{
		cerr << '\n' << "Unknown internal error!" << '\n';

	} // end of catch

	// Flush the error output
	flush( cerr );

	// Return back to the OS successfully
	return( EXIT_SUCCESS );

} // end of main( )
///////////////////////////////////////////////////