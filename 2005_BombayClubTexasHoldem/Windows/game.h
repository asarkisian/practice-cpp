///////////////////////////////////////
// game.h

///////////////////////////////////////
#ifndef _GAME_H_
#define _GAME_H_
///////////////////////////////////////

///////////////////////////////////////
#include "deck.h"
#include "typedefs.h"
///////////////////////////////////////

///////////////////////////////////////
class Game
{
public:
	Game( name_t pname, currency_t pmon );
	virtual ~Game( );

	// modifiers
	void playGame( );

	virtual void	reinitializeData( ) = 0;

	virtual void	dealCards( std::string phase ) = 0;
	virtual void	checkPattern( name_t who ) = 0;

	virtual void	makeWager( );
	virtual void	adjustWages( int status );

	void resetWagerAmount( );

	// accessors
	void displayTitle( ) const;

	void clearScreen( ) const;
	void pauseScreen( ) const;

	virtual void displayGrid( ) const = 0;

	virtual int checkWinnings( ) const = 0;

	name_t		playersName( ) const;
	currency_t	playersMoney( ) const;
	currency_t	wagerAmount( ) const;

protected:
	Deck theDeck;

private:
	name_t		my_playersName;
	currency_t	my_playersMoney;

	currency_t	my_wagerAmount;
};
///////////////////////////////////////

///////////////////////////////////////
#endif
///////////////////////////////////////