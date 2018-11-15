#include "Main.h"
#include "GameConstants.h"

extern TfrmMain *frmMain;	//From main.cpp

//Randomize the rand() method
randomize();

void __fastcall TfrmMain::randomMenuColors(){

 int randomNumber = (rand() % 8);
 int* chosenColor = new int;

 if(randomNumber == 0) *chosenColor = clBlue;
 else if(randomNumber == 1) *chosenColor = clRed;
 else if(randomNumber == 2) *chosenColor = clLime;
 else if(randomNumber == 3) *chosenColor = clBlue;
 else if(randomNumber == 4) *chosenColor = clSkyBlue;
 else if(randomNumber == 5) *chosenColor = clYellow;
 else if(randomNumber == 6) *chosenColor = clWhite;
 else if(randomNumber == 7) *chosenColor = clRed;

	frmMain->numberOfCredits->Font->Color = *chosenColor;
	frmMain->numberOfLevel->Font->Color = *chosenColor;
	frmMain->numberOfMisses->Font->Color = *chosenColor;
	frmMain->numberOfScore->Font->Color = *chosenColor;

 delete chosenColor;	
}
 