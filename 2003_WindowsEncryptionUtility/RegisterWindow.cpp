//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
using namespace std;

#pragma hdrstop

#include "RegisterWindow.h"
#include "Register.h"
#include "Main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmRegistration *frmRegistration;
registerSoftware methodRegister;
extern TfrmMain *frmMain;

//---------------------------------------------------------------------------
__fastcall TfrmRegistration::TfrmRegistration(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistration::BitBtn1Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegistration::BitBtn3Click(TObject *Sender)
{
	 methodRegister.registerComplete();
	 methodRegister.outputRegister();

	Application->MessageBoxA("Thank you for registering Drago Cryption Utility 2.0!", "Registration Successfull", MB_OK | MB_DEFBUTTON1);
	frmMain->Show();
	frmRegistration->Hide();
}
//---------------------------------------------------------------------------

}
//---------------------------------------------------------------------------

