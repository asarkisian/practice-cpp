//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "GameConstants.h"
//---------------------------------------------------------------------------

extern TfrmMain *frmMain;

void __fastcall TfrmMain::gameEnd(){

	playerNewGame = false;
	playerWinGame = false;
	playerLoseGame = true;
	playerRestartGame = false;
	playerEndGame = true;

	for(int i(0);i<(BRICK_MAX);++i) myBall->Visible = false;

	//Setting up the values for the mainMenu options
	StartGame1->Enabled = true;
	EndGame1->Enabled = false;

	//Resetting all controls because end-user is aborting
	controlKey_up = false;
	controlKey_down = false;
	controlKey_left = false;
	controlKey_right = false;

	//Defaults back to zero because game has ended.
	amountOfBricksHit=(0);

	//Initiate the Game to End (stop game)
	gExit = true;
}
