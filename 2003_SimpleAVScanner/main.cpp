/////////////////////////////////////////////////////
// Filename: <main.cpp>

/**************************************************************
******************* PROGRAM INFORMATION ***********************  
---------------------------------------------------------------
* Author   :		Sarkisian, Armond
* Time     :        14:04 (PST)
* Date     :        31, July 2006
* Software :        AntiVirus Detection Writer/Scanner
* Version  :		1.0
* Revision :        0.01
**************************************************************/
/**************************************************************
********************** REVISION HISTORY ***********************  
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Initial Draft
Version:      1.0
Revision:     0.00
Date / Time:  07/31/2006 : 14:05 (PST)
---------------------------------------------------------------
Full Name:    Sarkisian, Armond
Description:  Combined both projects into one
Version:      1.0
Revision:     0.01
Date / Time:  08/02/2006 : 12:40 (PST)
---------------------------------------------------------------
Full Name:    
Description:  
Version:      
Revision:     
Date / Time:  
---------------------------------------------------------------
Full Name:    
Description:  
Version:      
Revision:     
Date / Time:  
---------------------------------------------------------------
Full Name:    
Description:  
Version:      
Revision:     
Date / Time:  
---------------------------------------------------------------*/

#include "detwriter.h"
#include "scanner.h"
///////////////////////////////////////////////

///////////////////////////////////////////////
#include <iostream>
///////////////////////////////////////////////

///////////////////////////////////////////////
using std::cerr;
using std::domain_error;
using std::endl;
///////////////////////////////////////////////

///////////////////////////////////////////////
void doMain( int argc, char** argv )
{
	if( argc < 2 )
	{
		throw domain_error( "Not enough arguments" );
	}
	else if( argc > 3 )
	{
		throw domain_error( "Too many arguments" );
	}

	if( argc == 3 ) 
	{
		detWriter* dw = new detWriter( argv[1], argv[2] );
		delete dw;
	}
	else if( argc == 2 )
	{
		scanner* s = new scanner( argv[1] );
		delete s;
	}
	else
		return;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
int main( int argc, char** argv )
{
	try
	{
		doMain( argc, argv );
	}
	catch( std::exception& e )
	{
		cerr << "Exception: " << e.what( );
	}
	catch( ... )
	{
		cerr << "Unknown Internal Error";
	}

	endl( cerr );

	return( EXIT_SUCCESS );
}
///////////////////////////////////////////////