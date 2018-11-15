#include "poker.h"

void CPoker::discardCards()
{
    if(isComputerThreeOfAKind == true)
    {
	if(twoCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '2')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '2')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(threeCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '3')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '3')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(fourCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '4')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '4')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(fiveCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '5')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '5')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(sixCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '6')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '6')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(sevenCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '7')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '7')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(eightCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '8')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '8')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(nineCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '9')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '9')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(tenCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '1')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != '1')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(jackCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'J')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != 'J')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(queenCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'Q')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != 'Q')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(kingCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'K')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != 'K')
		{
		    dealCards(1, 0);
		}
	    }
        }
        else if(aceCounter == 3)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'A')
                {
                    computerHand[i] = "   ";
                }
	    }
	    showScreen();
	    system("sleep 1");
	    dealCards(1, 0);
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] != 'A')
		{
		    dealCards(1, 0);
		}
	    }
        }

	isComputerStay = true;
	isComputerHit = false;
        return;
    }
    else if(isComputerTwoPair == true)
    {
        if(twoCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '2')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(threeCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '3')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(fourCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '4')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(fiveCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '5')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(sixCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '6')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(sevenCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '7')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(eightCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '8')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
        }
	else if(nineCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '9')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(tenCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == '1')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(jackCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == 'J')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(queenCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == 'Q')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(kingCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == 'K')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	else if(aceCounter == 1)
	{
	    for(int i = 0; i < 5; ++i)
	    {
	        if(computerHand[i][0] == 'A')
		{
		    computerHand[i] = "   ";
		}
	    }
	    showScreen();
            system("sleep 1");
            dealCards(1, 0);
	}
	isComputerStay = true;
	isComputerHit = false;
        return;
    }
    else if(isComputerOnePair == true)
    {
	if(twoCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '2')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '2')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(threeCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '3')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '3')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(fourCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '4')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '4')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(fiveCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '5')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '5')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(sixCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '6')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '6')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(sevenCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '7')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '7')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(eightCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '8')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '8')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(nineCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '9')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '9')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(tenCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '1')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != '1')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(jackCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'J')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'J')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(queenCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'Q')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'Q')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(kingCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'K')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'K')
                {
  		    dealCards(1, 0);
                }
            }
        }
        else if(aceCounter == 2)
        {
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'A')
                {
                    computerHand[i] = "   ";
                }
            }
	    showScreen();
            system("sleep 1");
            for(int i = 0; i < 5; ++i)
            {
                if(computerHand[i][0] != 'A')
                {
  		    dealCards(1, 0);
                }
            }
        }

	isComputerStay = true;
	isComputerHit = false;
        return;
    }
    else if(isComputerNoHand == true)
    {
        char highCard = '0';

        for(int i = 0; i < 5; ++i)
	{
            if(computerHand[i][0] == 'A' )
	    {
	        highCard = 'A';
	    }
	    else if(computerHand[i][0] == 'K')
	    {
	        if(highCard != 'A')
		{
		    highCard = 'K';
		}
	    }
	    else if(computerHand[i][0] == 'Q')
	    {
	        if(highCard != 'A' && highCard != 'K')
		{
		    highCard = 'Q';
		}
	    }
	    else if(computerHand[i][0] == 'J')
	    {
	        if(highCard != 'A' && highCard != 'K' && highCard != 'Q')
		{
		    highCard = 'J';
		}
	    }
	    else if(computerHand[i][0] == '1')
	    {
                if(highCard != 'A' && highCard != 'K' && highCard != 'Q' && highCard != 'J')
		{
		    highCard = '1';
		}
	    }
	    else
	    {
	        if(computerHand[i][0] > highCard && computerHand[i][0] <= '9')
		{
                    highCard = computerHand[i][0];
		}
	    }
	}

        for(int i = 0; i < 5; ++i)
	{
	    if(computerHand[i][0] != highCard)
	    {
                computerHand[i] = "   ";
            }
	}

	showScreen();
        system("sleep 1");
        for(int i = 0; i < 5; ++i)
        {
            if(computerHand[i][0] != 'A')
            {
                dealCards(1, 0);
            }
        }

	isComputerStay = true;
	isComputerHit = false;
        return;
    }
}
