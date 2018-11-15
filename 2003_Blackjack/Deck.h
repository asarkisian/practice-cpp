//--------------------------------------------
// Deck.h

#pragma once
#pragma warning(disable : 4512)

#include "typedefs.h"

class Deck
{
public:

	//////////////////////////////////////////////
	// Constructors
	Deck();

	//////////////////////////////////////////////
	// Destructors
	~Deck();

	//////////////////////////////////////////////
	// Modifiers
	void dealCards(std::string who);

	void resetValues();
	bool checkUsedCard(const card_t& c);

	//////////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////////
	// Suites
	card_t heart() const;
	card_t diamond() const;
	card_t club() const;
	card_t spade() const;
	
	//////////////////////////////////////////////
	// Numbers
	card_t two() const;
	card_t three() const;
	card_t four() const;
	card_t five() const;
	card_t six() const;
	card_t seven() const;
	card_t eight() const;
	card_t nine() const;
	card_t ten() const;

	//////////////////////////////////////////////
	// Faces
	card_t jack() const;
	card_t queen() const;
	card_t king() const;
	card_t ace() const;

	//////////////////////////////////////////////
	// Blank Space
	card_t space() const;

	card_t playerCards(counter_t index);
	card_t dealerCards(counter_t index);
	image_t playerCards(counter_t index1, counter_t index2);
	image_t dealerCards(counter_t index1, counter_t index2);

	counter_t maxCards() const;
	counter_t maxDealtCards() const;
	
	counter_t numPlayerDealtCards() const;
	counter_t numDealerDealtCards() const;

private:

	//////////////////////////////////////////////
	// Private Data
	const counter_t my_maxCards; 
	const counter_t my_maxBlackjackDealtCards;

	cards_t my_cards;
	cards_t my_playerCards;
    cards_t my_dealerCards;

	counter_t my_numPlayerDealtCards;
	counter_t my_numDealerDealtCards;
	counter_t my_minDealtCards;

	cards_t my_usedCards;

	counter_t my_shuffleLimit;

	//////////////////////////////////////////////
	// Suites
	const card_t my_heart;
	const card_t my_diamond;
	const card_t my_club;
	const card_t my_spade;

	//////////////////////////////////////////////
	// Numbers
	const card_t my_two;
	const card_t my_three;
	const card_t my_four;
	const card_t my_five;
	const card_t my_six;
	const card_t my_seven;
	const card_t my_eight;
	const card_t my_nine;
	const card_t my_ten;
		
	//////////////////////////////////////////////
	// Faces
	const card_t my_jack;
	const card_t my_queen;
	const card_t my_king;
	const card_t my_ace;

	//////////////////////////////////////////////
	// Blank Space
	const card_t my_space;
};
//--------------------------------------------