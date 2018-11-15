//---------------------------------------------------------------------------

#ifndef AdminControlH
#define AdminControlH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <CmAdmCtl.hpp>
#include <OleServer.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmAdminControl : public TForm
{
__published:	// IDE-managed Components
        TImage *imgYellow;
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TLabel *lblFullName;
        TLabel *lblEmployeeID;
        TLabel *lblStreetAddress;
        TLabel *lblCity;
        TLabel *lblState;
        TLabel *lblZipCode;
        TLabel *lblHomePhone;
        TLabel *lblMobilePhone;
        TDBEdit *txtEmployeeID;
        TDBEdit *txtStreetAddress;
        TDBEdit *txtCity;
        TDBEdit *txtState;
        TGroupBox *GroupBox2;
        TLabel *lblHireDate;
        TLabel *lblPosition;
        TGroupBox *GroupBox3;
        TDBMemo *txtComments;
        TGroupBox *GroupBox4;
        TLabel *lblAdminCode;
        TDBEdit *txtAdminCode;
        TLabel *lblUserLogin;
        TLabel *lblPassword;
        TDBEdit *txtPassword;
        TDBEdit *txtUserLogin;
        TGroupBox *GroupBox5;
        TDBMemo *txtWarnings;
        TLabel *lblSocialSecurity;
        TPanel *Panel2;
        TBitBtn *cmdClear;
        TBitBtn *cmdLogoff;
        TDBEdit *txtPosition;
        TComboBox *cmbPosition;
        TDBEdit *txtHireDate;
        TDateTimePicker *dtpHireDateTemp;
        TDBNavigator *DBNavigator1;
        TLabel *lblIsAdmin;
        TDBEdit *txtIsAdmin;
        TDBEdit *txtSocialSecurity;
        TDBEdit *txtHomePhone;
        TDBEdit *txtMobilePhone;
        TDBEdit *txtZipCode;
        TTimer *tmrAdminControl;
        TDBEdit *txtFullName;
        TADOConnection *ADOConnection1;
        TADOTable *ADOTable1;
        TDataSource *DataSource1;
        void __fastcall cmdClearClick(TObject *Sender);
        void __fastcall cmdLogoffClick(TObject *Sender);
        void __fastcall cmbPositionChange(TObject *Sender);
        void __fastcall dtpHireDateTempChange(TObject *Sender);
        void __fastcall txtIsAdminChange(TObject *Sender);
        void __fastcall tmrAdminControlTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmAdminControl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAdminControl *frmAdminControl;
//---------------------------------------------------------------------------
#endif
