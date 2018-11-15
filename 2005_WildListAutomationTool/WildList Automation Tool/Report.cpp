////////////////////////////////////////////
#include "stdafx.h"
////////////////////////////////////////////

////////////////////////////////////////////
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
////////////////////////////////////////////

////////////////////////////////////////////
using std::domain_error;
using std::endl;
using std::fstream;
using std::getline;
using std::ios;
using std::left;
using std::replace_if;
using std::right;
using std::setfill;
using std::setw;
using std::string;
using std::vector;

using namespace boost;
////////////////////////////////////////////

////////////////////////////////////////////
// predicate function (helper)
bool isSlash ( char letter ) 
{ 
	if( letter == '\\' )
		return( true );

	return( false );
}
////////////////////////////////////////////

////////////////////////////////////////////
Report::Report( )
:my_newFile( "" ),
 my_freqFile( "" ),
 outer( 0 ),
 inner( 0 ),
 temp( "" )
{
	my_threatName = new vector<string*>;
	my_freq = new vector<string*>;
	
	my_wildList = new vector<string*>;
	my_wildListFreq = new vector<string*>;
}
////////////////////////////////////////////
////////////////////////////////////////////
Report::~Report( )
{
	for( uint_t i = ( 0 ); i < my_threatName->size( ); ++i ) { delete my_threatName->at( i ); }
	for( uint_t i = ( 0 ); i < my_freq->size( ); ++i ){ delete my_freq->at( i ); }
	
	for( uint_t i = ( 0 ); i < my_wildList->size( ); ++i ){ delete my_wildList->at( i ); }
	for( uint_t i = ( 0 ); i < my_wildListFreq->size( ); ++i ){ delete my_wildListFreq->at( i ); }

	delete my_wildListFreq;
	delete my_wildList;
	
	delete my_threatName;
	delete my_freq;
}
////////////////////////////////////////////

////////////////////////////////////////////
bool Report::retrieveThreatFreq( )
{
	fstream fin;
	string tn = ( "" ), f( "" );

	replace_if( my_freqFile.begin( ), my_freqFile.end( ), isSlash, '/' );
	trim( my_freqFile );

	fin.open( my_freqFile.c_str( ), ios::in );
	if( !fin )
	{
		MessageBox( NULL, "Error 100: Unable to open frequency file!", "Error", MB_OK );
		return( false );
	}

	while( !fin.eof( ) )
	{
		getline( fin, tn, ',' );
		getline( fin, f );

		// only get the threats that have a freq > 3
		if( f != "1" && f != "2" && f != "3" )
		{
			my_threatName->push_back( new string( tn ) );
			my_freq->push_back( new string( f ) );
		}
	}
	fin.close( );

	return( true );
}
////////////////////////////////////////////

////////////////////////////////////////////
void Report::sortThreats( )
{
	for( outer = ( 0 ); outer < my_wildList->size( ); ++outer )
	{
		for( inner = ( outer + 1 ); inner < my_wildList->size( ); ++inner )
		{
			if( *my_wildList->at( inner ) < *my_wildList->at( outer ) )
			{
				// organizing the threat names
				temp = ( *my_wildList->at( inner ) );
				*my_wildList->at( inner ) = ( *my_wildList->at( outer ) );
				*my_wildList->at( outer ) = ( temp );

				// organizing the frequency
				temp = ( *my_wildListFreq->at( inner ) );
				*my_wildListFreq->at( inner ) = ( *my_wildListFreq->at( outer ) );
				*my_wildListFreq->at( outer ) = ( temp );
			}
		}
	}
}
////////////////////////////////////////////

////////////////////////////////////////////
bool Report::matchNewFile( )
{
	fstream fin;
	size_t p = ( 0 );
	string line = ( "" );

	replace_if( my_newFile.begin( ), my_newFile.end( ), isSlash, '/' );
	trim( my_newFile );

	fin.open( my_newFile.c_str( ), ios::in );
	if( !fin )
	{
		MessageBox( NULL, "Error 101: Unable to open new detection file!", "Error", MB_OK );
		return ( false );
	}

	while( !fin.eof() )
	{
		getline( fin, line );

		for( uint_t i = ( 0 ); i < my_threatName->size( ); ++i )
		{
			string tempThreatName = *my_threatName->at(i);
			string tempFreq = *my_freq->at( i );
			p = line.find( tempThreatName );

			if( p != string::npos )
			{
				// makes sure it doesn't get fujacks when it is actually supposed to get
				// fujacks.A... we need to make sure it finds the right variant
				if( ( line[ p + strlen( tempThreatName.c_str( ) ) ] == '<' )
				&&  ( line[ p + 1 + strlen( tempThreatName.c_str( ) ) ] == '/' ) 
				&&  ( line[ p + 2 + strlen( tempThreatName.c_str( ) ) ] == 'a' ) )
				{
					// wild sample found, moving to next threat
					my_wildList->push_back( new string( tempThreatName ) );
					my_wildListFreq->push_back( new string( tempFreq ) );
					break;
				}
			}
		}

	}

	fin.close( );

	return( true );
}
//////////////////////////////////////////// 

//////////////////////////////////////////// 
void Report::generateReport( ) const
{
	fstream fout;
	
	fout.open( WILDLIST_FILE, ios::out );
	if( !fout )
	{
		// error
	}

	fout << "Generated Using The WildList Automation Tool\n"  
		 << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;

	fout << "Freq   |Name of Threat      |\n"
		 << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

	for( uint_t i = ( 0 ); i < my_wildList->size( ); ++i )
	{
		fout << left << '[' << right << setw( 5 ) << *my_wildListFreq->at( i ) << "] " << *my_wildList->at( i ) << endl;

	} // end of for-loop
}
////////////////////////////////////////////