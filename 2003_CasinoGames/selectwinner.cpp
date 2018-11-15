#pragma warning(disable : 4244)

#include "blackjack.h"
#include "poker.h"
using std::cout;
using std::endl;
using std::cin;

void CBlackjack::selectWinner()
{
    isHumanHit = false;
    isHumanStay = true;
    showScreen();

    if(isDraw == true && isHumanWin == false && isComputerWin == false)
    {
        cout << "Draw game!!!" << endl;
        calcPlayerMoney("DRAW GAME");
    }
    else if(isHumanWin == true && isComputerWin == false && isHumanBlackjack == true
    && isComputerBlackjack == false && isDraw == false)
    {
        calcPlayerMoney("BLACKJACK WIN");
        showScreen();
        cout << playersName << " won with a Blackjack!!!" << endl;
    }
    else if(isComputerWin == true && isHumanWin == false && isComputerBlackjack == true
    && isHumanBlackjack == false && isDraw == false)
    {
        cout << "Dealer Blackjack!!!" << endl;
    }
    else if(isHumanWin == true && isComputerWin == false && isDraw == false)
    {
        calcPlayerMoney("PLAYER WIN");
        showScreen();
        cout << playersName << " wins!!!" << endl;
    }
    else if(isHumanWin == false && isComputerWin == true && isDraw == false)
    {
        cout <<"Dealer wins!!!" << endl;
    }
    
    isComputerWin = false;
    isHumanWin = false;
    isHumanStay = false;
    isHumanHit = true;
    isComputerStay = false;
    isComputerHit = false;
    isDraw = false;
    isFirstDeal = true;
    isPlayAgain = true;
    isQuit = false;
    clearHands();

	for(int i = 0; i < 999999999; ++i);
}

void CPoker::selectWinner()
{
    //check if anybody has a royal flush
    if(isComputerRoyalFlush == true && isHumanRoyalFlush == true)
    {
        isDraw = true;
	isHumanWin = false;
	isComputerWin = false;
        cout << "Draw game!!!" << endl;
        calcPlayerMoney("DRAW GAME");
    }
    else if(isComputerRoyalFlush == true && isHumanRoyalFlush == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a royal flush!!!" << endl;
    }
    else if(isComputerRoyalFlush == false && isHumanRoyalFlush == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("ROYAL FLUSH");
	showScreen();
	cout << playersName << " wins with a royal flush!!!" << endl;
    }

    //check if anybody has a straight flush
    else if(isComputerStraightFlush == true && isHumanStraightFlush == true)
    {
        if(computerValueCount > humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher straight flush!!!" << endl;
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("STRAIGHT FLUSH");
	    showScreen();
	    cout << playersName << " wins with a higher straight flush!!!" << endl;
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
            calcPlayerMoney("DRAW GAME");
	}
    }
    else if(isComputerStraightFlush == true && isHumanStraightFlush == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a straight flush!!!" << endl;
    }
    else if(isComputerStraightFlush == false && isHumanStraightFlush == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("STRAIGHT FLUSH");
	showScreen();
	cout << playersName << " wins with a straight flush!!!" << endl;
    }


    //check if anybody has a four of a kind
    else if(isComputerFourOfAKind == true && isHumanFourOfAKind == true)
    {
        if(computerWinDepth > humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher four of a kind!!!" << endl;
	}
	else if(computerWinDepth < humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("FOFAK");
	    showScreen();
	    cout << playersName << " wins with a higher four of a kind!!!" << endl;
	}
	else
	{
            if(computerValueCount > humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = false;
	        isComputerWin = true;
	        cout << "Dealer wins with a higher four of a kind!!!" << endl;
	    }
	    else if(computerValueCount < humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = true;
	        isComputerWin = false;
		calcPlayerMoney("FOFAK");
		showScreen();
	        cout << playersName << " wins with a higher four of a kind!!!" << endl;
	    }
	    else
	    {
		isDraw = true;
                isHumanWin = false;
	        isComputerWin = false;
                cout << "Draw game!!!" << endl;
                calcPlayerMoney("DRAW GAME");
	    }
	}
    }
    else if(isComputerFourOfAKind == true && isHumanFourOfAKind == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a four of a kind!!!" << endl;
    }
    else if(isComputerFourOfAKind == false && isHumanFourOfAKind == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("FOFAK");
	showScreen();
	cout << playersName << " wins with a four of a kind!!!" << endl;
    }


    //check if anybody has a full house
    else if(isComputerFullHouse == true && isHumanFullHouse == true)
    {
        if(computerValueCount > humanValueCount)
	{
            isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher full house!!!" << endl;
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    calcPlayerMoney("FULL HOUSE");
	    showScreen();
	    cout << playersName << " wins with a higher full house!!!" << endl;
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
            calcPlayerMoney("DRAW GAME");
	}
    }
    else if(isComputerFullHouse == true && isHumanFullHouse == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a full house!!!" << endl;
    }
    else if(isComputerFullHouse == false && isHumanFullHouse == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("FULL HOUSE");
	showScreen();
	cout << playersName << " wins with a full house!!!" << endl;
    }

    //check if anybody has a flush
    else if(isComputerFlush == true && isHumanFlush == true)
    {
        if(computerValueCount > humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher flush!!!" << endl;
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("FLUSH");
	    showScreen();
	    cout << playersName << " wins with a higher flush!!!" << endl;
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
            calcPlayerMoney("DRAW GAME");
	}
    }
    else if(isComputerFlush == true && isHumanFlush == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a flush!!!" << endl;
    }
    else if(isComputerFlush == false && isHumanFlush == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("FLUSH");
	showScreen();
	cout << playersName << " wins with a flush!!!" << endl;
    }

    //check if anybody has a straight
    else if(isComputerStraight == true && isHumanStraight == true)
    {
        if(computerValueCount > humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher straight!!!" << endl;
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("STRAIGHT");
	    showScreen();
	    cout << playersName << " wins with a higher straight!!!" << endl;
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
            calcPlayerMoney("DRAW GAME");
	}
    }
    else if(isComputerStraight == true && isHumanStraight == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a straight!!!" << endl;
    }
    else if(isComputerStraight == false && isHumanStraight == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("STRAIGHT");
	showScreen();
	cout << playersName << " wins with a straight!!!" << endl;
    }

    //check if anybody has a three of a kind
    else if(isComputerThreeOfAKind == true && isHumanThreeOfAKind == true)
    {
        if(computerWinDepth > humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher three of a kind!!!" << endl;
	}
	else if(computerWinDepth < humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher three of a kind!!!" << endl;
	}
	else
	{
            if(computerValueCount > humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = false;
	        isComputerWin = true;
	        cout << "Dealer wins with a higher three of a kind!!!" << endl;
	    }
	    else if(computerValueCount < humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = true;
	        isComputerWin = false;
		calcPlayerMoney("OTHER");
		showScreen();
	        cout << playersName << " wins with a higher three of a kind!!!" << endl;
	    }
	    else
	    {
		isDraw = true;
                isHumanWin = false;
	        isComputerWin = false;
                cout << "Draw game!!!" << endl;
                calcPlayerMoney("DRAW GAME");
	    }
	}
    }
    else if(isComputerThreeOfAKind == true && isHumanThreeOfAKind == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a three of a kind!!!" << endl;
    }
    else if(isComputerThreeOfAKind == false && isHumanThreeOfAKind == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a three of a kind!!!" << endl;
    }

    //check if anybody has a two pair
    else if(isComputerTwoPair == true && isHumanTwoPair == true)
    {
        if(computerValueCount > humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher two pair!!!" << endl;
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher two pair!!!" << endl;
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
            calcPlayerMoney("DRAW GAME");
	}
    }
    else if(isComputerTwoPair == true && isHumanTwoPair == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a two pair!!!" << endl;
    }
    else if(isComputerTwoPair == false && isHumanTwoPair == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a two pair!!!" << endl;
    }

    //check if anybody has a one pair
    else if(isComputerOnePair == true && isHumanOnePair == true)
    {
        if(computerWinDepth > humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher pair!!!" << endl;
	}
	else if(computerWinDepth < humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher pair!!!" << endl;
	}
	else
	{
            if(computerValueCount > humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = false;
	        isComputerWin = true;
	        cout << "Dealer wins with a higher pair" << endl;
	    }
	    else if(computerValueCount < humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = true;
	        isComputerWin = false;
		calcPlayerMoney("OTHER");
		showScreen();
	        cout << playersName << " wins with a higher pair" << endl;
	    }
	    else
	    {
		isDraw = true;
                isHumanWin = false;
	        isComputerWin = false;
                cout << "Draw game!!!" << endl;
                calcPlayerMoney("DRAW GAME");
	    }
	}
    }
    else if(isComputerOnePair == true && isHumanOnePair == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a pair!!!" << endl;
    }
    else if(isComputerOnePair == false && isHumanOnePair == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a pair!!!" << endl;
    }


    //check if anybody has no hand
    else if(isComputerNoHand == true && isHumanNoHand == true)
    {
        if(computerValueCount > humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    cout << "Dealer wins with a higher hand!!!" << endl;
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher hand!!!" << endl;
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
            calcPlayerMoney("DRAW GAME");
	}
    }
    else if(isComputerNoHand == true && isHumanNoHand == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a higher hand!!!" << endl;
    }
    else if(isComputerStraight == false && isHumanStraight == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a higher hand!!!" << endl;
    }

	for(int i = 0; i < 999999999; ++i);
}