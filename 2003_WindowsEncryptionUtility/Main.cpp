//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "cryptClass.h"
#include "Register.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"

TfrmMain *frmMain;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	Timer1->Enabled = (true);			  // Enables the 1st timer to start
	miscTimer1->Enabled = (true);   // Enables the 2nd timer to start
	imgUnlocked->Visible = (true);  // Displays the unLocked lock images
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer1Timer(TObject *Sender)
{
    // Shows the date on the lower left side of the screen panel->item[0];
		frmMain->StatusBar1->Panels->Items[0]->Text = (DateToStr(Date()));

		// Shows the time on the lower left side of the screen panel->item[1];
		frmMain->StatusBar1->Panels->Items[1]->Text = (TimeToStr(Time()));


}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BitBtn4Click(TObject *Sender)
{
	if(Application->MessageBoxA("Are you sure you want to exit?",
		 "Exiting Application", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1)==IDYES)
	{
		Application->Terminate();
	}
	else{
		activeText->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BitBtn1Click(TObject *Sender)
{
	if(activeText->Text.Length()== (0)){
		Application->MessageBoxA("Please type in a message to encrypt", "Nothing to encrypt!", MB_OK);
		activeText->SetFocus();
		return;
	}
	if(activeText->Text.Length()>(0) && passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot encrypt because the fields are not blank!", "Cannot encrypt!", MB_OK);
		return;
	}
	if(passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot encrypt because the fields are not blank!", "Cannot encrypt!", MB_OK);
		return;
	}
	AnsiString theMessage = (activeText->Text);

	cryptIt* method = new cryptIt;
	method->encryptIt(theMessage.c_str());
	passiveText->Text = theMessage.c_str();

	delete method;

	imgLocked->Visible = true;
	imgUnlocked->Visible = false;

	passiveText->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::BitBtn2Click(TObject *Sender)
{
	if(activeText->Text.Length()== (0)){
		Application->MessageBoxA("Please type in a message to decrypt", "Nothing to decrypt!", MB_OK);
		activeText->SetFocus();
		return;
	}
	if(activeText->Text.Length()>(0) && passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot decrypt because the fields are not blank!", "Cannot decrypt!", MB_OK);
		return;
	}
	if(passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot encrypt because the fields are not blank!", "Cannot encrypt!", MB_OK);
		return;
	}
	AnsiString theMessage = (activeText->Text);

	cryptIt* method = new cryptIt;
	method->decryptIt(theMessage.c_str());
	passiveText->Text = theMessage.c_str();

	delete method;

	imgUnlocked->Visible = true;
	imgLocked->Visible = false;

	passiveText->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BitBtn3Click(TObject *Sender)
{
	activeText->Text = "";
	passiveText->Text = "";
	activeText->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Label1MouseMove(TObject *Sender,
			TShiftState Shift, int X, int Y)
{
			Label1->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormMouseMove(TObject *Sender, TShiftState Shift,
			int X, int Y)
{
	Label1->Font->Color = clTeal;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::activeTextMouseMove(TObject *Sender,
			TShiftState Shift, int X, int Y)
{
	Label1->Font->Color = clTeal;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::passiveTextMouseMove(TObject *Sender,
			TShiftState Shift, int X, int Y)
{
		Label1->Font->Color = clTeal;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Label1Click(TObject *Sender)
{
	activeText->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::miscTimer1Timer(TObject *Sender)
{
	if(activeText->Focused()){
		activeText->Color = clYellow;
	}
	else if(!activeText->Focused()){
		activeText->Color = clWhite;
	}

	if(passiveText->Focused()){
		passiveText->Color = clYellow;
	}
	else if(!passiveText->Focused()){
		passiveText->Color = clWhite;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Exit1Click(TObject *Sender)
{
	if(Application->MessageBoxA("Are you sure you want to exit?",
		 "Exiting Application", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1)==IDYES)
	{
		Application->Terminate();
	}
	else{
		activeText->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Encrypt1Click(TObject *Sender)
{
	if(activeText->Text.Length()== (0)){
		Application->MessageBoxA("Please type in a message to encrypt", "Nothing to encrypt!", MB_OK);
		activeText->SetFocus();
		return;
	}
	if(activeText->Text.Length()>(0) && passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot encrypt because the fields are not blank!", "Cannot encrypt!", MB_OK);
		return;
	}
	if(passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot encrypt because the fields are not blank!", "Cannot encrypt!", MB_OK);
		return;
	}
	AnsiString theMessage = (activeText->Text);

	cryptIt* method = new cryptIt;
	method->encryptIt(theMessage.c_str());
	passiveText->Text = theMessage.c_str();

	delete method;

	imgLocked->Visible = true;
	imgUnlocked->Visible = false;

	passiveText->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Decrypt1Click(TObject *Sender)
{
	if(activeText->Text.Length()== (0)){
		Application->MessageBoxA("Please type in a message to decrypt", "Nothing to decrypt!", MB_OK);
		activeText->SetFocus();
		return;
	}
	if(activeText->Text.Length()>(0) && passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot decrypt because the fields are not blank!", "Cannot decrypt!", MB_OK);
		return;
	}
	if(passiveText->Text.Length()>(0)){
		Application->MessageBoxA("You cannot encrypt because the fields are not blank!", "Cannot encrypt!", MB_OK);
		return;
	}
	AnsiString theMessage = (activeText->Text);

	cryptIt* method = new cryptIt;
	method->decryptIt(theMessage.c_str());
	passiveText->Text = theMessage.c_str();

	delete method;

	imgUnlocked->Visible = true;
	imgLocked->Visible = false;

	passiveText->SetFocus();
}
void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();	
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::About1Click(TObject *Sender)
{
        Application->MessageBoxA( "Written by Armond Sarkisian", "About", MB_OK);      
}
//---------------------------------------------------------------------------

