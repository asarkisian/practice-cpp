//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PauseGameScreen.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGamePause *frmGamePause;
//---------------------------------------------------------------------------
__fastcall TfrmGamePause::TfrmGamePause(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmGamePause::FormKeyDown(TObject *Sender, WORD &Key,
			TShiftState Shift)
{
	if(Key == VK_F5) frmGamePause->Close();

}
//---------------------------------------------------------------------------

