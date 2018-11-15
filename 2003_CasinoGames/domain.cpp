#include "blackjack.h"
#include "poker.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

money_t CBlackjack::doMain()
{
    selection_t myChoice = ' ';
    counter_t iHuman = 0;
    counter_t iComputer = 0;

    do
    {
        if(isPlayAgain == true)
        {
            showScreen();
            if(playerMoney == 0)
            {
                cout << "\n" << playersName << ", you have no more money to play!" << endl;
                //for(int i = 0; i < 999999999; ++i);
                quit();
                return playerMoney;
            }
            cout << "Place a bet " << playersName << "? (Y)es, (N)o: _\b";
            cin >> myChoice;
            myChoice = toupper(myChoice);

            if(myChoice == 'N')
            {
                quit();
                return playerMoney;
            }
            showScreen();
            placeWager();
	        calcPlayerMoney("DEAL");
            clearHands();
            isHumanBlackjack = isComputerBlackjack = false;
            isDraw = false;
            isQuit = isComputerWin = false;
            isComputerStay = isComputerHit = isHumanStay = isPlayAgain = false;
            isHumanHit = isFirstDeal = true;
            computerValueCount = humanValueCount = iHuman = iComputer = 0;
            myChoice = ' ';
        }

        myChoice = ' ';
        showScreen();

        if(isFirstDeal == true)
        {
            dealCards(2, 0, iComputer);
            dealCards(0, 2, iHuman);
            countValues();

            if(humanValueCount == BLACKJACK && computerValueCount == BLACKJACK)
            {
                isComputerBlackjack = true;
                isHumanBlackjack = false;
                isComputerWin = true;
                isHumanWin = false;
                isDraw = false;
                isComputerHit = isHumanHit = false;
                isHumanStay = isComputerStay = true;
                selectWinner();
                return playerMoney;
            }
            else if(humanValueCount == BLACKJACK)
            {
                isHumanBlackjack = true;
                isComputerBlackjack = false;
                isHumanWin = true;
                isComputerWin = false;
                isDraw = false;
                isHumanHit = isComputerHit = false;
                isHumanStay = isComputerStay = true;
                selectWinner();
                return playerMoney;
            }
            else if(computerValueCount == BLACKJACK)
            {
                isComputerBlackjack = true;
                isHumanBlackjack = false;
                isHumanWin = false;
                isComputerWin = true;
                isDraw = false;
                isHumanHit = isComputerHit = false;
                isHumanStay = isComputerStay = true;
                selectWinner();
                return playerMoney;
            }

            iHuman += 2;
            iComputer += 2;
            isFirstDeal = false;
        }

        countValues();
        showScreen();
        if(isQuit == false)
        {
            cout << "Would you like to stay or hit? (S)tay, (H)it: _\b";
            cin >> myChoice;
            myChoice = toupper(myChoice);

            if(myChoice == 'S')
            {
                isHumanHit = false;
                isComputerHit = true;
                isHumanStay = true;


                if(computerValueCount >= DEALERHITLIMIT)
                {
                    if(computerValueCount > BLACKJACK)
                    {
                        isHumanWin = true;
                        isComputerWin = false;
                        isDraw = false;
                    }
                    else if(computerValueCount > humanValueCount)
                    {
                        isHumanWin = false;
                        isComputerWin = true;
                        isDraw = false;
                    }
                    else if(computerValueCount < humanValueCount)
                    {
                        isHumanWin = true;
                        isComputerWin = false;;
                        isDraw = false;
                    }
                    else if(humanValueCount == computerValueCount)
                    {
                        isHumanWin = false;
                        isComputerWin = false;
                        isDraw = true;
                    }
                    selectWinner();
                }
                else if(computerValueCount > 0)
                {
                    while(computerValueCount < DEALERHITLIMIT)
                    {
                        dealCards(1, 0, iComputer);
                        ++iComputer;
                        countValues();

                        if(computerValueCount >= DEALERHITLIMIT)
                        {
                            if(computerValueCount > BLACKJACK)
                            {
                                isHumanWin = true;
                                isComputerWin = false;
                                isDraw = false;
                            }
		            else if(computerValueCount > humanValueCount)
		            {
		                isHumanWin = false;
                                isComputerWin = true;
                                isDraw = false;
		            }
		            else if(computerValueCount < humanValueCount)
		            {
		                isHumanWin = true;
                                isComputerWin = false;
			        isDraw = false;
                            }
		            else if(humanValueCount == computerValueCount)
		            {
		                isHumanWin = false;
                                isComputerWin = false;
			        isDraw = true;
		            }
		            selectWinner();
                        }
                    }
                }
            }
            else if(myChoice == 'H')
            {
                isHumanHit = true;
                isHumanStay = false;
                dealCards(0, 1, iHuman);
                ++iHuman;
                countValues();

                if(humanValueCount > BLACKJACK)
                {
                    isHumanWin = false;
                    isComputerWin = true;
                    isDraw = false;
		    selectWinner();
                }
            }
        }
    }while(isQuit == false);
    return playerMoney;
}

money_t CPoker::doMain()
{
    char myChoice = ' ';
    int i = 0;
    clearHands();
    showScreen();

    if(playerMoney == 0)
    {
        cout << "\n" << playersName << ", you have no more money to play!" << endl;        
		//for(int i = 0; i < 999999999; ++i);
	    quit();
        return playerMoney;
    }

    while(isQuit == false)
    {
    cout << "Place a bet " << playersName << "? (Y)es, (N)o: _\b";
    cin >> myChoice;
    myChoice = toupper(myChoice);

    if(myChoice == 'N')
    {
        quit();
        return playerMoney;
    }
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
            cout << playersName << ", which cards are you discarding? _\b";
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
        sleep();
	isFirstDeal = true;
	//return playerMoney;
    }
    return playerMoney;
}