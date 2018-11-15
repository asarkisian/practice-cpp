//--------------------------------------------
// CasinoGames.h

#pragma once
#pragma warning(disable : 4512)

#include "typedefs.h"
#include <iostream>

class CasinoGames
{
public:

	//////////////////////////////////////////////
	// Constructors
	CasinoGames(std::istream& inIS,
		        std::ostream& inOS);

	//////////////////////////////////////////////
	// Destructors
	virtual ~CasinoGames();

	//////////////////////////////////////////////
	// Modifiers
	virtual void playersTurn() = 0;
	virtual void dealersTurn() = 0;

	virtual void countPlayerCards() = 0;
	virtual void countDealerCards() = 0;

	void setMove(move_t m);

	virtual void resetValues() = 0;
	void playAgain();

	void setPlayerWon(option_t inC);
	void setDealerWon(option_t inC);

	virtual void setWinner() = 0;

	void setPlayerCount(counter_t inPC);
	void setDealerCount(counter_t inDC);
	void adjustPlayerCount(counter_t amt);
	void adjustDealerCount(counter_t amt);

	void getPlayerName();
	void getPlayerName(const std::string& s);

	void increase_numTimesPlayerWon();
	void increase_numTimesDealerWon();

	void increase_gameNumber();

	void adjustMoney(money_t amt);
	void setBetAmount(money_t amt);

	void placeBet();
	void applyWinnings();

	void setDemoMode(option_t choice);

	//////////////////////////////////////////////
	// Accessors
	virtual void displayScreen() const = 0;

	virtual void displayGrid() const = 0;
	void displayWinner(std::string who, option_t isBlackjack) const;
	void displayWinStatus() const;
	void displayMoneyStatus() const;
	void displayGameNumber() const;

	virtual void displayTitle() const = 0;

	counter_t minCount() const;	
	counter_t playerCount() const;
	counter_t dealerCount() const;

	move_t quit() const;
	option_t isQuit() const;
	move_t move() const;	

	option_t isPlayerWon() const;
	option_t isDealerWon() const;

	name_t playerName() const;

	counter_t numTimesPlayerWon() const;
	counter_t numTimesDealerWon() const;

	counter_t gameNumber() const;

	money_t startMoney() const;
	money_t money() const;
	money_t betAmount() const;
	money_t minBet() const;
	money_t maxBet() const;

	option_t isOutOfMoney() const;
	void outOfMoney() const;

	option_t isDemoMode() const;

private:

	//////////////////////////////////////////////
	// Private Data
	const move_t my_quit; 
	move_t my_move;

	option_t my_playerWon;
	option_t my_dealerWon;

	const counter_t my_minCount;
	counter_t my_playerCount;
	counter_t my_dealerCount;

	name_t my_playerName;

	std::istream& my_input;
	std::ostream& my_output;

	counter_t my_numTimesPlayerWon;
	counter_t my_numTimesDealerWon;

	counter_t my_gameNumber;

	const money_t my_startMoney;
	money_t my_money;
	money_t my_betAmount;
	const money_t my_minBet;
	const money_t my_maxBet;

	option_t my_isDemoMode;
};
//--------------------------------------------