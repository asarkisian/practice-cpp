//--------------------------------------------
// Deck.cpp

#pragma warning(disable : 4244)

#include "Deck.h"
#include "Globals.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
using std::domain_error;
using std::for_each;
using std::string;

//////////////////////////////////////////////
// Global Object Declarations
Deck theDeck;
	
//////////////////////////////////////////////
// Predicate Function to be used with for_each
void resetCards(card_t& c)
{
	c = "   ";
}

//////////////////////////////////////////////
// Constructors
Deck::Deck()
:my_maxCards(52),
 my_maxBlackjackDealtCards(11),
 my_cards(maxCards()),
 my_playerCards(maxDealtCards()),
 my_dealerCards(maxDealtCards()),
 my_numPlayerDealtCards(0),
 my_numDealerDealtCards(0),
 my_minDealtCards(0),
 my_usedCards(0),
 my_shuffleLimit(40),
 my_heart("\x3"),
 my_diamond("\x4"),
 my_club("\x5"),
 my_spade("\x6"),
 my_two("2"),
 my_three("3"),
 my_four("4"),
 my_five("5"),
 my_six("6"),
 my_seven("7"),
 my_eight("8"),
 my_nine("9"),
 my_ten("10"),
 my_jack("J"),
 my_queen("Q"),
 my_king("K"),
 my_ace("A"),
 my_space(" ")
{

	//////////////////////////////////////////////
	// Initializing the cards
	my_cards.at(0)  = two()   + heart()   + space();		
	my_cards.at(1)  = two()   + diamond() + space();
	my_cards.at(2)  = two()   + club()    + space();
	my_cards.at(3)  = two()   + spade()   + space();
	my_cards.at(4)  = three() + heart()   + space();
	my_cards.at(5)  = three() + diamond() + space();
 	my_cards.at(6)  = three() + club()    + space();
	my_cards.at(7)  = three() + spade()   + space();
	my_cards.at(8)  = four()  + heart()   + space();
	my_cards.at(9)  = four()  + diamond() + space();
	my_cards.at(10) = four()  + club()    + space();
	my_cards.at(11) = four()  + spade()   + space();
	my_cards.at(12) = five()  + heart()   + space();
	my_cards.at(13) = five()  + diamond() + space();
	my_cards.at(14) = five()  + club()    + space();
	my_cards.at(15) = five()  + spade()   + space();
	my_cards.at(16) = six()   + heart()   + space();
	my_cards.at(17) = six()   + diamond() + space();
	my_cards.at(18) = six()   + club()    + space();
	my_cards.at(19) = six()   + spade()   + space();
	my_cards.at(20) = seven() + heart()   + space();
	my_cards.at(21) = seven() + diamond() + space();
	my_cards.at(22) = seven() + club()    + space();
	my_cards.at(23) = seven() + spade()   + space();
	my_cards.at(24) = eight() + heart()   + space();
	my_cards.at(25) = eight() + diamond() + space();
	my_cards.at(26) = eight() + club()    + space();
	my_cards.at(27) = eight() + spade()   + space();
	my_cards.at(28) = nine()  + heart()   + space();
	my_cards.at(29) = nine()  + diamond() + space();
	my_cards.at(30) = nine()  + club()    + space();
	my_cards.at(31) = nine()  + spade()   + space();
	my_cards.at(32) = ten()   + heart();
	my_cards.at(33) = ten()   + diamond();
	my_cards.at(34) = ten()   + club();
	my_cards.at(35) = ten()   + spade();
	my_cards.at(36) = jack()  + heart()   + space();
	my_cards.at(37) = jack()  + diamond() + space();
	my_cards.at(38) = jack()  + club()    + space();
	my_cards.at(39) = jack()  + spade()   + space();
	my_cards.at(40) = queen() + heart()   + space();
	my_cards.at(41) = queen() + diamond() + space();
	my_cards.at(42) = queen() + club()    + space();
	my_cards.at(43) = queen() + spade()   + space();
	my_cards.at(44) = king()  + heart()   + space();
	my_cards.at(45) = king()  + diamond() + space();
	my_cards.at(46) = king()  + club()    + space();
	my_cards.at(47) = king()  + spade()   + space();
	my_cards.at(48) = ace()   + heart()   + space();
	my_cards.at(49) = ace()   + diamond() + space();
	my_cards.at(50) = ace()   + club()    + space();
	my_cards.at(51) = ace()   + spade()   + space();

	//////////////////////////////////////////////
	// Resetting the cards to three blank spaces
	for_each(my_playerCards.begin(), my_playerCards.end(), resetCards);
	for_each(my_dealerCards.begin(), my_dealerCards.end(), resetCards);
}

//////////////////////////////////////////////
// Destructors
Deck::~Deck()
{
}

//////////////////////////////////////////////
// Modifiers
void Deck::dealCards(string who)
{
	// Randomizes the sequence
	srand(time(NULL));

	counter_t my_temp(0);
	if(numPlayerDealtCards() == my_minDealtCards  
		&& numDealerDealtCards() == my_minDealtCards  
		&& who == "Both")
	{	
		if(my_usedCards.size() > my_shuffleLimit)
		{
			// Shuffle the deck
			clearScreen();
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tShuffling Deck. Please Hold..." 
				      << std::endl;
			for(counter_t i(0); i < 99999999; ++i);
			my_usedCards.erase(my_usedCards.begin(), my_usedCards.end());
		}
		
		//////////////////////////////////////////////
		// Deal to the Dealer
		my_temp = (rand() % my_maxCards);
		while(checkUsedCard(my_cards[my_temp]) == true)
		{
			my_temp = (rand() % my_maxCards);
		}

		my_dealerCards.at(numDealerDealtCards()) = my_cards[my_temp];
        // Store the card in the my_usedCards container
		my_usedCards.push_back(my_dealerCards.at(numDealerDealtCards()));

		//////////////////////////////////////////////
		// Deal to the Player
		my_temp = (rand() % my_maxCards);
		while(checkUsedCard(my_cards[my_temp]) == true)
		{
			my_temp = (rand() % my_maxCards);
		}

		my_playerCards.at(numPlayerDealtCards()) = my_cards[my_temp];
        // Store the card in the my_usedCards container
		my_usedCards.push_back(my_playerCards.at(numPlayerDealtCards()));

		// Increase the number of cards dealth to 1. One for each player
		my_numPlayerDealtCards++;
		my_numDealerDealtCards++;

		//////////////////////////////////////////////
		// Deal to the Dealer
		my_temp = (rand() % my_maxCards);
		while(checkUsedCard(my_cards[my_temp]) == true)
		{
			my_temp = (rand() % my_maxCards);
		}

		my_dealerCards.at(numDealerDealtCards()) = my_cards[my_temp];
        // Store the card in the my_usedCards container
		my_usedCards.push_back(my_dealerCards.at(numDealerDealtCards()));

		//////////////////////////////////////////////
		// Deal to the Player
		my_temp = (rand() % my_maxCards);
		while(checkUsedCard(my_cards[my_temp]) == true)
		{
			my_temp = (rand() % my_maxCards);
		}

		my_playerCards.at(numPlayerDealtCards()) = my_cards[my_temp];
        // Store the card in the my_usedCards container
		my_usedCards.push_back(my_playerCards.at(numPlayerDealtCards()));

		// Increase the number of cards dealt to 1. One for each player
		my_numPlayerDealtCards++;
		my_numDealerDealtCards++;

	}
	else if(who == "Player" || who == "Dealer")
	{
		if(who == "Player")
		{
			//////////////////////////////////////////////
			// Deal to the Player
			my_temp = (rand() % my_maxCards);
			while(checkUsedCard(my_cards[my_temp]) == true)
			{
				my_temp = (rand() % my_maxCards);
			}

			my_playerCards.at(numPlayerDealtCards()) = my_cards[my_temp];
			// Store the card in the my_usedCards container
			my_usedCards.push_back(my_playerCards.at(numPlayerDealtCards()));

			// Increase the number of cards dealt to 1.
			my_numPlayerDealtCards++;
		}
		else if(who == "Dealer")
		{
			//////////////////////////////////////////////
			// Deal to the Dealer
			my_temp = (rand() % my_maxCards);
			while(checkUsedCard(my_cards[my_temp]) == true)
			{
				my_temp = (rand() % my_maxCards);
			}

			my_dealerCards.at(numDealerDealtCards()) = my_cards[my_temp];
			// Store the card in the my_usedCards container
			my_usedCards.push_back(my_dealerCards.at(numDealerDealtCards()));

			// Increase the number of cards dealt to 1.
			my_numDealerDealtCards++;
		}
	}
	else
	{
		// Exception is thrown if the player is invalid (string who)
		throw domain_error("Invalid who type in dealCards(string who)");
	}
}

void Deck::resetValues()
{
	// Resetting the cards to three blank spaces
	for_each(my_playerCards.begin(), my_playerCards.end(), resetCards);
	for_each(my_dealerCards.begin(), my_dealerCards.end(), resetCards);

	// Reset the number of cards dealth
	my_numPlayerDealtCards = (0);
	my_numDealerDealtCards = (0);
}

bool Deck::checkUsedCard(const card_t& c)
{
	bool result(false);
	string::size_type pos;

	for(counter_t i(0); i < my_usedCards.size(); ++i)
	{
        pos = my_usedCards.at(i).find(c, 0);
		if(pos != string::npos)
		{
			result = (true);
		}
	}
	return(result);
}

//////////////////////////////////////////////
// Accessors
//////////////////////////////////////////////
// Suites
card_t Deck::heart() const
{
	return(my_heart);
}

card_t Deck::diamond() const
{
	return(my_diamond);
}

card_t Deck::club() const
{
	return(my_club);
}

card_t Deck::spade() const
{
	return(my_spade);
}

//////////////////////////////////////////////
// Numbers
card_t Deck::two() const
{
	return(my_two);
}

card_t Deck::three() const
{
	return(my_three);
}

card_t Deck::four() const
{
	return(my_four);
}

card_t Deck::five() const
{
	return(my_five);
}

card_t Deck::six() const
{
	return(my_six);
}

card_t Deck::seven() const
{
	return(my_seven);
}

card_t Deck::eight() const
{
	return(my_eight);
}

card_t Deck::nine() const
{
	return(my_nine);
}

card_t Deck::ten() const
{
	return(my_ten);
}

//////////////////////////////////////////////
// Faces
card_t Deck::jack() const
{
	return(my_jack);
}

card_t Deck::queen() const
{
	return(my_queen);
}

card_t Deck::king() const
{
	return(my_king);
}

card_t Deck::ace() const
{
	return(my_ace);
}

//////////////////////////////////////////////
// Blank Space
card_t Deck::space() const
{
	return(my_space);
}

card_t Deck::playerCards(counter_t index)
{
	return(my_playerCards[index]);
}

card_t Deck::dealerCards(counter_t index)
{
	return(my_dealerCards[index]);
}

image_t Deck::playerCards(counter_t index1, counter_t index2)
{
	return(my_playerCards.at(index1).at(index2));
}

image_t Deck::dealerCards(counter_t index, counter_t index2)
{
	return(my_dealerCards.at(index).at(index2));
}

counter_t Deck::maxCards() const
{
	return(my_maxCards);
}

counter_t Deck::maxDealtCards() const
{
	return(my_maxBlackjackDealtCards);
}

counter_t Deck::numPlayerDealtCards() const
{
	return(my_numPlayerDealtCards);
}

counter_t Deck::numDealerDealtCards() const
{
	return(my_numDealerDealtCards);
}
//--------------------------------------------