///////////////////////////////////////
// deck.h

///////////////////////////////////////
#ifndef _DECK_H_
#define _DECK_H_
///////////////////////////////////////

///////////////////////////////////////
#include "typedefs.h"
///////////////////////////////////////

///////////////////////////////////////
class Deck
{
public:
	Deck( );
	~Deck( );

	// modifiers
	void initializeDeck( );
	
	void initializeTwo( );
	void initializeThree( );
	void initializeFour( );
	void initializeFive( );
	void initializeSix( );
	void initializeSeven( );
	void initializeEight( );
	void initializeNine( );
	void initializeTen( );
	void initializeJack( );
	void initializeQueen( );
	void initializeKing( );
	void initializeAce( );

	void initializeTempDeck( );
	
	void shuffleDeck( );

	// used in conjunction with dealCards( )
	card_t releaseCard( );

	void resetDeck( );

	// accessors
	size_t showSize( std::string whichDeck ) const;

	// ** test only **
	void displayDeck( ) const;
	void displayTempDeck( ) const;

private:

	// the entire deck
	deck_t my_deck;

	// used for shuffling
	deck_t my_tempDeck;

	// suites (hexadecimal values)
	symbol_t my_heartSymbol;
	symbol_t my_diamondSymbol;
	symbol_t my_spadeSymbol;
	symbol_t my_clubSymbol;
};
///////////////////////////////////////

///////////////////////////////////////
#endif
///////////////////////////////////////