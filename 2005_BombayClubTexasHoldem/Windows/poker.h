///////////////////////////////////////
// poker.h

///////////////////////////////////////
#ifndef _POKER_H_
#define _POKER_H_
///////////////////////////////////////

///////////////////////////////////////
#include "game.h"
///////////////////////////////////////

///////////////////////////////////////
class Poker : public Game
{
public:
	Poker( name_t, currency_t pmon );
	virtual ~Poker( );

	// modifiers
	virtual void reinitializeData( );
	
	virtual void dealCards( std::string phase );
	
	virtual void checkPattern( name_t who );

	// accessors
	virtual void displayGrid( ) const;

	bool isRoyalFlush( name_t who ) const;
	bool isStraightFlush( name_t who ) const;
	bool isFourKind( name_t who ) const;
	bool isFullHouse( name_t who ) const;
	bool isFlush( name_t who ) const;
	bool isStraight( name_t who ) const;
	bool isThreeKind( name_t who ) const;
	bool isTwoPair( name_t who ) const;
	bool isPair( name_t who ) const;
	
	void highCard( name_t who ) const;

	virtual int checkWinnings( ) const;

	score_t playersScore( ) const;
	score_t dealersScore( ) const;
	
	depth_t playersDepth( ) const;
	depth_t dealersDepth( ) const;

	uint_t playersHighCard( ) const;
	uint_t dealersHighCard( ) const;

	std::string getHand( score_t s ) const;
	std::string getCard( uint_t hc ) const;

private:
	score_t my_playersScore;
	score_t my_dealersScore;
	
	mutable depth_t my_playersDepth;
	mutable depth_t my_dealersDepth;

	mutable uint_t my_playersHighCard;
	mutable uint_t my_dealersHighCard;

	hand_t my_playersHand;
	hand_t my_dealersHand;
	shand_t my_sharedHand;
};
///////////////////////////////////////

///////////////////////////////////////
#endif
///////////////////////////////////////