#include "Main.h"
#include "GameConstants.h"

extern TfrmMain *frmMain;	//From main.cpp

void __fastcall TfrmMain::themePaddleColor(){

//determining which paddleColor to use with the theme
if(currentLevel >= STAGE1FIRST && currentLevel <= STAGE1LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE1_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE1_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE1_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE1_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE1_COLOR;
}
else if(currentLevel >= STAGE2FIRST && currentLevel <= STAGE2LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE2_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE2_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE2_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE2_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE2_COLOR;
}
else if(currentLevel >= STAGE3FIRST && currentLevel <= STAGE3LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE3_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE3_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE3_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE3_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE3_COLOR;
}
else if(currentLevel >= STAGE4FIRST && currentLevel <= STAGE4LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE4_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE4_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE4_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE4_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE4_COLOR;
}
else if(currentLevel >= STAGE5FIRST && currentLevel <= STAGE5LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE5_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE5_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE5_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE5_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE5_COLOR;
}
else if(currentLevel >= STAGE6FIRST && currentLevel <= STAGE5LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE6_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE6_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE6_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE6_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE6_COLOR;
}
else if(currentLevel >= STAGE7FIRST && currentLevel <= STAGE7LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE7_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE7_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE7_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE7_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE7_COLOR;
}
else if(currentLevel >= STAGE8FIRST && currentLevel <= STAGE8LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE8_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE8_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE8_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE8_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE8_COLOR;
}
else if(currentLevel >= STAGE9FIRST && currentLevel <= STAGE9LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE9_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE9_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE9_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE9_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE9_COLOR;
}
else if(currentLevel >= STAGE10FIRST && currentLevel <= STAGE10LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE10_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE10_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE10_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE10_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE10_COLOR;
}
else if(currentLevel >= STAGE11FIRST && currentLevel <= STAGE11LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE11_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE11_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE11_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE11_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE11_COLOR;
}
else if(currentLevel >= STAGE12FIRST && currentLevel <= STAGE12LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE12_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE12_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE12_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE12_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE12_COLOR;
}
else if(currentLevel >= STAGE13FIRST && currentLevel <= STAGE13LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE13_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE13_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE13_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE13_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE13_COLOR;
}
else if(currentLevel >= STAGE14FIRST && currentLevel <= STAGE14LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE14_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE14_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE14_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE14_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE14_COLOR;
}
else if(currentLevel >= STAGE15FIRST && currentLevel <= STAGE15LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE15_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE15_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE15_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE15_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE15_COLOR;
}
else if(currentLevel >= STAGE16FIRST && currentLevel <= STAGE16LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE16_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE16_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE16_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE16_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE16_COLOR;
}
else if(currentLevel >= STAGE17FIRST && currentLevel <= STAGE17LAST){
	frmMain->myPaddle->Brush->Color = PADDLE_STAGE17_COLOR;
	frmMain->myPaddle2->Brush->Color = PADDLE_STAGE17_COLOR;
	frmMain->myPaddle3->Brush->Color = PADDLE_STAGE17_COLOR;
	frmMain->myPaddle4->Brush->Color = PADDLE_STAGE17_COLOR;
	frmMain->myPaddle5->Brush->Color = PADDLE_STAGE17_COLOR;
}

}
