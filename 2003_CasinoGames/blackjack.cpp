//--------------------------------------------------
//blackjack.cpp

#include "blackjack.h"

CBlackjack::CBlackjack(name_t n, money_t t)
	:CGame(n, t),
	playerHand(12),
	computerHand(12),
	isHumanBlackjack(false),
	isComputerBlackjack(false)
{
    for(counter_t i = 0; i < 12; ++i)
    {
        playerHand[i]   = "   ";
        computerHand[i] = "   ";
    }
}

CBlackjack::~CBlackjack()
{}

//--------------------------------------------------
