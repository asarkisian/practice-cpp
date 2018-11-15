//--------------------------------------------
// Blackjack.cpp

#pragma warning(disable : 4244)

#include "Blackjack.h"
#include "Deck.h"
#include "CasinoGames.h"
#include "Globals.h"
#include <iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

//////////////////////////////////////////////
// Constructors
Blackjack::Blackjack(std::istream& inIS,
		             std::ostream& inOS)
:my_blackjack(21),
 my_softSeventeen(17),
 my_hit('h'),
 my_stay('s'),
 my_input(inIS),
 my_output(inOS),
 my_blackjackVersion(1.3),
 CasinoGames(inIS, inOS)
{
}

//////////////////////////////////////////////
// Destructors
Blackjack::~Blackjack()
{
}

//////////////////////////////////////////////
// Modifiers
void Blackjack::playersTurn()
{
	move_t m(' ');
	if(playerCount() <= blackjack())
	{
		cout << playerName() << ": (H)it or (S)tay: ";
		my_input >> m;
		setMove(tolower(m));

		if(move() == my_hit)
		{
			theDeck.dealCards("Player");
			countPlayerCards();
		}
	}
	else if(playerCount() > blackjack())
	{
		setMove(my_stay);
		setPlayerWon(false);
		setDealerWon(true);
	}
}

void Blackjack::dealersTurn()
{
	if(isDealerWon() == false)
	{
		setMove(my_hit);
		if(dealerCount() > blackjack())
		{
			setMove(my_stay);
			setPlayerWon(true);
			setDealerWon(false);
		}
		else if(dealerCount() >= playerCount())
		{
			setMove(my_stay);
			setPlayerWon(false);
			setDealerWon(true);
		}
		else if(dealerCount() >= softSeventeen())
		{
			setMove(my_stay);
		}
		else
		{
			theDeck.dealCards("Dealer");
			countDealerCards();
		}
	}
}

void Blackjack::countPlayerCards()
{
	setPlayerCount(minCount());

	char value(' ');
	int numberOfAces(0), sumOfAces(0);
	
	for(counter_t i(0); i < theDeck.numPlayerDealtCards(); ++i)
	{
		value = theDeck.playerCards(i, 0);
		if(value == '2')
		{
			adjustPlayerCount(2);
		}
		else if(value == '3')
		{
			adjustPlayerCount(3);
		}
		else if(value == '4')
		{
			adjustPlayerCount(4);
		}
		else if(value == '5')
		{
			adjustPlayerCount(5);
		}
		else if(value == '6')
		{
			adjustPlayerCount(6);
		}
		else if(value == '7')
		{
			adjustPlayerCount(7);
		}
		else if(value == '8')
		{
			adjustPlayerCount(8);
		}
		else if(value == '9')
		{
			adjustPlayerCount(9);
		}
		else if(value == '1')
		{
			adjustPlayerCount(10);
		}
		else if(value == 'J')
		{
			adjustPlayerCount(10);
		}
		else if(value == 'Q')
		{
			adjustPlayerCount(10);
		}
		else if(value == 'K')
		{
			adjustPlayerCount(10);
		}
		else if(value == 'A')
		{
			++numberOfAces;
		}
		
		//////////////////////////////////////////////
		// Assertions
		if(dealerCount() != blackjack())
		{
			bool result(isDealerBlackjack());
		}	
	}

	if(numberOfAces == 1)
	{
		if(playerCount() <= 10)
		{
			adjustPlayerCount(11);
		}
		else
		{
			adjustPlayerCount(1);
		}
	}
	else
	{
		adjustPlayerCount(numberOfAces);
	}
	if(playerCount() != blackjack())
	{
		bool result(isPlayerBlackjack());
	}
}

void Blackjack::countDealerCards()
{
	setDealerCount(minCount());

	char value(' ');
	int numberOfAces(0);

	for(counter_t i(0); i < theDeck.numDealerDealtCards(); ++i)
	{
		value = theDeck.dealerCards(i, 0);
		if(value == '2')
		{
			adjustDealerCount(2);
		}
		else if(value == '3')
		{
			adjustDealerCount(3);
		}
		else if(value == '4')
		{
			adjustDealerCount(4);
		}
		else if(value == '5')
		{
			adjustDealerCount(5);
		}
		else if(value == '6')
		{
			adjustDealerCount(6);
		}
		else if(value == '7')
		{
			adjustDealerCount(7);
		}
		else if(value == '8')
		{
			adjustDealerCount(8);
		}
		else if(value == '9')
		{
			adjustDealerCount(9);
		}
		else if(value == '1')
		{
			adjustDealerCount(10);
		}
		else if(value == 'J')
		{
			adjustDealerCount(10);
		}
		else if(value == 'Q')
		{
			adjustDealerCount(10);
		}
		else if(value == 'K')
		{
			adjustDealerCount(10);
		}
		else if(value == 'A')
		{
			++numberOfAces;
		}

		if(dealerCount() != blackjack())
		{
			bool result(isDealerBlackjack());
		}
	}

	if(numberOfAces == 1)
	{
		if(playerCount() <= 10)
		{
			adjustDealerCount(11);
		}
		else
		{
			adjustDealerCount(1);
		}
	}
	else
	{
		adjustDealerCount(numberOfAces);
	}
}

void Blackjack::resetValues()
{
	setMove(my_hit);
	setPlayerCount(minCount());
	setDealerCount(minCount());
	setPlayerWon(false);
	setDealerWon(false);
}

void Blackjack::setWinner()
{
	if(isDealerWon() == true || (dealerCount() >= playerCount() && dealerCount() <= blackjack()))
	{
		increase_numTimesDealerWon();
		setDealerWon(true);
		displayWinner("Dealer", false);
	}
	else if(isPlayerWon() == true || (playerCount() > dealerCount() && playerCount() <= blackjack()))
	{
		increase_numTimesPlayerWon();
		setPlayerWon(true);
		displayWinner("Player", false);
		applyWinnings();
	}
	cout << endl;
}

void Blackjack::checkBlackjack()
{
	if(isDealerBlackjack() == true)
	{
		increase_numTimesDealerWon();
		displayWinner("Dealer", true);
	}
	else if(isPlayerBlackjack() == true)
	{
		increase_numTimesPlayerWon();
		displayWinner("Player", true);
		applyWinnings();
	}
}

//////////////////////////////////////////////
// Accessors
void Blackjack::displayScreen() const
{
	clearScreen();
	displayTitle();
	displayGameNumber();
	displayWinStatus();
	displayGrid();
	displayCount();
	if(isDemoMode() == false)
	{
		displayMoneyStatus();
	}
}

void Blackjack::displayGrid() const
{
	my_output << "Players Name: Dealer\n"
	          << "*=================================================================*\n";
	if(move() == stay())
	{
		my_output << "| " << theDeck.dealerCards(0);
	}
	else
	{
		my_output << "| " << "   ";
	}
		 my_output << " | " << theDeck.dealerCards(1) << " | " 
			  << theDeck.dealerCards(2) << " | " 
			  << theDeck.dealerCards(3) << " | " 
			  << theDeck.dealerCards(4) 
			  << " | " << theDeck.dealerCards(5) 
			  << " | " << theDeck.dealerCards(6) << " | " 
			  << theDeck.dealerCards(7) << " | " 
			  << theDeck.dealerCards(8) << " | " 
			  << theDeck.dealerCards(9) 
			  << " | " << theDeck.dealerCards(10) << " |\n"
			  << "|                                                                 |\n"
			  << "|                                                                 |\n"
			  << "| " << theDeck.playerCards(0) 
			  << " | " << theDeck.playerCards(1) 
			  << " | " << theDeck.playerCards(2) << " | " 
			  << theDeck.playerCards(3) << " | " << theDeck.playerCards(4) 
			  << " | " << theDeck.playerCards(5) << " | " 
			  << theDeck.playerCards(6) << " | " 
			  << theDeck.playerCards(7) << " | " << theDeck.playerCards(8) 
			  << " | " << theDeck.playerCards(9) 
			  << " | " << theDeck.playerCards(10) << " |\n"
			  << "*=================================================================*\n" 
		      << "Players Name: " << playerName() << '\n'
			  << endl;
}

void Blackjack::displayCount() const
{
	if(move() == stay())
	{
		my_output << "Dealer Count: " << dealerCount() << '\n'
				<< playerName() << " Count: " << playerCount() << '\n' << endl;
	}
	else
	{
		my_output << "Dealer Count: --\n"
				<< playerName() << " Count: " << playerCount() << '\n' << endl;
	}
}

void Blackjack::displayTitle() const
{
	my_output << "\n\n\t\t\tCasino Games By Armond Sarkisian\n"
		      << "\t\t\t      Blackjack Version " << blackjackVersion() << '\n'
			  << "\t\t\t================================" << endl;
}

counter_t Blackjack::blackjack() const
{
	return(my_blackjack);
}

counter_t Blackjack::softSeventeen() const
{
	return(my_softSeventeen);
}

option_t Blackjack::isPlayerBlackjack() const
{
	option_t result(playerCount() == blackjack());
	return(result);
}

option_t Blackjack::isDealerBlackjack() const
{
	option_t result(dealerCount() == blackjack());
	return(result);
}

move_t Blackjack::hit() const
{
	return(my_hit);
}

move_t Blackjack::stay() const
{
	return(my_stay);
}

version_t Blackjack::blackjackVersion() const
{
	return(my_blackjackVersion);
}
//--------------------------------------------