#include "Main.h"
#include "GameConstants.h"

extern TfrmMain *frmMain;	//From main.cpp

void __fastcall TfrmMain::levelThemes(){

if(currentLevel >= STAGE1FIRST && currentLevel <= STAGE1LAST)
	myBackground->Picture->LoadFromFile(STAGE1);
else if(currentLevel >= STAGE2FIRST && currentLevel <= STAGE2LAST)
	myBackground->Picture->LoadFromFile(STAGE2);
else if(currentLevel >= STAGE3FIRST && currentLevel <= STAGE3LAST)
	myBackground->Picture->LoadFromFile(STAGE3);
else if(currentLevel >= STAGE4FIRST && currentLevel <= STAGE4LAST)
	myBackground->Picture->LoadFromFile(STAGE4);
else if(currentLevel >= STAGE5FIRST && currentLevel <= STAGE5LAST)
	myBackground->Picture->LoadFromFile(STAGE5);
else if(currentLevel >= STAGE6FIRST && currentLevel <= STAGE5LAST)
	myBackground->Picture->LoadFromFile(STAGE6);
else if(currentLevel >= STAGE7FIRST && currentLevel <= STAGE7LAST)
	myBackground->Picture->LoadFromFile(STAGE7);
else if(currentLevel >= STAGE8FIRST && currentLevel <= STAGE8LAST)
	myBackground->Picture->LoadFromFile(STAGE8);
else if(currentLevel >= STAGE9FIRST && currentLevel <= STAGE9LAST)
	myBackground->Picture->LoadFromFile(STAGE9);
else if(currentLevel >= STAGE10FIRST && currentLevel <= STAGE10LAST)
	myBackground->Picture->LoadFromFile(STAGE10);
else if(currentLevel >= STAGE11FIRST && currentLevel <= STAGE11LAST)
	myBackground->Picture->LoadFromFile(STAGE11);
else if(currentLevel >= STAGE12FIRST && currentLevel <= STAGE12LAST)
	myBackground->Picture->LoadFromFile(STAGE12);
else if(currentLevel >= STAGE13FIRST && currentLevel <= STAGE13LAST)
	myBackground->Picture->LoadFromFile(STAGE13);
else if(currentLevel >= STAGE14FIRST && currentLevel <= STAGE14LAST)
	myBackground->Picture->LoadFromFile(STAGE14);
else if(currentLevel >= STAGE15FIRST && currentLevel <= STAGE15LAST)
	myBackground->Picture->LoadFromFile(STAGE15);
else if(currentLevel >= STAGE16FIRST && currentLevel <= STAGE16LAST)
	myBackground->Picture->LoadFromFile(STAGE16);
else if(currentLevel >= STAGE17FIRST && currentLevel <= STAGE17LAST)
	myBackground->Picture->LoadFromFile(STAGE17);
}
