#if !defined GAMECONSTANTS_H
#define GAMECONSTANTS_H

#include "Main.h"

/************************* Form  & Object Controls *****************************
------------------------------------------------------------------------------*/

//General Controls
#define NULL_VALUE 0

//////////////////////////////////////////////////////////////////////////////
////////////////////////// MUSIC AND SOUND CONTROLS //////////////////////////
//////////////////////////////////////////////////////////////////////////////

#define BRICK_HIT "Sounds\\HitBrick.wav"

//////////////////////////////////////////////////////////////////////////////
////////////////////////// MAINFRM ATTRIBUTES ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//frmMain attributes & properties
#define MAIN_HEIGHT 388
#define MAIN_WIDTH 577
#define MAIN_TOP 579
#define MAIN_LEFT 215

//frmMain default values (player & level values)
#define DEFAULT_PLAYERS_LEVEL 1
#define DEFAULT_CURRENT_LEVEL 1
#define DEFAULT_PLAYERS_CREDITS 3
#define DEFAULT_PLAYERS_MISSES 0
#define DEFAULT_PLAYERS_SCORE 0


//////////////////////////////////////////////////////////////////////////////
////////////////////////// BALL ATTRIBUTES ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//myBall attributes
#define MYBALL_HEIGHT 17
#define MYBALL_WIDTH 25
#define MYBALL_TOP 246
#define MYBALL_LEFT 274


/////////// BALL COLOR FOR EACH THEME ///////////////////////////////////////
//ballColor depending on the stage (theme)

//Default Color (during startup)
#define BALL_DEFAULT_COLOR clWhite

//Egypt Stage
#define BALL_STAGE1_COLOR_BRUSH clSkyBlue
#define BALL_STAGE1_COLOR_PEN clWhite

//South America Jungle
#define BALL_STAGE2_COLOR_BRUSH clRed
#define BALL_STAGE2_COLOR_PEN clWhite
#define BALL_STAGE3_COLOR_BRUSH clRed
#define BALL_STAGE3_COLOR_PEN clWhite
#define BALL_STAGE4_COLOR_BRUSH clRed
#define BALL_STAGE4_COLOR_PEN clWhite

//Atlantic Ocean Underwater Adventure
#define BALL_STAGE5_COLOR_BRUSH clLime
#define BALL_STAGE5_COLOR_PEN clLime
#define BALL_STAGE6_COLOR_BRUSH clBlue
#define BALL_STAGE6_COLOR_PEN clWhite
#define BALL_STAGE7_COLOR_BRUSH clLime
#define BALL_STAGE7_COLOR_PEN clLime
#define BALL_STAGE8_COLOR_BRUSH clBlue
#define BALL_STAGE8_COLOR_PEN clWhite

//A trip to Antarctica
#define BALL_STAGE9_COLOR_BRUSH clLime
#define BALL_STAGE9_COLOR_PEN clNavy
#define BALL_STAGE10_COLOR_BRUSH clLime
#define BALL_STAGE10_COLOR_PEN clNavy

//Desert Stage
#define BALL_STAGE11_COLOR_BRUSH clBlue
#define BALL_STAGE11_COLOR_PEN clBlue
#define BALL_STAGE12_COLOR_BRUSH clBlue
#define BALL_STAGE12_COLOR_PEN clBlue

//Sky and Sunset Stage
#define BALL_STAGE13_COLOR_BRUSH clGreen
#define BALL_STAGE13_COLOR_PEN clBlack
#define BALL_STAGE14_COLOR_BRUSH clGreen
#define BALL_STAGE14_COLOR_PEN clWhite

//Lightning across the sky stage
#define BALL_STAGE15_COLOR_BRUSH clRed
#define BALL_STAGE15_COLOR_PEN clWhite
#define BALL_STAGE16_COLOR_BRUSH clRed
#define BALL_STAGE16_COLOR_PEN clWhite

//Into the sun we go
#define BALL_STAGE17_COLOR_BRUSH clRed
#define BALL_STAGE17_COLOR_PEN clYellow

///////////////////////////////////////////////////////////////////////////////

//myBall gravity attributes
#define BALL_SPEED_UP 1
#define BALL_SPEED_DOWN 1
#define BALL_SPEED_LEFT 1
#define BALL_SPEED_RIGHT 1

//True speed of the ball
#define BALL_SLEEP 20

//ballSpeed attributes
#define USR_BALL_SLOWEST 1
#define USR_BALL_SLOW 2
#define USR_BALL_MOD 4
#define USR_BALL_FAST 5
#define USR_BALL_FASTEST 6

//Initiating whether the ball will go up or down during startup
#define BALL_UP 0
#define BALL_DOWN 1

//blackFloor bottom window (menu) attributes
#define BLACKFLOOR_COLOR clBlack
#define BLACKFLOOR_HEIGHT 25
#define BLACKFLOOR_WIDTH 569
#define BLACKFLOOR_TOP 312
#define BLACKFLOOR_LEFT 0

//////////////////////////////////////////////////////////////////////////////
////////////////////////// PADDLE ATTRIBUTES /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//leftPanel attributes
//#define LEFTPANEL_COLOR clBlue
#define LEFTPANEL_HEIGHT 12
#define LEFTPANEL_WIDTH 2
#define LEFTPANEL_TOP 288
#define LEFTPANEL_LEFT 229
//leftPanel speed (when the ball bounces on this portion of the paddle)
#define LEFTPANEL_UP_SPEED 2
#define LEFTPANEL_DOWN_SPEED 2
#define LEFTPANEL_LEFT_SPEED 5
#define LEFTPANEL_RIGHT_SPEED 5

//middle-leftPanel attributes
//#define MIDDLELEFTPANEL_COLOR clBlue
#define MIDDLELEFTPANEL_HEIGHT 12
#define MIDDLELEFTPANEL_WIDTH 60
#define MIDDLELEFTPANEL_TOP 288
#define MIDDLELEFTPANEL_LEFT 230
//middleLeftPanel speed (when the ball bounces on this portion of the paddle)
#define MIDDLELEFTPANEL_UP_SPEED 3
#define MIDDLELEFTPANEL_DOWN_SPEED 3
#define MIDDLELEFTPANEL_LEFT_SPEED 2
#define MIDDLELEFTPANEL_RIGHT_SPEED 2

//middlePanel attributes
//#define MIDDLEPANEL_COLOR clBlue
#define MIDDLEPANEL_HEIGHT 12
#define MIDDLEPANEL_WIDTH 2
#define MIDDLEPANEL_TOP 288
#define MIDDLEPANEL_LEFT 289
//middlePanel speed (when the ball bounces on this portion of the paddle)
#define MIDDLEPANEL_UP_SPEED 4
#define MIDDLEPANEL_DOWN_SPEED 4
#define MIDDLEPANEL_LEFT_SPEED 0
#define MIDDLEPANEL_RIGHT_SPEED 0

//middle-rightPanel attributes
//#define MIDDLERIGHTPANEL_COLOR clBlue
#define MIDDLERIGHTPANEL_HEIGHT 12
#define MIDDLERIGHTPANEL_WIDTH 60
#define MIDDLERIGHTPANEL_TOP 288
#define MIDDLERIGHTPANEL_LEFT 290
//middleRightPanel speed (when the ball bounces on this portion of the paddle)
#define MIDDLERIGHTPANEL_UP_SPEED 3
#define MIDDLERIGHTPANEL_DOWN_SPEED 3
#define MIDDLERIGHTPANEL_LEFT_SPEED 2
#define MIDDLERIGHTPANEL_RIGHT_SPEED 2

//rightPanel attributes
//#define RIGHTPANEL_COLOR clBlue
#define RIGHTPANEL_HEIGHT 12
#define RIGHTPANEL_WIDTH 2
#define RIGHTPANEL_TOP 288
#define RIGHTPANEL_LEFT 349
//rightPanel speed (when the ball bounces on this portion of the paddle)
#define RIGHTPANEL_UP_SPEED 2
#define RIGHTPANEL_DOWN_SPEED 2
#define RIGHTPANEL_LEFT_SPEED 5
#define RIGHTPANEL_RIGHT_SPEED 5

/////////// PADDLE COLOR FOR EACH THEME ///////////////////////////////////////
//paddleColor depending on the stage (theme)

//Default Color (during startup)
#define PADDLE_DEFAULT_COLOR clWhite

//Egypt Stage
#define PADDLE_STAGE1_COLOR clBlue

//South America Jungle
#define PADDLE_STAGE2_COLOR clRed
#define PADDLE_STAGE3_COLOR clRed
#define PADDLE_STAGE4_COLOR clRed

//Atlantic Ocean Underwater Adventure
#define PADDLE_STAGE5_COLOR clLime
#define PADDLE_STAGE6_COLOR clBlue
#define PADDLE_STAGE7_COLOR clAqua
#define PADDLE_STAGE8_COLOR clBlue

//A trip to Antarctica
#define PADDLE_STAGE9_COLOR clBlue
#define PADDLE_STAGE10_COLOR clNavy

//Desert Stage
#define PADDLE_STAGE11_COLOR clSkyBlue
#define PADDLE_STAGE12_COLOR clBlue

//Sky and Sunset Stage
#define PADDLE_STAGE13_COLOR clNavy
#define PADDLE_STAGE14_COLOR clNavy

//Lightning across the sky stage
#define PADDLE_STAGE15_COLOR clRed
#define PADDLE_STAGE16_COLOR clRed

//Into the sun we go
#define PADDLE_STAGE17_COLOR clRed

//paddleSpeed attribute
#define PADDLE_SPEED 1

//paddleSpeed difficulty level attributes (PADDLE SPEED NOT BALL)
#define PADDLE_BALL_SLOWEST 7
#define PADDLE_BALL_SLOW 13
#define PADDLE_BALL_MOD 18
#define PADDLE_BALL_FAST 24
#define PADDLE_BALL_FASTEST 30

//Maximum number of paddles on the screen
#define BRICK_MAX 25

//BRICK ATTRIBUTES (Dynamic Shape3)
#define BRICK_HEIGHT 15
#define BRICK_WIDTH 107
#define BRICK_PICTURE "Graphics\\Game_Objects\\myBrick.jpg"

//////////////////////////////////////////////////////////////////////////////
///////////////////////SCORING SYSTEM/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#define MAX_SCORE 10000

//Slowest Level Hit Score Attributes
#define SLOWEST_HIT_SCORE 16
#define SLOWEST_MISS_SCORE 6

//Slow Level Hit Score Attributes
#define SLOW_HIT_SCORE 20
#define SLOW_MISS_SCORE 9

//Moderate Level Hit Score Attributes
#define MOD_HIT_SCORE 29
#define MOD_MISS_SCORE 21

//Fast Level Hit Score Attributes
#define FAST_HIT_SCORE 41
#define FAST_MISS_SCORE 30

//Fastest Level Hit Score Attributes
#define FASTEST_HIT_SCORE 52
#define FASTEST_MISS_SCORE 38

//////////////////////////////////////////////////////////////////////////////
///////////////////////LEVELING SYSTEM////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//Indicates the number of maximum levels
#define MAX_LEVELS 100

//Special Levels (bonus levels)
#define SPECIAL_LEVELONE 7
#define SPECIAL_LEVELTWO 16
#define SPECIAL_LEVELTHREE 22
#define SPECIAL_LEVELFOUR 34
#define SPECIAL_LEVELFIVE 45
#define SPECIAL_LEVELSIX 59
#define SPECIAL_LEVELSEVEN 67
#define SPECIAL_LEVELEIGHT 74
#define SPECIAL_LEVELNINE 89
#define SPECIAL_LEVELTEN 93
#define SPECIAL_LEVELELEVEN 100

#define SPECIAL_LEVEL_HITPOINT_SLOWEST 5
#define SPECIAL_LEVEL_HITPOINT_SLOW 10
#define SPECIAL_LEVEL_HITPOINT_MODERATE 15
#define SPECIAL_LEVEL_HITPOINT_FAST 5
#define SPECIAL_LEVEL_HITPOINT_FASTEST 20

//Color of the text (there are two bonus texts, left side and right side of the window)
#define BONUS_LEVEL_TEXT_COLOR clRed

//////////////////////////////////////////////////////////////////////////////
///////////////////////THEME LEVELS///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//The width for all these pictures are 577 and the height are 388

//Brick Stage
#define STAGE1 "Graphics\\Egypt_Stage\\EgyptLevel1.jpg"

//South America Jungle
#define STAGE2 "Graphics\\Jungle_Stage\\JungleLevel1.jpg"
#define STAGE3 "Graphics\\Jungle_Stage\\JungleLevel2.jpg"
#define STAGE4 "Graphics\\Jungle_Stage\\JungleLevel3.jpg"

//Atlantic Ocean Underwater Adventure
#define STAGE5 "Graphics\\Water_Stage\\WaterLevel1.jpg"
#define STAGE6 "Graphics\\Water_Stage\\WaterLevel2.jpg"
#define STAGE7 "Graphics\\Water_Stage\\WaterLevel3.jpg"
#define STAGE8 "Graphics\\Water_Stage\\WaterLevel4.jpg"

//A trip to Antarctica
#define STAGE9 "Graphics\\Ice_Stage\\IceLevel1.jpg"
#define STAGE10 "Graphics\\Ice_Stage\\IceLevel2.jpg"

//Some nice abstract designs
#define STAGE11 "Graphics\\Desert_Stage\\DesertLevel1.jpg"
#define STAGE12 "Graphics\\Desert_Stage\\DesertLevel2.jpg"

//Sky and Sunset Stage
#define STAGE13 "Graphics\\Sky_Stage\\SkyLevel1.jpg"
#define STAGE14 "Graphics\\Sky_Stage\\SkyLevel2.jpg"

//Lightning across the sky stage
#define STAGE15 "Graphics\\Lightning_Stage\\LightningLevel1.jpg"
#define STAGE16 "Graphics\\Lightning_Stage\\LightningLevel2.jpg"

//Into the sun we go
#define STAGE17 "Graphics\\Fire_Stage\\FireLevel1.jpg"

//////////////////////////////////////////////////////////////////////////////
//Determines the theme levels start level and end level for each stage (theme)
//////////////////////////////////////////////////////////////////////////////

//Egypt Stage
#define STAGE1FIRST 1
#define STAGE1LAST 4

//South America Jungle
#define STAGE2FIRST 5
#define STAGE2LAST 9
#define STAGE3FIRST 10
#define STAGE3LAST 17
#define STAGE4FIRST 18
#define STAGE4LAST 22

//Atlantic Ocean Underwater Adventure
#define STAGE5FIRST 23
#define STAGE5LAST 28
#define STAGE6FIRST 29
#define STAGE6LAST 35
#define STAGE7FIRST 36
#define STAGE7LAST 40
#define STAGE8FIRST 41
#define STAGE8LAST 46

//A trip to Antarctica
#define STAGE9FIRST 47
#define STAGE9LAST 50
#define STAGE10FIRST 51
#define STAGE10LAST 55

//Desert Stage
#define STAGE11FIRST 56
#define STAGE11LAST 62
#define STAGE12FIRST 63
#define STAGE12LAST 69

//Sky and Sunset Stage
#define STAGE13FIRST 70
#define STAGE13LAST 73
#define STAGE14FIRST 74
#define STAGE14LAST 76

//Lightning across the sky stage
#define STAGE15FIRST 77
#define STAGE15LAST 83
#define STAGE16FIRST 84
#define STAGE16LAST 90

//Into the sun we go
#define STAGE17FIRST 91
#define STAGE17LAST 100

//////////////////////////////////////////////////////////////////////////////
////////////////////////// TOP SCORE CONTROLS ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//Hall Of Fame Controls
///////////////////////

#define FILE_NAME "GameLog.Dat"

//Default players if game starts only the first time

//Default players names
#define DEFAULT_PLAYERONE_NAME "Armond Sarkisian"
#define DEFAULT_PLAYERTWO_NAME "Superman"
#define DEFAULT_PLAYERTHREE_NAME "Spiderman"
#define DEFAULT_PLAYERFOUR_NAME "Batman"
#define DEFAULT_PLAYERFIVE_NAME "Darth Vader"
#define DEFAULT_PLAYERSIX_NAME "Mickey Mouse"
#define DEFAULT_PLAYERSEVEN_NAME "Homer Simpson"
#define DEFAULT_PLAYEREIGHT_NAME "Bugs Bunny"
#define DEFAULT_PLAYERNINE_NAME "Luke Skywalker"
#define DEFAULT_PLAYERTEN_NAME "Daffy Duck"

//Default players scores
#define DEFAULT_PLAYERONE_SCORE   "100000"
#define DEFAULT_PLAYERTWO_SCORE   "95000"
#define DEFAULT_PLAYERTHREE_SCORE "85500"
#define DEFAULT_PLAYERFOUR_SCORE  "75500"
#define DEFAULT_PLAYERFIVE_SCORE  "65200"
#define DEFAULT_PLAYERSIX_SCORE   "55250"
#define DEFAULT_PLAYERSEVEN_SCORE "45520"
#define DEFAULT_PLAYEREIGHT_SCORE "42500"
#define DEFAULT_PLAYERNINE_SCORE  "35250"
#define DEFAULT_PLAYERTEN_SCORE   "32500"

#define FIRST_PLACE 1
#define SECOND_PLACE 2
#define THIRD_PLACE 3
#define FOURTH_PLACE 4
#define FIFTH_PLACE 5
#define SIXTH_PLACE 6
#define SEVENTH_PLACE 7
#define EIGHT_PLACE 8
#define NINTH_PLACE 9
#define TENTH_PLACE 10

//////////////////////////////////////////////////////////////////////////////
////////////////////////// CREDIT STORE /////////// //////////////////////////
//////////////////////////////////////////////////////////////////////////////

//Players can purchase credits for 1500 dollars and in return they will receive 1 credit
#define CREDIT_COST 1500
#define RETURN_CREDIT 1

#endif
