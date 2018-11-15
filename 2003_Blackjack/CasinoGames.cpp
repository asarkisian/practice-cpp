//--------------------------------------------
// CasinoGames.cpp

#pragma warning(disable : 4244)

#include "CasinoGames.h"
#include "Globals.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;
using std::ostream;
using std::string;
using std::transform;
using std::ws;

//////////////////////////////////////////////
// Constructors
CasinoGames::CasinoGames(istream& inIS,
						 ostream& inOS)
:my_quit('q'),
 my_move(my_move),
 my_minCount(0),
 my_playerCount(minCount()),
 my_dealerCount(minCount()),
 my_playerName(""),
 my_input(inIS),
 my_output(inOS),
 my_numTimesPlayerWon(minCount()),
 my_numTimesDealerWon(minCount()),
 my_gameNumber(minCount()),
 my_startMoney(50.0),
 my_money(startMoney()),
 my_betAmount(minCount()),
 my_minBet(5.00),
 my_maxBet(1000.00),
 my_isDemoMode(false)
{
}

//////////////////////////////////////////////
// Destructors
CasinoGames::~CasinoGames()
{
}

//////////////////////////////////////////////
// Modifiers
void CasinoGames::setMove(move_t m)
{
	my_move = (m);
}

void CasinoGames::playAgain()
{
	move_t choice(' ');
	cout << "\nDo you want to play again? (Y)es, (N)o: ";
	my_input >> choice;
	choice = tolower(choice);
	if(choice == 'n')
	{
		setMove(quit());
	}
}

void CasinoGames::setPlayerWon(option_t inC)
{
	my_playerWon = (inC);
}

void CasinoGames::setDealerWon(option_t inC)
{
	my_dealerWon = (inC);
}

void CasinoGames::setPlayerCount(counter_t inPC)
{
	my_playerCount = (inPC);
}

void CasinoGames::setDealerCount(counter_t inDC)
{
	my_dealerCount = (inDC);
}

void CasinoGames::adjustPlayerCount(counter_t amt)
{
	my_playerCount += (amt);
}

void CasinoGames::adjustDealerCount(counter_t amt)
{
	my_dealerCount += (amt);
}

void CasinoGames::getPlayerName()
{
	cout << "\nPlayer: Enter your name: ";
	cin >> ws;
	getline(cin, my_playerName);
	transform(my_playerName.begin(), my_playerName.end(), my_playerName.begin(), tolower);
	my_playerName.at(0) = toupper(my_playerName.at(0));
}

void CasinoGames::getPlayerName(const name_t& s)
{
	my_playerName = (s);
	transform(my_playerName.begin(), my_playerName.end(), my_playerName.begin(), tolower);
	my_playerName.at(0) = toupper(my_playerName.at(0));
}

void CasinoGames::increase_numTimesPlayerWon()
{
	++my_numTimesPlayerWon;
}

void CasinoGames::increase_numTimesDealerWon()
{
	++my_numTimesDealerWon;
}

void CasinoGames::increase_gameNumber()
{
	++my_gameNumber;
}

void CasinoGames::adjustMoney(money_t amt)
{
	my_money += (amt);
}

void CasinoGames::setBetAmount(money_t amt)
{
    my_betAmount = (amt);
}

void CasinoGames::placeBet()
{
	money_t ba(0.0);
	do
	{
		ba = (0.0);
			cout << "\nMINIMUM BET: $" << minBet() << ".00\n"
				 << "MAXIMUM BET: $" << maxBet() << ".00\n"  
				 << "How much would you like to bet " << playerName() << "? ";
		
		while(!(my_input >> ba))
		{
			std::cerr << "\nMINIMUM BET: $" << minBet() << ".00\n"
				 << "MAXIMUM BET: $" << maxBet() << ".00\n"  
				 << "How much would you like to bet " << playerName() << "? ";
			my_input.clear();
			my_input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	
	}while((ba < minBet() || ba > maxBet()) || ba > money());
	setBetAmount(ba);
	adjustMoney(-ba);
}

void CasinoGames::applyWinnings()
{
	adjustMoney(my_betAmount * (2));
	adjustMoney(-.25);
}

void CasinoGames::setDemoMode(option_t choice)
{
	my_isDemoMode = (choice);
}

//////////////////////////////////////////////
// Accessors
void CasinoGames::displayWinner(std::string who, option_t isBlackjack) const
{
	if(who == "Dealer" && isBlackjack == true)
	{
		my_output << "Dealer won with a Blackjack!!!" << endl;
	}
	else if(who == "Player" && isBlackjack == true)
	{
		my_output << playerName() << " won with a Blackjack!!!" << endl;
	}
	else if(who == "Dealer")
	{
		my_output << "Dealer won!!!" << endl;
	}
	else
	{
		my_output << playerName() << " won!!!" << endl;
	}
}

void CasinoGames::displayWinStatus() const
{
	my_output << "Dealer Win Amount: " << numTimesDealerWon() << '\n'
		      << playerName() << " Win Amount: " << numTimesPlayerWon() << '\n' << endl;
}

void CasinoGames::displayMoneyStatus() const
{
	my_output << playerName() << " Money: $" << money() << '\n' << endl;
}

void CasinoGames::displayGameNumber() const
{
	my_output << "\n\nGame #: " << gameNumber() << '\n' << endl;
}

counter_t CasinoGames::minCount() const
{
	return(my_minCount);
}

counter_t CasinoGames::playerCount() const
{
	return(my_playerCount);
}

counter_t CasinoGames::dealerCount() const
{
	return(my_dealerCount);
}

move_t CasinoGames::quit() const
{
	return(my_quit);
}

option_t CasinoGames::isQuit() const
{
	option_t result(move() == quit());
	return(result);
}

move_t CasinoGames::move() const
{
	return(my_move);
}

option_t CasinoGames::isPlayerWon() const
{
	option_t result(my_playerWon == true);
	return(result);
}

option_t CasinoGames::isDealerWon() const
{
	option_t result(my_dealerWon == true);
	return(result);
}

name_t CasinoGames::playerName() const
{
	return(my_playerName);
}

counter_t CasinoGames::numTimesPlayerWon() const
{
	return(my_numTimesPlayerWon);
}

counter_t CasinoGames::numTimesDealerWon() const
{
	return(my_numTimesDealerWon);
}

counter_t CasinoGames::gameNumber() const
{
	return(my_gameNumber);
}
	
money_t CasinoGames::startMoney() const
{
	return(my_startMoney);
}

money_t CasinoGames::money() const
{
	return(my_money);
}

money_t CasinoGames::betAmount() const
{
	return(my_betAmount);
}

money_t CasinoGames::minBet() const
{
	return(my_minBet);
}

money_t CasinoGames::maxBet() const
{
	return(my_maxBet);
}

option_t CasinoGames::isOutOfMoney() const
{
	return(money() < minBet());
}

void CasinoGames::outOfMoney() const
{
	clearScreen();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		 << "\tYou are out of money. Better luck next time. Come back soon!!!" 
		 << "\n\n\n" << std::flush;
}

option_t CasinoGames::isDemoMode() const
{
	return(my_isDemoMode);
}
//--------------------------------------------