//--------------------------------------------
// Blackjack.h

#pragma once
#pragma warning(disable : 4512)

#include "CasinoGames.h"

class Blackjack : public CasinoGames
{
public:

	//////////////////////////////////////////////
	// Constructors
	Blackjack(std::istream& inIS,
		      std::ostream& inOS);

	//////////////////////////////////////////////
	// Destructors
	virtual ~Blackjack();  // Check

	//////////////////////////////////////////////
	// Modifiers
	virtual void playersTurn();
	virtual void dealersTurn();

	virtual void countPlayerCards();
	virtual void countDealerCards();

	virtual void resetValues();

	virtual void setWinner();

	void checkBlackjack();

	//////////////////////////////////////////////
	// Accessors
	virtual void displayScreen() const;
	virtual void displayGrid() const;
	void displayCount() const;

	virtual void displayTitle() const;

	counter_t blackjack() const;
	counter_t softSeventeen() const;

	option_t isPlayerBlackjack() const;
	option_t isDealerBlackjack() const;

	move_t hit() const;
	move_t stay() const;

	version_t blackjackVersion() const;

private:

	//////////////////////////////////////////////
	// Private Data
	const counter_t my_blackjack;
	const counter_t my_softSeventeen;

	const move_t my_hit;
	const move_t my_stay;

	std::istream& my_input;
	std::ostream& my_output;

	const version_t my_blackjackVersion;
};
//--------------------------------------------