///////////////////////////////////////
// domain.cpp

///////////////////////////////////////
#include "game.h"
#include "poker.h"
#include "sdl_lib.h"
///////////////////////////////////////

///////////////////////////////////////
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
///////////////////////////////////////

///////////////////////////////////////
extern bool isPlayAgain( bool& );
///////////////////////////////////////

///////////////////////////////////////
void doMain( )
{
	Game* myGame = ( new Poker( DEFAULT_PLYR, STARTING_WAGE ) );
	bool isQuit = ( false ), reinitialize = ( false );
	SDL_lib my_sdl = SDL_lib( );

	my_sdl.init( );
	my_sdl.load_files( );
	my_sdl.apply_surface( 0, 0, my_sdl.background, my_sdl.screen );

	//Update the screen
	if( SDL_Flip( my_sdl.screen ) == SDL_ERROR )
	{
		throw domain_error( SDL_GetError( ) );    
	}

	//While the user hasn't quit
	while( isQuit == false )
	{
		if( reinitialize ){ myGame->reinitializeData( ); }
		if( myGame->playersMoney( ) <= NO_MONEY )
		{
			//cout << NO_MORE_MONEY << endl;
			break;
		}
				
		myGame->playGame( );

		//While there's an event to handle
		while( SDL_PollEvent( &my_sdl.my_event ) )
		{
			Uint8 *keystates = SDL_GetKeyState( NULL );

			//If the user has Xed out the window
			if( my_sdl.my_event.type == SDL_QUIT )
			{
				//Quit the program
				isQuit = ( true );
			}

			if( keystates[SDLK_ESCAPE] )
			{
				isQuit = ( true );
			}
			else if( keystates[SDLK_DOWN] )
			{
				my_sdl.apply_surface( 92, 273, my_sdl.queenClubs, my_sdl.screen );
				SDL_UpdateRect( my_sdl.screen, 92, 273, 83, 126 );

				break;
			}
		}
		isQuit = isPlayAgain( reinitialize );	
	}

	//Free the surface and quit SDL
	my_sdl.clean_up( );

	delete myGame;
}
///////////////////////////////////////

///////////////////////////////////////
bool isPlayAgain( bool& ri )
{
	char choice = ( EMPTY );

	do
	{
		//cout << IS_PLAY_AGAIN;
		//cin >> choice;

		choice = toupper( choice );

	}while( choice != YES && choice != NO );

	if( choice == YES ) { ri = ( true ); return( false ); }

	return( true );
}
///////////////////////////////////////