//--------------------------------------------------
//blackjack.h

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "game.h"

const minsize_t MINCARDS       =  2;
//const maxsize_t MAXSIZE      = 12;
const maxsize_t BLACKJACK      = 21;
const maxsize_t DEALERHITLIMIT = 17;

class CBlackjack : public CGame
{
public:
    //constructor
    CBlackjack();
    CBlackjack(name_t, money_t);
    virtual ~CBlackjack();

    //modifier
    money_t doMain         ();
    void    clearHands     ();
    void    countValues    ();
    void    selectWinner   ();
    void    calcPlayerMoney(std::string);
    void    dealCards      (counter_t, counter_t, counter_t);

    //accessors
    void displayGrid () const;

private:
    std::vector <cards_t> playerHand;
    std::vector <cards_t> computerHand;
    option_t  isHumanBlackjack;
    option_t  isComputerBlackjack;
};

#endif

//--------------------------------------------------
