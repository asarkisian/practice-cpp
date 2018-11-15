#include <io.h>
#include "halloffame.h"

hallOfFame theRecords;

hallOfFame::hallOfFame():

		//Radio Variables to determine which place the user will fit in the top scores list
    //Reseting all radio variables to FALSE
		onePlace(false),
		twoPlace(false),
		threePlace(false),
		fourPlace(false),
		fivePlace(false),
		sixPlace(false),
		sevenPlace(false),
		eightPlace(false),
		ninePlace(false),
		tenPlace(false){

	//Initializing of the playerHallOfFame properties
	for(int index(0);index<(2);++index){
			playerOne[index] = "";
			playerTwo[index]= "";
			playerThree[index]= "";
			playerFour[index]= "";
			playerFive[index]= "";
			playerSix[index]= "";
			playerSeven[index]= "";
			playerEight[index]= "";
			playerNine[index]= "";
			playerTen[index] = "";
	}
}

hallOfFame::~hallOfFame(){}

void __fastcall hallOfFame::processInput(){

 inputTopScoresPlayersName->ShowModal();

 if(tenPlace == true && ninePlace == false && eightPlace == false && sevenPlace == false
 && sixPlace == false && fivePlace == false && fourPlace == false && threePlace == false
 && twoPlace == false && onePlace == false){

	theRecords.playerTen[0] = theRecords.tempName;

 //Retrieve players score
	theRecords.playerTen[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == true && eightPlace == false && sevenPlace == false
 && sixPlace == false && fivePlace == false && fourPlace == false && threePlace == false
 && twoPlace == false && onePlace == false){

	theRecords.playerTen[0] = theRecords.playerNine[0];

	theRecords.playerTen[1] = theRecords.playerNine[1];

	theRecords.playerNine[0] = theRecords.tempName;
	theRecords.playerNine[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == true && sevenPlace == false
 && sixPlace == false && fivePlace == false && fourPlace == false && threePlace == false
 && twoPlace == false && onePlace == false){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];

	theRecords.playerEight[0] = theRecords.tempName;
	theRecords.playerEight[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == false && sevenPlace == true
 && sixPlace == false && fivePlace == false && fourPlace == false && threePlace == false
 && twoPlace == false && onePlace == false){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];
 theRecords.playerEight[0] = theRecords.playerSeven[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];
 theRecords.playerEight[1] = theRecords.playerSeven[1];

	theRecords.playerSeven[0] = theRecords.tempName;
	theRecords.playerSeven[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == false && sevenPlace == false
 && sixPlace == true && fivePlace == false && fourPlace == false && threePlace == false
 && twoPlace == false && onePlace == false){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];
 theRecords.playerEight[0] = theRecords.playerSeven[0];
 theRecords.playerSeven[0] = theRecords.playerSix[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];
 theRecords.playerEight[1] = theRecords.playerSeven[1];
 theRecords.playerSeven[1] = theRecords.playerSix[1];

	theRecords.playerSix[0] = theRecords.tempName;
	theRecords.playerSix[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == false && sevenPlace == false
 && sixPlace == false && fivePlace == true && fourPlace == false && threePlace == false
 && twoPlace == false && onePlace == false){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];
 theRecords.playerEight[0] = theRecords.playerSeven[0];
 theRecords.playerSeven[0] = theRecords.playerSix[0];
 theRecords.playerSix[0] = theRecords.playerFive[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];
 theRecords.playerEight[1] = theRecords.playerSeven[1];
 theRecords.playerSeven[1] = theRecords.playerSix[1];
 theRecords.playerSix[1] = theRecords.playerFive[1];

	theRecords.playerFive[0] = theRecords.tempName;
	theRecords.playerFive[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == false && sevenPlace == false
 && sixPlace == false && fivePlace == false && fourPlace == true && threePlace == false
 && twoPlace == false && onePlace == false){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];
 theRecords.playerEight[0] = theRecords.playerSeven[0];
 theRecords.playerSeven[0] = theRecords.playerSix[0];
 theRecords.playerSix[0] = theRecords.playerFive[0];
 theRecords.playerFive[0] = theRecords.playerFour[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];
 theRecords.playerEight[1] = theRecords.playerSeven[1];
 theRecords.playerSeven[1] = theRecords.playerSix[1];
 theRecords.playerSix[1] = theRecords.playerFive[1];
 theRecords.playerFive[1] = theRecords.playerFour[1];

	theRecords.playerFour[0] = theRecords.tempName;
	theRecords.playerFour[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == false && sevenPlace == false
 && sixPlace == false && fivePlace == false && fourPlace == false && threePlace == true
 && twoPlace == false && onePlace == false){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];
 theRecords.playerEight[0] = theRecords.playerSeven[0];
 theRecords.playerSeven[0] = theRecords.playerSix[0];
 theRecords.playerSix[0] = theRecords.playerFive[0];
 theRecords.playerFive[0] = theRecords.playerFour[0];
 theRecords.playerFour[0] = theRecords.playerThree[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];
 theRecords.playerEight[1] = theRecords.playerSeven[1];
 theRecords.playerSeven[1] = theRecords.playerSix[1];
 theRecords.playerSix[1] = theRecords.playerFive[1];
 theRecords.playerFive[1] = theRecords.playerFour[1];
 theRecords.playerFour[1] = theRecords.playerThree[1];

	theRecords.playerThree[0] = theRecords.tempName;
	theRecords.playerThree[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == false && sevenPlace == false
 && sixPlace == false && fivePlace == false && fourPlace == false && threePlace == false
 && twoPlace == true && onePlace == false){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];
 theRecords.playerEight[0] = theRecords.playerSeven[0];
 theRecords.playerSeven[0] = theRecords.playerSix[0];
 theRecords.playerSix[0] = theRecords.playerFive[0];
 theRecords.playerFive[0] = theRecords.playerFour[0];
 theRecords.playerFour[0] = theRecords.playerThree[0];
 theRecords.playerThree[0] = theRecords.playerTwo[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];
 theRecords.playerEight[1] = theRecords.playerSeven[1];
 theRecords.playerSeven[1] = theRecords.playerSix[1];
 theRecords.playerSix[1] = theRecords.playerFive[1];
 theRecords.playerFive[1] = theRecords.playerFour[1];
 theRecords.playerFour[1] = theRecords.playerThree[1];
 theRecords.playerThree[1] = theRecords.playerTwo[1];

	theRecords.playerTwo[0] = theRecords.tempName;
	theRecords.playerTwo[1] = IntToStr(frmMain->playersScore);
 }
else if(tenPlace == false && ninePlace == false && eightPlace == false && sevenPlace == false
 && sixPlace == false && fivePlace == false && fourPlace == false && threePlace == false
 && twoPlace == false && onePlace == true){

 theRecords.playerTen[0] = theRecords.playerNine[0];
 theRecords.playerNine[0] = theRecords.playerEight[0];
 theRecords.playerEight[0] = theRecords.playerSeven[0];
 theRecords.playerSeven[0] = theRecords.playerSix[0];
 theRecords.playerSix[0] = theRecords.playerFive[0];
 theRecords.playerFive[0] = theRecords.playerFour[0];
 theRecords.playerFour[0] = theRecords.playerThree[0];
 theRecords.playerThree[0] = theRecords.playerTwo[0];
 theRecords.playerTwo[0] = theRecords.playerOne[0];

 theRecords.playerTen[1] = theRecords.playerNine[1];
 theRecords.playerNine[1] = theRecords.playerEight[1];
 theRecords.playerEight[1] = theRecords.playerSeven[1];
 theRecords.playerSeven[1] = theRecords.playerSix[1];
 theRecords.playerSix[1] = theRecords.playerFive[1];
 theRecords.playerFive[1] = theRecords.playerFour[1];
 theRecords.playerFour[1] = theRecords.playerThree[1];
 theRecords.playerThree[1] = theRecords.playerTwo[1];
 theRecords.playerTwo[1] = theRecords.playerOne[1];

	theRecords.playerOne[0] = theRecords.tempName;
	theRecords.playerOne[1] = IntToStr(frmMain->playersScore);
}

		 //Sends a message to updateFile() so it will know which file to update
		 if(onePlace == true) updateFile(FIRST_PLACE);
		 else if(twoPlace == true) updateFile(SECOND_PLACE);
		 else if(threePlace == true) updateFile(THIRD_PLACE);
		 else if(fourPlace == true) updateFile(FOURTH_PLACE);
		 else if(fivePlace == true) updateFile(FIFTH_PLACE);
		 else if(sixPlace == true) updateFile(SIXTH_PLACE);
		 else if(sevenPlace == true) updateFile(SEVENTH_PLACE);
		 else if(eightPlace == true) updateFile(EIGHT_PLACE);
		 else if(ninePlace == true) updateFile(NINTH_PLACE);
		 else if(tenPlace == true) updateFile(TENTH_PLACE);
}

void __fastcall hallOfFame::initializeList(){

	//The file (gamelog.dat) IS in existence
	if(!access(FILE_NAME, 0)){

    //Get the records from the disk file (FILE_NAME)
		theRecords.importDisk();

		//Update ALL records and display them
		theRecords.updateFile(1);
	}
	//If the (FILE_NAME) IS NOT in existence
	else{

				//Initializing of the playerHallOfFame properties
				//Copy the default players names
				playerOne[0] = DEFAULT_PLAYERONE_NAME;
				playerTwo[0]= DEFAULT_PLAYERTWO_NAME;
				playerThree[0]= DEFAULT_PLAYERTHREE_NAME;
				playerFour[0]= DEFAULT_PLAYERFOUR_NAME;
				playerFive[0]= DEFAULT_PLAYERFIVE_NAME;
				playerSix[0]= DEFAULT_PLAYERSIX_NAME;
				playerSeven[0]= DEFAULT_PLAYERSEVEN_NAME;
				playerEight[0]= DEFAULT_PLAYEREIGHT_NAME;
				playerNine[0]= DEFAULT_PLAYERNINE_NAME;
				playerTen[0]= DEFAULT_PLAYERTEN_NAME;

				//Copy the default players scores
				playerOne[1] = DEFAULT_PLAYERONE_SCORE;
				playerTwo[1]= DEFAULT_PLAYERTWO_SCORE;
				playerThree[1] = DEFAULT_PLAYERTHREE_SCORE;
				playerFour[1]= DEFAULT_PLAYERFOUR_SCORE;
				playerFive[1]= DEFAULT_PLAYERFIVE_SCORE;
				playerSix[1]= DEFAULT_PLAYERSIX_SCORE;
				playerSeven[1]= DEFAULT_PLAYERSEVEN_SCORE;
				playerEight[1]= DEFAULT_PLAYEREIGHT_SCORE;
				playerNine[1]= DEFAULT_PLAYERNINE_SCORE;
				playerTen[1]= DEFAULT_PLAYERTEN_SCORE;

	//Update the window so people can see the scores.
	frmHallOfFame->List1->Caption = theRecords.playerOne[0];
	frmHallOfFame->List11->Caption = theRecords.playerOne[1];
	frmHallOfFame->List2->Caption = theRecords.playerTwo[0];
	frmHallOfFame->List12->Caption = theRecords.playerTwo[1];
	frmHallOfFame->List3->Caption = theRecords.playerThree[0];
	frmHallOfFame->List13->Caption = theRecords.playerThree[1];
	frmHallOfFame->List4->Caption = theRecords.playerFour[0];
	frmHallOfFame->List14->Caption = theRecords.playerFour[1];
	frmHallOfFame->List5->Caption = theRecords.playerFive[0];
	frmHallOfFame->List15->Caption = theRecords.playerFive[1];
	frmHallOfFame->List6->Caption = theRecords.playerSix[0];
	frmHallOfFame->List16->Caption = theRecords.playerSix[1];
	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];
	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];
	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];
	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];

    //Update the file with the scores (default scores that is)
		theRecords.writeDisk();
	}
}

bool __fastcall hallOfFame::checkScores(int playersScore)const{

 //This var determines whether or not the player will go up on the top scores or not
 bool passFlag = false;

  //AnsiString to Int. Copy the scores to an int file to test the scores
	int tempPlayerOne = StrToInt(theRecords.playerOne[1]);
	int tempPlayerTwo = StrToInt(theRecords.playerTwo[1]);
	int tempPlayerThree = StrToInt(theRecords.playerThree[1]);
	int tempPlayerFour = StrToInt(theRecords.playerFour[1]);
	int tempPlayerFive = StrToInt(theRecords.playerFive[1]);
	int tempPlayerSix = StrToInt(theRecords.playerSix[1]);
	int tempPlayerSeven = StrToInt(theRecords.playerSeven[1]);
	int tempPlayerEight = StrToInt(theRecords.playerEight[1]);
	int tempPlayerNine = StrToInt(theRecords.playerNine[1]);
	int tempPlayerTen = StrToInt(theRecords.playerTen[1]);

 //Radio variables to see which ranking the player goes into. IF FALSE then none
 //if passFlag == true then the player goes up on the top scores list
 if((playersScore >= tempPlayerTen) && (playersScore < tempPlayerNine)){
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = true;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
 else if((playersScore >= tempPlayerNine) && (playersScore < tempPlayerEight)){
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = true;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if((playersScore >= tempPlayerEight) && (playersScore < tempPlayerSeven)){
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = true;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if((playersScore >= tempPlayerSeven) && (playersScore < tempPlayerSix)){
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = true;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if((playersScore >= tempPlayerSix) && (playersScore < tempPlayerFive)){
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = true;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if((playersScore >= tempPlayerFive) && (playersScore < tempPlayerFour)){
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = true;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if((playersScore >= tempPlayerFour) && (playersScore < tempPlayerThree)){
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = true;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if((playersScore >= tempPlayerThree) && (playersScore < tempPlayerTwo)){
		onePlace = false;
		twoPlace = false;
		threePlace = true;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if((playersScore >= tempPlayerTwo) && (playersScore < tempPlayerOne)){
		onePlace = false;
		twoPlace = true;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
 }
else if(playersScore >= tempPlayerOne){
		onePlace = true;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will go up on the top scores list because passFlag = true
		passFlag = true;
}
else{
		onePlace = false;
		twoPlace = false;
		threePlace = false;
		fourPlace = false;
		fivePlace = false;
		sixPlace = false;
		sevenPlace = false;
		eightPlace = false;
		ninePlace = false;
		tenPlace = false;

		//Player will NOT up on the top scores list because passFlag = false
		//If passFlag == false then the user didn't get a high enough score to be on the top scores list
		passFlag = false;
}

 //if passFlag == true then the player goes up on the board
 if(passFlag == true) return true;

 //If user did not get a high enough score, false out of this and not be posted
 return false;
}

void __fastcall hallOfFame::updateFile(short int player)const{

 //Update the board with the specific name\score and update the file

 //Player is good enough to be listed 1st place
 if(player == FIRST_PLACE){
	frmHallOfFame->List1->Caption = theRecords.playerOne[0];
	frmHallOfFame->List11->Caption = theRecords.playerOne[1];

	frmHallOfFame->List2->Caption = theRecords.playerTwo[0];
	frmHallOfFame->List12->Caption = theRecords.playerTwo[1];

	frmHallOfFame->List3->Caption = theRecords.playerThree[0];
	frmHallOfFame->List13->Caption = theRecords.playerThree[1];

	frmHallOfFame->List4->Caption = theRecords.playerFour[0];
	frmHallOfFame->List14->Caption = theRecords.playerFour[1];

	frmHallOfFame->List5->Caption = theRecords.playerFive[0];
	frmHallOfFame->List15->Caption = theRecords.playerFive[1];

	frmHallOfFame->List6->Caption = theRecords.playerSix[0];
	frmHallOfFame->List16->Caption = theRecords.playerSix[1];

	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];

	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 2nd place
 else if(player == SECOND_PLACE){
	frmHallOfFame->List2->Caption = theRecords.playerTwo[0];
	frmHallOfFame->List12->Caption = theRecords.playerTwo[1];

	frmHallOfFame->List3->Caption = theRecords.playerThree[0];
	frmHallOfFame->List13->Caption = theRecords.playerThree[1];

	frmHallOfFame->List4->Caption = theRecords.playerFour[0];
	frmHallOfFame->List14->Caption = theRecords.playerFour[1];

	frmHallOfFame->List5->Caption = theRecords.playerFive[0];
	frmHallOfFame->List15->Caption = theRecords.playerFive[1];

	frmHallOfFame->List6->Caption = theRecords.playerSix[0];
	frmHallOfFame->List16->Caption = theRecords.playerSix[1];

	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];

	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 3rd place
 else if(player == THIRD_PLACE){
	frmHallOfFame->List3->Caption = theRecords.playerThree[0];
	frmHallOfFame->List13->Caption = theRecords.playerThree[1];

	frmHallOfFame->List4->Caption = theRecords.playerFour[0];
	frmHallOfFame->List14->Caption = theRecords.playerFour[1];

	frmHallOfFame->List5->Caption = theRecords.playerFive[0];
	frmHallOfFame->List15->Caption = theRecords.playerFive[1];

	frmHallOfFame->List6->Caption = theRecords.playerSix[0];
	frmHallOfFame->List16->Caption = theRecords.playerSix[1];

	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];

	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 4th place
 else if(player == FOURTH_PLACE){
	frmHallOfFame->List4->Caption = theRecords.playerFour[0];
	frmHallOfFame->List14->Caption = theRecords.playerFour[1];

	frmHallOfFame->List5->Caption = theRecords.playerFive[0];
	frmHallOfFame->List15->Caption = theRecords.playerFive[1];

	frmHallOfFame->List6->Caption = theRecords.playerSix[0];
	frmHallOfFame->List16->Caption = theRecords.playerSix[1];

	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];

	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 5th place
 else if(player == FIFTH_PLACE){
	frmHallOfFame->List5->Caption = theRecords.playerFive[0];
	frmHallOfFame->List15->Caption = theRecords.playerFive[1];

	frmHallOfFame->List6->Caption = theRecords.playerSix[0];
	frmHallOfFame->List16->Caption = theRecords.playerSix[1];

	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];

	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 6th place
 else if(player == SIXTH_PLACE){
	frmHallOfFame->List6->Caption = theRecords.playerSix[0];
	frmHallOfFame->List16->Caption = theRecords.playerSix[1];

	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];

	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 7th place
 else if(player == SEVENTH_PLACE){
	frmHallOfFame->List7->Caption = theRecords.playerSeven[0];
	frmHallOfFame->List17->Caption = theRecords.playerSeven[1];

	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 8th place
 else if(player == EIGHT_PLACE){
	frmHallOfFame->List8->Caption = theRecords.playerEight[0];
	frmHallOfFame->List18->Caption = theRecords.playerEight[1];

	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 9th place
 else if(player == NINTH_PLACE){
	frmHallOfFame->List9->Caption = theRecords.playerNine[0];
	frmHallOfFame->List19->Caption = theRecords.playerNine[1];

	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }
 //Player is good enough to be listed 10th place
 else if(player == TENTH_PLACE){
	frmHallOfFame->List10->Caption = theRecords.playerTen[0];
	frmHallOfFame->List20->Caption = theRecords.playerTen[1];
 }

 //Update the disk file with the new top scores records
 writeDisk();
}
