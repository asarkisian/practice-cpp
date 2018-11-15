//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HallOfFameInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHallOfFame *frmHallOfFame;
//---------------------------------------------------------------------------
__fastcall TfrmHallOfFame::TfrmHallOfFame(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmHallOfFame::SpeedButton1Click(TObject *Sender)
{
	frmHallOfFame->Close();	
}
//---------------------------------------------------------------------------
