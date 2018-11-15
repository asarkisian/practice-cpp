/////////////////////////////////////////////
// sdl_lib.cpp

/////////////////////////////////////////////
#include "sdl_lib.h"
/////////////////////////////////////////////

/////////////////////////////////////////////
using std::domain_error;
using std::string;
/////////////////////////////////////////////

/////////////////////////////////////////////
SDL_lib::SDL_lib( )
:background( NULL ),
 screen( NULL )
{
}
/////////////////////////////////////////////

/////////////////////////////////////////////
SDL_lib::~SDL_lib( )
{
}
/////////////////////////////////////////////

/////////////////////////////////////////////
SDL_Surface *SDL_lib::load_image( string filename ) 
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = ( NULL );
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = ( NULL );

	//Load the image
    loadedImage = SDL_LoadBMP( filename.c_str( ) );

	//If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

	//Return the optimized image
    return( optimizedImage );
}
/////////////////////////////////////////////

/////////////////////////////////////////////
void SDL_lib::apply_surface( position_t x, position_t y, 
				    SDL_Surface* source, SDL_Surface* destination )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = ( x );
    offset.y = ( y );
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}
/////////////////////////////////////////////

/////////////////////////////////////////////
void SDL_lib::init( )
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == SDL_ERROR )
    {
        throw domain_error( SDL_GetError( ) );
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 
		                       SCREEN_BPP, SCREEN_MODE );
    
    //If there was in error in setting up the screen
    if( screen == NULL )
    {
        throw domain_error( SDL_GetError( ) );
    }
    
    //Set the window caption
    SDL_WM_SetCaption( TITLE, NULL );
}
/////////////////////////////////////////////

/////////////////////////////////////////////
void SDL_lib::load_files()
{
    //Load the images
    background = load_image( BACKGROUND_IMG );
    if( background == NULL )
    {
		throw domain_error( SDL_GetError( ) );
	}

	queenClubs = load_image( QCLUBS_IMG );
    if( queenClubs == NULL )
    {
		throw domain_error( SDL_GetError( ) );
	}
}

/////////////////////////////////////////////

/////////////////////////////////////////////
void SDL_lib::clean_up( )
{
    //Free the images
	SDL_FreeSurface( queenClubs );
    SDL_FreeSurface( background );
    
    //Quit SDL
    SDL_Quit( );    
}
/////////////////////////////////////////////