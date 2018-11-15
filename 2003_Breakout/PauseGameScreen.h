//---------------------------------------------------------------------------

#ifndef PauseGameScreenH
#define PauseGameScreenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmGamePause : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmGamePause(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGamePause *frmGamePause;
//---------------------------------------------------------------------------
#endif
