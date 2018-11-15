//--------------------------------------------------
//domain.cpp

#include "poker.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void CPoker::doMain()
{
    char myChoice = ' ';
    int i = 0;
    clearHands();

    cout << "Ready to make a wager " << playersName << "? (Y)es, (N)o: ";
    cin >> myChoice;
    myChoice = toupper(myChoice);

    if(myChoice == 'N')
    {
        quit();
        return;
    }
    if(playerMoney == 0)
    {
        cout << "\n" << playersName << " left the poker table due to insufficient funds. Come back soon!!!\n" << endl;
        quit();
        return;
    }


    while(isQuit == false)
    {
	showScreen();
        myChoice = ' ';

        placeWager();
        calcPlayerMoney("DEAL");

        if(isFirstDeal == true)
        {
            isQuit = false;
            isDraw = false;
            isHumanWin = false;
            isComputerWin = false;
            isHumanHit = true;
            isHumanStay = false;
	    isComputerHit = true;
	    isComputerStay = false;
            isFirstDeal = false;
            computerValueCount = 0;
            humanValueCount = 0;
            computerWinDepth = 0;
            humanWinDepth = 0;
            keepingCards = 0;
	    i = 0;
	    numberOfHumanDiscards = 0;
	    numberOfComputerDiscards = 0;
            clearHands();
	    dealCards(5, 5);
            showScreen();
        }

bool oneStatus = false, twoStatus = false, threeStatus = false, fourStatus = false, fiveStatus = false;
string oneTemp = "   ", twoTemp = "   ", threeTemp = "   ", fourTemp = "   ", fiveTemp = "   ";

        while(isHumanStay == false && isHumanHit == true && numberOfHumanDiscards < 4)
        {
	    showScreen();
            cout << playersName << ", which cards are you discarding? ";
            cin >> keepingCards;

            switch(keepingCards)
            {
            case 1:
            {
                if(oneStatus == false)
                {
                    if(playerHand[0] != "   ")
                    {
                        oneTemp = playerHand[0];
                        playerHand[0] = "   ";
                        ++numberOfHumanDiscards;
                        oneStatus = true;
                    }
                }
                else
                {
                    if(playerHand[0] == "   ")
                    {
                        playerHand[0] = oneTemp;
                        --numberOfHumanDiscards;
                        oneStatus = false;
                    }
                } 
                break;
            }
            case 2:
            {
                if(twoStatus == false)
                {
                    if(playerHand[1] != "   ")
                    {
                        twoTemp = playerHand[1];
                        playerHand[1] = "   ";
                        ++numberOfHumanDiscards;
                        twoStatus = true;
                    }
                }
                else
                {
                    if(playerHand[1] == "   ")
                    {
                        playerHand[1] = twoTemp;
                        --numberOfHumanDiscards;
                        twoStatus = false;
                    }  
                }
                break;
            }
            case 3:
            {
                if(threeStatus == false)
                {
                    if(playerHand[2] != "   ")
                    {
                        threeTemp = playerHand[2];
                        playerHand[2] = "   ";
                        ++numberOfHumanDiscards;
                        threeStatus = true;
                    }
                }
                else
                {
                    if(playerHand[2] == "   ")
                    {
                        playerHand[2] = threeTemp;
                        --numberOfHumanDiscards;
                        threeStatus = false;
                    }
                }
                break;
            }
            case 4:
            {
                if(fourStatus == false)
                { 
                    if(playerHand[3] != "   ")
                    {
                        fourTemp = playerHand[3];
                        playerHand[3] = "   ";
                        ++numberOfHumanDiscards;
                        fourStatus = true;
                    }
                }
                else
                {
                    if(playerHand[3] == "   ")
                    {
                        playerHand[3] = fourTemp;
                        --numberOfHumanDiscards;
                        fourStatus = false;
                    }
                }
                break;
            }
            case 5:
            {
                if(fiveStatus == false)
                {        
                    if(playerHand[4] != "   ")
                    {
                        fiveTemp = playerHand[4];
                        playerHand[4] = "   ";
                        ++numberOfHumanDiscards;
                        fiveStatus = true;
                    }
                }
                else
                {
                    if(playerHand[4] == "   ")
                    {
                        playerHand[4] = fiveTemp;
                        --numberOfHumanDiscards;
                        fiveStatus = false;
                    }
                }
                break;
            }
            case 6:
            {
                isHumanHit = false;
                isHumanStay = true;
		isComputerHit = true;
		isComputerStay = false;
            }
            }
        }
        while(numberOfHumanDiscards > 0)
        {
            dealCards(0, numberOfHumanDiscards);
        }
	showScreen(); 
	
	countValues();
	checkPatterns();
        
	if(isComputerStay == false && isComputerHit == true)
	{
	    discardCards();
	    countValues();
            checkPatterns();
	}
	showScreen();
        selectWinner();
	isFirstDeal = true;
	return;
    }
}

//--------------------------------------------------
