///////////////////////////////////////
// config.h

///////////////////////////////////////
#ifndef _CONFIG_H_
#define _CONFIG_H_
///////////////////////////////////////

///////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
///////////////////////////////////////

///////////////////////////////////////
// program info
#define TITLE			"\n-=Bombay Club Texas Holdem=-\n"
#define TITLE_LINE		"*~~~~~~~~~~~~~~~~~~~~~~~~~~*"

// deck
#define MAX_CARDS		52
#define EMPTY_CARD		"   "
#define MYSTERY_CARD	"???"

// suites
#define HEART			"\x3"
#define SPADE			"\x6"
#define DIAMOND			"\x4"
#define CLUB			"\x5"

// numbers
#define ACE				'A'
#define TWO				'2'
#define THREE			'3'
#define FOUR			'4'
#define FIVE			'5'
#define SIX				'6'
#define SEVEN			'7'
#define EIGHT			'8'
#define NINE			'9'
#define TEN				"10"
#define TEN_SUBST		'1'

// faces
#define JACK			'J'
#define QUEEN			'Q'
#define KING			'K'

// container sizes
#define SHARED_HAND		5
#define EMPTY_ARRAY		15

// initializations
#define STARTING_WAGE	100.00
#define MIN_BET			5.00
#define NO_MONEY		0

#define FLOP_ROUND		1
#define TURN_ROUND		2
#define SHOWDOWN_ROUND	3

#define DEFAULT_PLYR	"Player"

#define YES				'Y'
#define NO				'N'
#define EMPTY			' '

// commands
#define DEAL			"deal"
#define FLOP			"flop"
#define TURN			"turn"
#define RIVER			"river"

#define PLAYER			"player"
#define DEALER			"dealer"

#define CLEAR_SCREEN	"cls"
#define PAUSE_SCREEN	"pause"

#define PRIMARY_DECK	"primary"
#define TEMP_DECK		"temp"

// statements
#define ENTER_WAGE_AMT	"\nEnter wager amount: $"
#define PLAYER_HAS		"\'s money: $"
#define CURRENT_POT		"\nCurrent Pot: $"
#define NOT_ENOUGH_MNY	"You do not have enough money to bet $"

#define PLAYER_WINS		" wins with a "
#define PLAYER_HIGHER	" wins with a higher "
#define DEALER_WINS		"Dealer wins with a "
#define DEALER_HIGHER	"Dealer wins with a higher "
#define KICKER			" kicker!"
#define PUSH			"You Push!"
#define IS_PLAY_AGAIN	"Place another wager? (Y)es, (N)o: "

#define NO_MORE_MONEY	"Sorry, you have no more funds to play!"

// errors
#define EXCEPTION		"Exception: "
#define UNKNOWN_ERROR	"Unknown Internal Error!"

#define ERROR_100		"Error 100: Invalid Phase!"
#define ERROR_101		"ERROR 101: Incorrect Opponent!"
#define ERROR_102		"ERROR 102: No High Card Returned!"
#define ERROR_103		"ERROR 103: Invalid Score!"
#define ERROR_104		"ERROR 104: Invalid Card!"
#define ERROR_105		"ERROR 105: Invalid Deck!"
///////////////////////////////////////

///////////////////////////////////////
#endif
///////////////////////////////////////