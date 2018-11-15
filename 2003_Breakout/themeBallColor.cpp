#include "Main.h"
#include "GameConstants.h"

extern TfrmMain *frmMain;	//From main.cpp

void __fastcall TfrmMain::themeBallColor(){

//determining which ballColor to use with the theme
if(currentLevel >= STAGE1FIRST && currentLevel <= STAGE1LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE1_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE1_COLOR_PEN;
}
else if(currentLevel >= STAGE2FIRST && currentLevel <= STAGE2LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE2_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE2_COLOR_PEN;
}
else if(currentLevel >= STAGE3FIRST && currentLevel <= STAGE3LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE3_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE3_COLOR_PEN;
}
else if(currentLevel >= STAGE4FIRST && currentLevel <= STAGE4LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE4_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE4_COLOR_PEN;
}
else if(currentLevel >= STAGE5FIRST && currentLevel <= STAGE5LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE5_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE5_COLOR_PEN;
}
else if(currentLevel >= STAGE6FIRST && currentLevel <= STAGE5LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE6_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE6_COLOR_PEN;
}
else if(currentLevel >= STAGE7FIRST && currentLevel <= STAGE7LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE7_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE7_COLOR_PEN;
}
else if(currentLevel >= STAGE8FIRST && currentLevel <= STAGE8LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE8_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE8_COLOR_PEN;
}
else if(currentLevel >= STAGE9FIRST && currentLevel <= STAGE9LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE9_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE9_COLOR_PEN;
}
else if(currentLevel >= STAGE10FIRST && currentLevel <= STAGE10LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE10_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE10_COLOR_PEN;
}
else if(currentLevel >= STAGE11FIRST && currentLevel <= STAGE11LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE11_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE11_COLOR_PEN;
}
else if(currentLevel >= STAGE12FIRST && currentLevel <= STAGE12LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE12_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE12_COLOR_PEN;
}
else if(currentLevel >= STAGE13FIRST && currentLevel <= STAGE13LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE13_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE13_COLOR_PEN;
}
else if(currentLevel >= STAGE14FIRST && currentLevel <= STAGE14LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE14_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE14_COLOR_PEN;
}
else if(currentLevel >= STAGE15FIRST && currentLevel <= STAGE15LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE15_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE15_COLOR_PEN;
}
else if(currentLevel >= STAGE16FIRST && currentLevel <= STAGE16LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE16_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE16_COLOR_PEN;
}
else if(currentLevel >= STAGE17FIRST && currentLevel <= STAGE17LAST){
	frmMain->myBall->Brush->Color = BALL_STAGE17_COLOR_BRUSH;
	frmMain->myBall->Pen->Color = BALL_STAGE17_COLOR_PEN;
}

}
