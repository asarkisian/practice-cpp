//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TfrmAbout *frmAbout;
//--------------------------------------------------------------------- 
__fastcall TfrmAbout::TfrmAbout(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TfrmAbout::OKButtonClick(TObject *Sender)
{
	frmAbout->Close();
}
//---------------------------------------------------------------------------

