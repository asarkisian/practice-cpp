#include "Main.h"
#include "GameConstants.h"

extern TfrmMain *frmMain;	//From main.cpp

//Randomize the color entries
randomize();

void __fastcall TfrmMain::determiningLevelColors(int i){

/* if(currentLevel == SPECIAL_LEVELONE
 || currentLevel == SPECIAL_LEVELTWO
 || currentLevel == SPECIAL_LEVELTHREE
 || currentLevel == SPECIAL_LEVELFOUR
 || currentLevel == SPECIAL_LEVELFIVE
 || currentLevel == SPECIAL_LEVELSIX
 || currentLevel == SPECIAL_LEVELSEVEN
 || currentLevel == SPECIAL_LEVELEIGHT
 || currentLevel == SPECIAL_LEVELNINE
 || currentLevel == SPECIAL_LEVELTEN
 || currentLevel == SPECIAL_LEVELELEVEN){

//			 Shape3[i]->Brush->Style = bsClear;
 }
 else{

	Shape3[i]->Brush->Color = (rand() % 19);
		if(Shape3[i]->Brush->Color == 0) Shape3[i]->Brush->Color = clRed;
		else if(Shape3[i]->Brush->Color == 1) Shape3[i]->Brush->Color = clLime;
		else if(Shape3[i]->Brush->Color == 2) Shape3[i]->Brush->Color = clBlue;
		else if(Shape3[i]->Brush->Color == 3) Shape3[i]->Brush->Color = clBlack;
		else if(Shape3[i]->Brush->Color == 4) Shape3[i]->Brush->Color = clGreen;
		else if(Shape3[i]->Brush->Color == 5) Shape3[i]->Brush->Color = clNavy;
		else if(Shape3[i]->Brush->Color == 6) Shape3[i]->Brush->Color = clTeal;
		else if(Shape3[i]->Brush->Color == 7) Shape3[i]->Brush->Color = clSilver;
		else if(Shape3[i]->Brush->Color == 8) Shape3[i]->Brush->Color = clAqua;
		else if(Shape3[i]->Brush->Color == 9) Shape3[i]->Brush->Color = clLime;
		else if(Shape3[i]->Brush->Color == 10) Shape3[i]->Brush->Color = clYellow;
		else if(Shape3[i]->Brush->Color == 11) Shape3[i]->Brush->Color = clPurple;
		else if(Shape3[i]->Brush->Color == 12) Shape3[i]->Brush->Color = clFuchsia;
		else if(Shape3[i]->Brush->Color == 13) Shape3[i]->Brush->Color = clMoneyGreen;
		else if(Shape3[i]->Brush->Color == 14) Shape3[i]->Brush->Color = clSkyBlue;
		else if(Shape3[i]->Brush->Color == 15) Shape3[i]->Brush->Color = clMedGray;
		else if(Shape3[i]->Brush->Color == 16) Shape3[i]->Brush->Color = clMaroon;
		else if(Shape3[i]->Brush->Color == 17) Shape3[i]->Brush->Color = clOlive;
		else if(Shape3[i]->Brush->Color == 18) Shape3[i]->Brush->Color = clGray;

//		Shape3[i]->Brush->Style = bsSolid;
 }
*/
}
