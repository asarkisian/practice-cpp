///////////////////////////////////////
// deck.cpp

///////////////////////////////////////
#include "deck.h"
///////////////////////////////////////

///////////////////////////////////////
#include <ctime>
///////////////////////////////////////

///////////////////////////////////////
using std::domain_error;
using std::string;
using std::vector;
///////////////////////////////////////

///////////////////////////////////////
Deck::Deck( )
:my_heartSymbol		( HEART ),
 my_diamondSymbol	( DIAMOND),
 my_spadeSymbol		( SPADE ),
 my_clubSymbol		( CLUB )
{
	my_deck = ( new vector<card_t*> );
	my_tempDeck = ( new vector<card_t*> );

	initializeDeck( );
}
///////////////////////////////////////

///////////////////////////////////////
Deck::~Deck( )
{
	for( uint_t i = ( 0 ); i < my_tempDeck->size( ); ++i ){ delete my_tempDeck->at( i ); }
	for( uint_t i = ( 0 ); i < my_deck->size( ); ++i ){ delete my_deck->at( i ); }

	delete my_tempDeck;
	delete my_deck;
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeDeck( )
{
	// initializing the entire deck (52 cards)
	initializeTwo( );
	initializeThree( );
	initializeFour( );
	initializeFive( );
	initializeSix( );
	initializeSeven( );
	initializeEight( );
	initializeNine( );
	initializeTen( );
	initializeJack( );
	initializeQueen( );
	initializeKing( );
	initializeAce( );

	// initializing temp deck used for shuffling
	initializeTempDeck( );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeTwo( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = TWO + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = TWO + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = TWO + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = TWO + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeThree( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = THREE + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = THREE + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = THREE + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = THREE + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeFour( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = FOUR + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = FOUR + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = FOUR + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = FOUR + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeFive( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = FIVE + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = FIVE + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = FIVE + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = FIVE + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeSix( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = SIX + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = SIX + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = SIX + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = SIX + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeSeven( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = SEVEN + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = SEVEN + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = SEVEN + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = SEVEN + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeEight( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = EIGHT + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = EIGHT + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = EIGHT + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = EIGHT + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeNine( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = NINE + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = NINE + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = NINE + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = NINE + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeTen( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = TEN + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = TEN + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = TEN + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = TEN + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeJack( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = JACK + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = JACK + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = JACK + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = JACK + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeQueen( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = QUEEN + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = QUEEN + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = QUEEN + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = QUEEN + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeKing( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = KING + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = KING + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = KING + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = KING + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeAce( ) 
{ 
	card_t tempCard = ( EMPTY_CARD );

	tempCard = ACE + my_heartSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = ACE + my_diamondSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = ACE + my_spadeSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
	tempCard = ACE + my_clubSymbol + EMPTY;
	my_deck->push_back( new card_t( tempCard ) );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::initializeTempDeck( )
{
	for( uint_t i = ( 0 ); i < my_deck->size( ); ++i )
	{
		my_tempDeck->push_back( new card_t( EMPTY_CARD ) );
	}
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::shuffleDeck( )
{
	int randomNumber = ( 0 );
	bool isCopy = ( true );

	srand( static_cast<int>( time( NULL ) ) );

	for( uint_t i = ( 0 ); i < my_deck->size( ); ++i )
	{
		do
		{
			isCopy = ( true );
			randomNumber = ( rand( ) % 52 );

			for( uint_t x = ( 0 ); x < my_tempDeck->size( ); ++x )
			{
				if( *my_tempDeck->at( x ) == *my_deck->at( randomNumber ) )
				{
					isCopy = ( false );
				}
			}
		}while( !isCopy );
		
		*my_tempDeck->at( i ) = *my_deck->at( randomNumber );

	} // end of for-loop

	// transfer all elements back to primary vector
	for( uint_t i = ( 0 ); i < my_deck->size( ); ++i )
	{
		*my_deck->at( i ) = *my_tempDeck->at( i );
	} // end of for-loop
}
///////////////////////////////////////

///////////////////////////////////////
card_t Deck::releaseCard( )
{
	card_t tempCard = ( EMPTY_CARD );

	tempCard = *my_deck->at( my_deck->size( ) - 1 );
	my_deck->erase( my_deck->end( ) - 1 );

	return( tempCard );
}
///////////////////////////////////////

///////////////////////////////////////
void Deck::resetDeck( )
{
	my_deck->resize( 0 );
	my_tempDeck->resize( 0 );

	initializeDeck( );
}
///////////////////////////////////////

///////////////////////////////////////
// ** testing only **
size_t Deck::showSize( string whichDeck ) const
{
	size_t deckSize = ( 0 );

	if( whichDeck == PRIMARY_DECK ) { deckSize = ( my_deck->size( ) ); }
	else if( whichDeck == TEMP_DECK ) { deckSize = ( my_tempDeck->size( ) ); }
	else { throw domain_error( ERROR_105 ); }

	return( static_cast<size_t> ( deckSize ) );
}
///////////////////////////////////////

///////////////////////////////////////
// ** testing only **
void Deck::displayDeck( ) const
{
	for( uint_t i  = ( 0 ); i < my_deck->size( ); ++i )
	{
		std::cout << *my_deck->at( i ) << std::endl;
	}
}
///////////////////////////////////////

///////////////////////////////////////
// ** testing only **
void Deck::displayTempDeck( ) const
{
	for( uint_t i  = ( 0 ); i < my_tempDeck->size( ); ++i )
	{
		std::cout << *my_tempDeck->at( i ) << std::endl;
	}
}
///////////////////////////////////////