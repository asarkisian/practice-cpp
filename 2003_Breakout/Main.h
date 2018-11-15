//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <jpeg.hpp>
#include "trayicon.h"

//---------------------------------------------------------------------------
class TfrmMain : public TForm{

__published:	// IDE-managed Components
	TShape *myPaddle;
	TShape *myPaddle2;
	TShape *blackFloor;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *StartGame1;
	TMenuItem *EndGame1;
	TMenuItem *Help2;
	TMenuItem *N1;
	TMenuItem *ExitAltF41;
	TMenuItem *Opotions1;
	TMenuItem *Difficulty1;
	TMenuItem *PaddleSpeed1;
	TMenuItem *mnuBallSlow;
	TMenuItem *mnuBallMod;
	TMenuItem *mnuBallFast;
	TMenuItem *mnuPaddleSlow;
	TMenuItem *mnuPaddleMod;
	TMenuItem *mnuPaddleFast;
	TMenuItem *mnuBallFastest;
	TMenuItem *mnuPaddleFastest;
	TMenuItem *mnuBallSlowest;
	TMenuItem *mnuPaddleSlowest;
	TShape *myPaddle3;
	TShape *myPaddle4;
	TShape *myPaddle5;
	TShape *myBall;
	TLabel *Label1;
	TLabel *numberOfMisses;
	TLabel *Label2;
	TLabel *numberOfLevel;
	TLabel *Label3;
	TLabel *numberOfScore;
	TLabel *Label4;
	TLabel *numberOfCredits;
	TMenuItem *HallOfFame1;
	TMenuItem *PauseGame1;
	TMenuItem *mnucmdSound;
	TMenuItem *N2;
	TLabel *bonusLevel1;
	TLabel *bonusLevel2;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
					TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall StartGame1Click(TObject *Sender);
	void __fastcall ExitAltF41Click(TObject *Sender);
	void __fastcall EndGame1Click(TObject *Sender);
	void __fastcall mnuBallModClick(TObject *Sender);
	void __fastcall mnuBallSlowClick(TObject *Sender);
	void __fastcall mnuBallFastClick(TObject *Sender);
	void __fastcall mnuPaddleFastClick(TObject *Sender);
	void __fastcall mnuPaddleModClick(TObject *Sender);
	void __fastcall mnuPaddleSlowClick(TObject *Sender);
	void __fastcall mnuPaddleFastestClick(TObject *Sender);
	void __fastcall mnuBallFastestClick(TObject *Sender);
	void __fastcall mnuBallSlowestClick(TObject *Sender);
	void __fastcall mnuPaddleSlowestClick(TObject *Sender);
	void __fastcall Help2Click(TObject *Sender);
	void __fastcall HallOfFame1Click(TObject *Sender);
	void __fastcall PauseGame1Click(TObject *Sender);
	void __fastcall mnucmdSoundClick(TObject *Sender);

private:

	//Sound FX On/Off Switch
	bool soundEnabled;

	//Switches ON/OFF. These switches make the ball move accordingly.
	bool controlKey_up;		//Controls the ball to go up
	bool controlKey_down;  //Controls the ball to go down
	bool controlKey_left;  //Controls the ball to go left
	bool controlKey_right; //Controls the ball to go right

	//States whether or not the user has exited the game
	bool gExit;				//Global Var for escape during gameplay

	//User chooses the speed of the ball
	short int usr_ballspeed;

	//User chooses the speed of the paddle
	short int usr_paddlespeed;

	//Required amount of paddles to hit to advance to next level
	short int amountOfBricksHit;

	//PlayersScore
	int playersScore;

	//PlayersMisses
	int playersMisses;

	//States what level the user is in
	int playersLevel;
	int currentLevel;

	//States how many credits a player has
	int playersCredits;

	bool playerNewGame;
	bool playerWinGame;
	bool playerLoseGame;
	bool playerRestartGame;
	bool playerEndGame;

	//Depending on which portion of the paddle you hit, the ball will move differently
	short int paddle_ballSpeedUp;
	short int paddle_ballSpeedDown;
	short int paddle_ballSpeedLeft;
	short int paddle_ballSpeedRight;

public:
  friend class hallOfFame;
	__fastcall TfrmMain(TComponent* Owner);

	void __fastcall gameStart();									//Starts the game
	void __fastcall gameEnd();          					//Ends the game
	void __fastcall initializeValues(); 					//Initializes game constants
	bool __fastcall interceptedPaddleBallBrick(); //Determines if the ball hit anything
	void __fastcall levelThemes();                //Level themes
	void __fastcall themePaddleColor();           //Theme paddle color
	void __fastcall themeBallColor();             //Theme ball color
  void __fastcall randomMenuColors();           //Random menubar colors

	TImage* Shape3[25];		//Dynamic object (Shape3 which is the bricks)
	TImage* myBackground; //Dynamic object (myBackground which is the wallpaper (theme))
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------

#endif
