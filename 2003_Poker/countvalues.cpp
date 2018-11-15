#include "poker.h"

void CPoker::countValues()
{
   humanValueCount = 0;
   computerValueCount = 0;

    isComputerRoyalFlush = isComputerStraight = false;
    isComputerFourOfAKind = isComputerFullHouse = false;
    isComputerFlush = isComputerStraight = isComputerThreeOfAKind = false;
    isComputerTwoPair = isComputerOnePair = false;
    isComputerNoHand = true;

    isHumanRoyalFlush = isHumanStraight = false;
    isHumanFourOfAKind = isHumanFullHouse = false;
    isHumanFlush = isHumanStraight = isHumanThreeOfAKind = false;
    isHumanTwoPair = isHumanOnePair = false;
    isHumanNoHand = true;

    heartCounter = spadeCounter = clubCounter = diamondCounter = 0;
    aceCounter = kingCounter = queenCounter = jackCounter = 0;
    tenCounter = nineCounter = eightCounter = sevenCounter = 0;
    sixCounter = fiveCounter = fourCounter = threeCounter = twoCounter = 0;

    heartHumanCounter = spadeHumanCounter = clubHumanCounter = diamondHumanCounter = 0;
    aceHumanCounter = kingHumanCounter = queenHumanCounter = jackHumanCounter = 0;
    tenHumanCounter = nineHumanCounter = eightHumanCounter = sevenHumanCounter = 0;
    sixHumanCounter = fiveHumanCounter = fourHumanCounter = threeHumanCounter = twoHumanCounter = 0;

   //counting the computer values of the cards and symbols
   for(int i = 0; i < 5; ++i)
   {

    	   //Card Numbers
       if(computerHand[i][0] == '2')
       {
           computerValueCount += TWO;
	   ++twoCounter;
       }
       else if(computerHand[i][0] == '3')
       {
           computerValueCount += THREE;
	   ++threeCounter;
       }
       else if(computerHand[i][0] == '4')
       {
           computerValueCount += FOUR;
	   ++fourCounter;
       }
       else if(computerHand[i][0] == '5')
       {
           computerValueCount += FIVE;
	   ++fiveCounter;
       }
       else if(computerHand[i][0] == '6')
       {
           computerValueCount += SIX;
	   ++sixCounter;
       }
       else if(computerHand[i][0] == '7')
       {
           computerValueCount += SEVEN;
	   ++sevenCounter;
       }
       else if(computerHand[i][0] == '8')
       {
           computerValueCount += EIGHT;
	   ++eightCounter;
       }
       else if(computerHand[i][0] == '9')
       {
           computerValueCount += NINE;
	   ++nineCounter;
       }
       else if(computerHand[i][0] == '1')
       {
           computerValueCount += TEN;
	   ++tenCounter;
       }
       else if(computerHand[i][0] == 'J')
       {
           computerValueCount += JACK;
	   ++jackCounter;
       }
       else if(computerHand[i][0] == 'Q')
       {
           computerValueCount += QUEEN;
	   ++queenCounter;
       }
       else if(computerHand[i][0] == 'K')
       {
           computerValueCount += KING;
	   ++kingCounter;
       }
       else if(computerHand[i][0] == 'A')
       {
           computerValueCount += ACE;
	   ++aceCounter;
       }

       //Card Symbols
       if(computerHand[i][1] == '0')
       {
           if(computerHand[i][2] == 'H')
	   {
	       ++heartCounter;
	   }
	   else if(computerHand[i][2] == 'S')
	   {
	       ++spadeCounter;
	   }
	   else if(computerHand[i][2] == 'C')
	   {
	       ++clubCounter;
	   }
	   else if(computerHand[i][2] == 'D')
	   {
	       ++diamondCounter;
	   }
       }

       if(computerHand[i][1] == 'H')
       {
	   ++heartCounter;
       }
       else if(computerHand[i][1] == 'S')
       {
	   ++spadeCounter;
       }
       else if(computerHand[i][1] == 'C')
       {
	   ++clubCounter;
       }
       else if(computerHand[i][1] == 'D')
       {
	   ++diamondCounter;
       }
   }


   //counting the player values of the cards and symbols
   for(int i = 0; i < 5; ++i)
   {
    	   //Card Numbers
       if(playerHand[i][0] == '2')
       {
           humanValueCount += TWO;
	   ++twoHumanCounter;
       }
       else if(playerHand[i][0] == '3')
       {
           humanValueCount += THREE;
	   ++threeHumanCounter;
       }
       else if(playerHand[i][0] == '4')
       {
           humanValueCount += FOUR;
	   ++fourHumanCounter;
       }
       else if(playerHand[i][0] == '5')
       {
           humanValueCount += FIVE;
	   ++fiveHumanCounter;
       }
       else if(playerHand[i][0] == '6')
       {
           humanValueCount += SIX;
	   ++sixHumanCounter;
       }
       else if(playerHand[i][0] == '7')
       {
           humanValueCount += SEVEN;
	   ++sevenHumanCounter;
       }
       else if(playerHand[i][0] == '8')
       {
           humanValueCount += EIGHT;
	   ++eightHumanCounter;
       }
       else if(playerHand[i][0] == '9')
       {
           humanValueCount += NINE;
	   ++nineHumanCounter;
       }
       else if(playerHand[i][0] == '1')
       {
           humanValueCount += TEN;
	   ++tenHumanCounter;
       }
       else if(playerHand[i][0] == 'J')
       {
           humanValueCount += JACK;
	   ++jackHumanCounter;
       }
       else if(playerHand[i][0] == 'Q')
       {
           humanValueCount += QUEEN;
	   ++queenHumanCounter;
       }
       else if(playerHand[i][0] == 'K')
       {
           humanValueCount += KING;
	   ++kingHumanCounter;
       }
       else if(playerHand[i][0] == 'A')
       {
           humanValueCount += ACE;
	   ++aceHumanCounter;
       }

       //Card Symbols
       if(playerHand[i][1] == '0')
       {
           if(playerHand[i][2] == 'H')
	   {
	       ++heartHumanCounter;
	   }
	   else if(playerHand[i][2] == 'S')
	   {
	       ++spadeHumanCounter;
	   }
	   else if(playerHand[i][2] == 'C')
	   {
	       ++clubHumanCounter;
	   }
	   else if(playerHand[i][2] == 'D')
	   {
	       ++diamondHumanCounter;
	   }
       }

       if(playerHand[i][1] == 'H')
       {
	   ++heartHumanCounter;
       }
       else if(playerHand[i][1] == 'S')
       {
	   ++spadeHumanCounter;
       }
       else if(playerHand[i][1] == 'C')
       {
	   ++clubHumanCounter;
       }
       else if(playerHand[i][1] == 'D')
       {
	   ++diamondHumanCounter;
       }
   }
}
