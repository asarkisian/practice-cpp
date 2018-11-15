///////////////////////////////////////
// poker.cpp

///////////////////////////////////////
#include "poker.h"
///////////////////////////////////////

///////////////////////////////////////
using std::cout;
using std::domain_error;
using std::endl;
using std::string;
using std::vector;
///////////////////////////////////////

///////////////////////////////////////
Poker::Poker( name_t pname, currency_t pmon )
:Game( pname, pmon ),
 my_playersScore( 0 ),
 my_dealersScore( 0 ),
 my_playersDepth( 0 ),
 my_dealersDepth( 0 ),
 my_playersHighCard( 0 ),
 my_dealersHighCard( 0 ),
 my_sharedHand( SHARED_HAND, EMPTY_CARD )
{
	my_playersHand = ( new vector<card_t*> );
	my_dealersHand = ( new vector<card_t*> );
}
///////////////////////////////////////

///////////////////////////////////////
Poker::~Poker( )
{
	delete my_playersHand;
	delete my_dealersHand;
}
///////////////////////////////////////

///////////////////////////////////////
void Poker::reinitializeData( )
{
	// Scoring / Depths / High Card
	my_playersScore = my_dealersScore = my_playersDepth =
	my_dealersDepth = my_playersHighCard = my_dealersHighCard = ( 0 );

	resetWagerAmount( );

	// Deck / Temp Deck
	theDeck.resetDeck( );
	my_playersHand->resize( 0 );
	my_dealersHand->resize( 0 );
	
	// Resetting values for the communal hand
	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i ) 
	{ 
		my_sharedHand.at( i ) = ( EMPTY_CARD ); 
	} // end of for-loop
}
///////////////////////////////////////

///////////////////////////////////////
void Poker::dealCards( string phase )
{
	if( phase == DEAL )
	{ // release two cards for each player
		my_playersHand->push_back( new card_t( theDeck.releaseCard( ) ) );
		my_playersHand->push_back( new card_t( theDeck.releaseCard( ) ) );

		my_dealersHand->push_back( new card_t( theDeck.releaseCard( ) ) );
		my_dealersHand->push_back( new card_t( theDeck.releaseCard( ) ) );
	}
	else if( phase == FLOP )
	{ // release three cards to be shared
		for( uint_t i = ( 0 ); i < 3; ++i )
			my_sharedHand.at( i ) = theDeck.releaseCard( );
	}
	else if( phase == TURN )
	{ // release one card to be shared
		my_sharedHand.at( 3 ) = theDeck.releaseCard( );
	}
	else if( phase == RIVER )
	{ // release one card to be shared
		my_sharedHand.at( 4 ) = theDeck.releaseCard( );
	}
	else
	{
		throw domain_error( ERROR_100 );
	}

	this->displayGrid( );
	this->makeWager( );
}
///////////////////////////////////////

///////////////////////////////////////
void Poker::displayGrid( ) const
{
	clearScreen( );

	static int rounds = ( 0 );
	card_t firstCard = ( MYSTERY_CARD ), secondCard = ( MYSTERY_CARD );

	if( rounds > SHOWDOWN_ROUND )
	{
		firstCard = *my_dealersHand->at( 0 );
		secondCard = *my_dealersHand->at( 1 );

		rounds = ( -1 );
	}

	cout << "\n\n*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\n"
		 << "* * * * * * * * * * * * * * * * * * * * *\n"
		 << "*  " << firstCard << "  |  " << secondCard << "  |                       *\n"
		 << "* = = = = = = = *                       *\n"
		 << "*                                       *\n"
		 << "*          -=( D E A L E R )=-          *\n"
		 << "*                                       *\n"
		 << "*                                       *\n"
		 << "*  / ~ ~ ~ \\    / ~ ~ ~ \\    / ~ ~ ~ \\  *\n"
		 << "*  | " << my_sharedHand.at( 0 ) << "   |    |  " << my_sharedHand.at( 1 ) << "  |    |  " << my_sharedHand.at( 2 ) << "  |  *\n"
		 << "*  \\ ~ ~ ~ /    \\ ~ ~ ~ /    \\ ~ ~ ~ /  *\n"
		 << "*                                       *\n"
		 << "*  / ~ ~ ~ \\    / ~ ~ ~ \\               *\n"
		 << "*  | " << my_sharedHand.at( 3 ) << "   |    | " << my_sharedHand.at( 4 ) << "   |               *\n"
		 << "*  \\ ~ ~ ~ /    \\ ~ ~ ~ /               *\n"
		 << "*                                       *\n"
		 << "*                                       *\n"
		 << "*          -=( P L A Y E R )=-          *\n"
		 << "*                                       *\n"
		 << "*                                       *\n"
		 << "*                       * = = = = = = = *\n"
		 << "*                       |  " << *my_playersHand->at( 0 ) << "  |  " << *my_playersHand->at( 1 ) << "  *\n"
		 << "* * * * * * * * * * * * * * * * * * * * *\n"
		 << "*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*" << endl;

	cout << '\n' << playersName( ) << PLAYER_HAS << playersMoney( )
		 << CURRENT_POT << wagerAmount( ) << endl;

	++rounds;
}
///////////////////////////////////////

///////////////////////////////////////
int Poker::checkWinnings( ) const
{
	int status = ( 999 );
	//1 win
	//0 lose
	//-1 push

	displayGrid( );
	endl( cout );

	if( playersScore( ) > dealersScore( ) )
	{
		cout << playersName( ) << PLAYER_WINS << getHand( playersScore( ) ) << '!' << endl;
		status = ( 1 );
	}
	else if( playersScore( ) < dealersScore( ) )
	{
		cout << DEALER_WINS << getHand( dealersScore( ) ) << '!' << endl;
		status = ( 0 );
	}
	else if( playersDepth( ) > dealersDepth( ) )
	{
		cout << playersName( ) << PLAYER_HIGHER << getHand( playersScore( ) ) << '!' << endl;
		status = ( 1 );
	}
	else if( playersDepth( ) < dealersDepth( ) )
	{
		cout << DEALER_HIGHER << getHand( dealersScore( ) ) << '!' << endl;
		status = ( 0 );
	}
	else if( playersHighCard( ) > dealersHighCard( ) )
	{
		cout << playersName( ) << PLAYER_WINS << getHand( playersScore( ) ) << ", " << getCard( playersHighCard( ) ) << KICKER << endl;
		status = ( 1 );
	}
	else if( playersHighCard( ) < dealersHighCard( ) )
	{
		cout << DEALER_WINS << getHand( dealersScore( ) ) << ", " << getCard( dealersHighCard( ) ) << KICKER << endl;
		status = ( 0 );
	}
	else
	{
		cout << PUSH << endl;
		status = ( -1 );
	}

	endl( cout );

	if( status == 999 )
	{
		throw domain_error( ERROR_103 );
	}

	return( status );
}
///////////////////////////////////////

///////////////////////////////////////
score_t Poker::playersScore( ) const
{
	return( my_playersScore );
}
///////////////////////////////////////

///////////////////////////////////////
score_t Poker::dealersScore( ) const
{
	return( my_dealersScore );
}
///////////////////////////////////////

///////////////////////////////////////
depth_t Poker::playersDepth( ) const
{
	return( my_playersDepth );
}
///////////////////////////////////////

///////////////////////////////////////
depth_t Poker::dealersDepth( ) const
{ 
	return( my_dealersDepth );
}
///////////////////////////////////////

///////////////////////////////////////
uint_t Poker::playersHighCard( ) const
{
	return( my_playersHighCard );
}
///////////////////////////////////////

///////////////////////////////////////
uint_t Poker::dealersHighCard( ) const
{
	return( my_dealersHighCard );
}
///////////////////////////////////////

///////////////////////////////////////
string Poker::getCard( uint_t hc ) const
{
	if( hc == 14 ) { return( "Ace" ); }
	else if( hc == 13 ) { return( "King" ); }
	else if( hc == 12 ) { return( "Queen" ); }
	else if( hc == 11 ) { return( "Jack" ); }
	else if( hc == 10 ) { return( "10" ); }
	else if( hc == 9 ) { return( "9" ); }
	else if( hc == 8 ) { return( "8" ); }
	else if( hc == 7 ) { return( "7" ); }
	else if( hc == 6 ) { return( "6" ); }
	else if( hc == 5 ) { return( "5" ); }
	else if( hc == 4 ) { return( "4" ); }
	else if( hc == 3 ) { return( "3" ); }
	else if( hc == 2 ) { return( "2" ); }
	else { throw domain_error( ERROR_104 ); }
}
///////////////////////////////////////

///////////////////////////////////////
std::string Poker::getHand( score_t s ) const
{
	std::string hand = ( "" );

	if( s == 10 ) { hand = "Royal Flush"; }
	else if( s == 9 ) { hand = "Straight Flush"; }
	else if( s == 8 ) { hand = "4 of a Kind"; }
	else if( s == 7 ) { hand = "Full House"; }
	else if( s == 6 ) { hand = "Flush"; }
	else if( s == 5 ) { hand = "Straight"; }
	else if( s == 4 ) { hand = "3 of a Kind"; }
	else if( s == 3 ) { hand = "2 Pair"; }
	else if( s == 2 ) { hand = "Pair"; }
	else if( s == 1 ) { hand = "Nothing"; }
	else { throw domain_error( ERROR_103 ); }

	return( hand );
}
///////////////////////////////////////