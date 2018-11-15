#include "poker.h"
#include <iostream>
using std::cout;
using std::endl;

void CPoker::selectWinner()
{
    //check if anybody has a royal flush
    if(isComputerRoyalFlush == true && isHumanRoyalFlush == true)
    {
        isDraw = true;
	isHumanWin = false;
	isComputerWin = false;
        cout << "Draw game!!!" << endl;
	system("pause");
    }
    else if(isComputerRoyalFlush == true && isHumanRoyalFlush == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a royal flush!!!" << endl;
	system("pause");
    }
    else if(isComputerRoyalFlush == false && isHumanRoyalFlush == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("ROYAL FLUSH");
	showScreen();
	cout << playersName << " wins with a royal flush!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("STRAIGHT FLUSH");
	    showScreen();
	    cout << playersName << " wins with a higher straight flush!!!" << endl;
	    system("pause");
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
	    system("pause");
	}
    }
    else if(isComputerStraightFlush == true && isHumanStraightFlush == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a straight flush!!!" << endl;
	system("pause");
    }
    else if(isComputerStraightFlush == false && isHumanStraightFlush == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("STRAIGHT FLUSH");
	showScreen();
	cout << playersName << " wins with a straight flush!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerWinDepth < humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("FOFAK");
	    showScreen();
	    cout << playersName << " wins with a higher four of a kind!!!" << endl;
	    system("pause");
	}
	else
	{
            if(computerValueCount > humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = false;
	        isComputerWin = true;
	        cout << "Dealer wins with a higher four of a kind!!!" << endl;
	        system("pause");
	    }
	    else if(computerValueCount < humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = true;
	        isComputerWin = false;
		calcPlayerMoney("FOFAK");
		showScreen();
	        cout << playersName << " wins with a higher four of a kind!!!" << endl;
	        system("pause");
	    }
	    else
	    {
		isDraw = true;
                isHumanWin = false;
	        isComputerWin = false;
                cout << "Draw game!!!" << endl;
	        system("pause");
	    }
	}
    }
    else if(isComputerFourOfAKind == true && isHumanFourOfAKind == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a four of a kind!!!" << endl;
	system("pause");
    }
    else if(isComputerFourOfAKind == false && isHumanFourOfAKind == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("FOFAK");
	showScreen();
	cout << playersName << " wins with a four of a kind!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = false;
	    isComputerWin = true;
	    calcPlayerMoney("FULL HOUSE");
	    showScreen();
	    cout << playersName << " wins with a higher full house!!!" << endl;
	    system("pause");
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
	    system("pause");
	}
    }
    else if(isComputerFullHouse == true && isHumanFullHouse == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a full house!!!" << endl;
	system("pause");
    }
    else if(isComputerFullHouse == false && isHumanFullHouse == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("FULL HOUSE");
	showScreen();
	cout << playersName << " wins with a full house!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("FLUSH");
	    showScreen();
	    cout << playersName << " wins with a higher flush!!!" << endl;
	    system("pause");
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
	    system("pause");
	}
    }
    else if(isComputerFlush == true && isHumanFlush == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a flush!!!" << endl;
	system("pause");
    }
    else if(isComputerFlush == false && isHumanFlush == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("FLUSH");
	showScreen();
	cout << playersName << " wins with a flush!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("STRAIGHT");
	    showScreen();
	    cout << playersName << " wins with a higher straight!!!" << endl;
	    system("pause");
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
	    system("pause");
	}
    }
    else if(isComputerStraight == true && isHumanStraight == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a straight!!!" << endl;
	system("pause");
    }
    else if(isComputerStraight == false && isHumanStraight == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("STRAIGHT");
	showScreen();
	cout << playersName << " wins with a straight!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerWinDepth < humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher three of a kind!!!" << endl;
	    system("pause");
	}
	else
	{
            if(computerValueCount > humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = false;
	        isComputerWin = true;
	        cout << "Dealer wins with a higher three of a kind!!!" << endl;
	        system("pause");
	    }
	    else if(computerValueCount < humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = true;
	        isComputerWin = false;
		calcPlayerMoney("OTHER");
		showScreen();
	        cout << playersName << " wins with a higher three of a kind!!!" << endl;
	        system("pause");
	    }
	    else
	    {
		isDraw = true;
                isHumanWin = false;
	        isComputerWin = false;
                cout << "Draw game!!!" << endl;
	        system("pause");
	    }
	}
    }
    else if(isComputerThreeOfAKind == true && isHumanThreeOfAKind == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a three of a kind!!!" << endl;
	system("pause");
    }
    else if(isComputerThreeOfAKind == false && isHumanThreeOfAKind == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a three of a kind!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher two pair!!!" << endl;
	    system("pause");
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
	    system("pause");
	}
    }
    else if(isComputerTwoPair == true && isHumanTwoPair == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a two pair!!!" << endl;
	system("pause");
    }
    else if(isComputerTwoPair == false && isHumanTwoPair == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a two pair!!!" << endl;
	system("pause");
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
	    system("pause");
	}
	else if(computerWinDepth < humanWinDepth)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher pair!!!" << endl;
	system("pause");
	}
	else
	{
            if(computerValueCount > humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = false;
	        isComputerWin = true;
	        cout << "Dealer wins with a higher pair" << endl;
	system("pause");
	    }
	    else if(computerValueCount < humanValueCount)
	    {
	        isDraw = false;
	        isHumanWin = true;
	        isComputerWin = false;
		calcPlayerMoney("OTHER");
		showScreen();
	        cout << playersName << " wins with a higher pair" << endl;
	system("pause");
	    }
	    else
	    {
		isDraw = true;
                isHumanWin = false;
	        isComputerWin = false;
                cout << "Draw game!!!" << endl;
	system("pause");
	    }
	}
    }
    else if(isComputerOnePair == true && isHumanOnePair == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a pair!!!" << endl;
	system("pause");
    }
    else if(isComputerOnePair == false && isHumanOnePair == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a pair!!!" << endl;
	system("pause");
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
	system("pause");
	}
	else if(computerValueCount < humanValueCount)
	{
	    isDraw = false;
	    isHumanWin = true;
	    isComputerWin = false;
	    calcPlayerMoney("OTHER");
	    showScreen();
	    cout << playersName << " wins with a higher hand!!!" << endl;
	system("pause");
	}
	else
	{
            isDraw = true;
            isHumanWin = false;
	    isComputerWin = false;
            cout << "Draw game!!!" << endl;
	system("pause");
	}
    }
    else if(isComputerNoHand == true && isHumanNoHand == false)
    {
        isDraw = false;
	isHumanWin = false;
	isComputerWin = true;
	cout << "Dealer wins with a higher hand!!!" << endl;
	system("pause");
    }
    else if(isComputerStraight == false && isHumanStraight == true)
    {
        isDraw = false;
	isHumanWin = true;
	isComputerWin = false;
	calcPlayerMoney("OTHER");
	showScreen();
	cout << playersName << " wins with a higher hand!!!" << endl;
	system("pause");
    }
}
