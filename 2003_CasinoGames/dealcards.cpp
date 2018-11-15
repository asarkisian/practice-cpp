#include "blackjack.h"
#include "poker.h"

void CBlackjack::dealCards(maxsize_t computerNumber, maxsize_t humanNumber, maxsize_t counter)
{
    temp_t tempNumber = 0;
    
    srand(time(NULL));
    if(counter == 0)
    {
        for(counter_t i = 0; i < MINCARDS; ++i)
        {
            tempNumber = (rand() % 52);
            playerHand[i] = myCards[tempNumber];
            tempNumber = (rand() % 52);
            computerHand[i] = myCards[tempNumber];
        }
    }
    if(counter > 0)
    {
       sleep();;
       if(computerNumber == 1)
       {
           tempNumber = (rand() % 52);
           computerHand[counter] = myCards[tempNumber];
       }
       if(humanNumber == 1)
       {
           tempNumber = (rand() % 52);
           playerHand[counter] = myCards[tempNumber];
       }
    }
}

void CPoker::dealCards(int computerValueCount, int humanValueCount)
{
    int i = 0;
    int tempNumber = 0;

    srand(time(NULL));
    if(computerValueCount ==  5 && humanValueCount == 5)
    {
       //generating random numbers for the computer
       for(int i = 0; i < 5; ++i)
       {
           tempNumber = (rand() % 52);
           computerHand[i] = myCards[tempNumber];
       }

       //this section will be here temporarily
       //computerHand[0] = "3C ";
       //computerHand[1] = "3C ";
       //computerHand[2] = "AS ";
       //computerHand[3] = "9D ";
       //computerHand[4] = "5S ";

       tempNumber = 0;

       //generating random numbers for the player
       for(int i = 0; i < 5; ++i)
       {
           tempNumber = (rand() % 52);
           playerHand[i] = myCards[tempNumber];
       }

       //this section will be here temporarily
       //playerHand[0] = "10C";
       //playerHand[1] = "AS ";
       //playerHand[2] = "6C ";
       //playerHand[3] = "JS ";
       //playerHand[4] = "2S ";

        return;
    }

    tempNumber = 0;

    if(humanValueCount > 0)
    {
        for(int i = 0; i < 5; ++i)
        {
            tempNumber = (rand() % 52);
            if(playerHand[i] == "   ")
            {
                playerHand[i] = myCards[tempNumber];
                --numberOfHumanDiscards;
            }
        }
    }

    i = 0;
    tempNumber = 0;

    if(computerValueCount > 0)
    {
        for(int i = 0; i < 5; ++i)
	{
	    tempNumber = (rand() % 52);
	    if(computerHand[i] == "   ")
	    {
	        computerHand[i] = myCards[tempNumber];
		--numberOfComputerDiscards;
	    }
	}
    }

    i = 0;
    tempNumber = 0;
}
