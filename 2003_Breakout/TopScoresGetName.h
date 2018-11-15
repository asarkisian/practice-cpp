//---------------------------------------------------------------------------

#ifndef TopScoresGetNameH
#define TopScoresGetNameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TinputTopScoresPlayersName : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *getName;
	TButton *Button1;
	TLabel *Label1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		friend class hallOfFame;
	__fastcall TinputTopScoresPlayersName(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TinputTopScoresPlayersName *inputTopScoresPlayersName;
//---------------------------------------------------------------------------
#endif
