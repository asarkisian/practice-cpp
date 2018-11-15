///////////////////////////////////////
// domain.cpp

///////////////////////////////////////
#include "game.h"
#include "poker.h"
///////////////////////////////////////

///////////////////////////////////////
using std::cin;
using std::cout;
using std::endl;
///////////////////////////////////////

///////////////////////////////////////
bool isPlayAgain( bool& ri )
{
	char choice = ( EMPTY );

	do
	{
		cout << IS_PLAY_AGAIN;
		cin >> choice;

		choice = toupper( choice );

	}while( choice != YES && choice != NO );

	if( choice == YES ) { ri = ( true ); return( false ); }

	return( true );
}
///////////////////////////////////////

///////////////////////////////////////
void doMain( )
{
	bool isStopGame = ( true ), reinitialize = ( false );

	Game* myGame = ( new Poker( DEFAULT_PLYR, STARTING_WAGE ) );

	do{	
		if( reinitialize ){ myGame->reinitializeData( ); }

		if( myGame->playersMoney( ) <= NO_MONEY )
		{
			cout << NO_MORE_MONEY << endl;
			break;
		}

		myGame->playGame( );

		isStopGame = isPlayAgain( reinitialize );

	}while( !isStopGame );

	delete myGame;
}
///////////////////////////////////////