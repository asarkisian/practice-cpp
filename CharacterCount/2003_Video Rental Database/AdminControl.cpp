//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AdminControl.h"
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAdminControl *frmAdminControl;
//---------------------------------------------------------------------------
__fastcall TfrmAdminControl::TfrmAdminControl(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TfrmAdminControl::cmdClearClick(TObject *Sender)
{
/*
    if(MessageBox(NULL, "Are you sure you want to clear ALL fields?", "Start Over?", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2)==IDYES){
                txtComments->Clear();
                txtIsTheMovieRented->Clear();
                txtIsTheMovieRented->Clear();
                txtLanguage->Clear();
                txtMovieArtist->Clear();
                txtMovieDirector->Clear();
                txtMovieFormat->Clear();
                txtMovieLength->Clear();
                txtMovieName->Clear();
                txtMovieReleaseDate->Clear();
                txtParentalRating->Clear();
                txtRentalPrice->Clear();
                txtSalesPrice->Clear();
                txtScreenSize->Clear();
                txtUserRating->Clear();
                txtMovieName->SetFocus();
        }
*/
}
//---------------------------------------------------------------------------

void __fastcall TfrmAdminControl::cmdLogoffClick(TObject *Sender)
{
     if(MessageBox(NULL, "Are you sure you want to log off?", "Logging off", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2)==IDYES){
                frmLogin->Show();
                frmLogin->txtAccount->SetFocus();
                frmAdminControl->Hide();
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmAdminControl::cmbPositionChange(TObject *Sender)
{
         txtPosition->Text = cmbPosition->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAdminControl::dtpHireDateTempChange(TObject *Sender)
{
        txtHireDate->Text = (AnsiString) dtpHireDateTemp->Date;
}
//---------------------------------------------------------------------------


void __fastcall TfrmAdminControl::txtIsAdminChange(TObject *Sender)
{
        if(txtIsAdmin->Text == "YES"){
                txtAdminCode->Enabled = true;
                txtAdminCode->Cursor = crIBeam;
        }
        else{
                txtAdminCode->Enabled = false;
                txtAdminCode->Cursor = crNoDrop;
                txtAdminCode->Text = "";
        }
}
//---------------------------------------------------------------------------
void __fastcall TfrmAdminControl::tmrAdminControlTimer(TObject *Sender)
{
        if(txtSocialSecurity->Focused()) txtSocialSecurity->Color = clYellow;
        else txtSocialSecurity->Color = clWhite;
        if(txtFullName->Focused()) txtFullName->Color = clYellow;
        else txtFullName->Color = clWhite;
        if(txtStreetAddress->Focused()) txtStreetAddress->Color = clYellow;
        else txtStreetAddress->Color = clWhite;
        if(txtCity->Focused()) txtCity->Color = clYellow;
        else txtCity->Color = clWhite;
        if(txtState->Focused()) txtState->Color = clYellow;
        else txtState->Color = clWhite;
        if(txtZipCode->Focused()) txtZipCode->Color = clYellow;
        else txtZipCode->Color = clWhite;
        if(txtHomePhone->Focused()) txtHomePhone->Color = clYellow;
        else txtHomePhone->Color = clWhite;
        if(txtMobilePhone->Focused()) txtMobilePhone->Color = clYellow;
        else txtMobilePhone->Color = clWhite;
        if(txtUserLogin->Focused()) txtUserLogin->Color = clYellow;
        else txtUserLogin->Color = clWhite;
        if(txtPassword->Focused()) txtPassword->Color = clYellow;
        else txtPassword->Color = clWhite;
        if(txtIsAdmin->Focused()) txtIsAdmin->Color = clYellow;
        else txtIsAdmin->Color = clWhite;
        if(txtAdminCode->Focused()) txtAdminCode->Color = clYellow;
        else txtAdminCode->Color = clWhite;
        if(txtComments->Focused()) txtComments->Color = clYellow;
        else txtComments->Color = clWhite;
        if(txtWarnings->Focused()) txtWarnings->Color = clYellow;
        else txtWarnings->Color = clWhite;
}
//---------------------------------------------------------------------------

