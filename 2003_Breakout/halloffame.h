#ifndef HALLOFFAME_H
#define HALLOFFAME_H

#include <string>
using namespace std;

//This is for the input top scores players name
#include "Main.h"
#include "GameConstants.h"
#include "TopScoresGetName.h"
#include "HallOfFameInterface.h"

class hallOfFame{
	public:
		hallOfFame();	//To Initialize the radio variables
		~hallOfFame();

		//Puts the players name on the board
		void __fastcall processInput();

		//Initializes the list
		void __fastcall initializeList();

		//Checks the score to see if the players name will go up on the board
		bool __fastcall checkScores(int playersScore)const;

		//Determines which record must be updated
		void __fastcall updateFile(short int player)const;

		//Routine which writes to the disk
		void __fastcall writeDisk()const;

		//Routine which imports data from the disk
		void __fastcall importDisk()const;

		//Stores the players name temporarily
		AnsiString tempName;
		 
	private:

	  //Radio variables to see which ranking the player will fall into
		mutable bool onePlace;
		mutable bool twoPlace;
		mutable bool threePlace;
		mutable bool fourPlace;
		mutable bool fivePlace;
		mutable bool sixPlace;
		mutable bool sevenPlace;
		mutable bool eightPlace;
		mutable bool ninePlace;
		mutable bool tenPlace;

		//This is where all the actual data "players name and score" gets copied into
		AnsiString playerOne[2];
		AnsiString playerTwo[2];
		AnsiString playerThree[2];
		AnsiString playerFour[2];
		AnsiString playerFive[2];
		AnsiString playerSix[2];
		AnsiString playerSeven[2];
		AnsiString playerEight[2];
		AnsiString playerNine[2];
		AnsiString playerTen[2];
};

 //Global object "theRecords" so all of main could see it. the real one is declared
 //in hallOfFame.cpp
 extern hallOfFame theRecords;

#endif
