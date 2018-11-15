//**begin #include files************
#include <iostream> // provides access to cin and cout
#include <array>	// provides access to std::array
#include <time.h>	// provides access to time() for srand()
//--end of #include files-----------
//----------------------------------

using namespace std;
//----------------------------------

//**begin global constants**********
// define coordinate structure
struct Coords
{
	int x;
	int y;
};

// define a struct of the target
struct MyStruct
{	
  char characterType;
	int ID;				// -- Identification number of the target
	Coords position;	// -- position of target			
	int dist;			// -- distance between target and snowball hit	
	bool hit;			// -- flag indicating target has been hit
};

const int gridSize = 5;		// const grid size (i.e. 5x5 grid constant is 5)
const int turns = 20;		// const number of turns
const int targetCount = 3;	// number of targets

//--end of global constants---------
//----------------------------------

//**begin function prototypes*******
int throwSnowball(Coords p, MyStruct &Target);
void moveTarget( MyStruct &Target);
//--end of function prototypes------
//----------------------------------

//**begin main program**************
int main()
{
	// initialization
	srand(time(NULL));
	bool allHit = false;
	int hitCount = 0;	// number of hits.
	int dist = 0;		// distance of miss
	Coords snowballPos;	// position of snowball hit
	array <MyStruct, targetCount> Targets;
	MyStruct Player;

	
	// Initialize player
		Player.characterType = 'p';
		Player.ID = 0;		// set identification number
		// set target at random location
		Player.position.x = rand()%gridSize;
		Player.position.y = rand()%gridSize;
		Player.hit = false;		// set target hit flag to default: false

	// Initialize targets
	int idNum = 0;
	for (auto &T: Targets) //**Error 1: add the "&"
	{
		T.characterType = 't';
		T.ID = idNum++;		// set identification number
		// set target at random location
		T.position.x = rand()%gridSize;
		T.position.y = rand()%gridSize;
		T.hit = false;		// set target hit flag to default: false
	}
	// loop for the specified number of turns
	for (int i = 0; i < turns; i++)
	{
		//   get x and y position for the snowball from player
		cout << "column? ";
		cin >> snowballPos.x;
		cout << "row?    ";
		cin >> snowballPos.y;
		
		// player throws snow ball (see instructions for details)
		for(auto &T: Targets)
		{
			if (!T.hit)
			{
				// check for hit or miss
				dist = throwSnowball(snowballPos, T);
				// report results
				switch (dist)
				{
				case 0:
					cout << "***SPLAT*** You hit target " << T.ID << "!" << endl;
					hitCount++;
					break;
				case 1:
					cout << "target " << T.ID << ": Way too close!" << endl;
					break;
				case 2:
					cout << "target " << T.ID << ": I heard it hit." << endl; 
					break;
				default:
					cout << "target " << T.ID << ": Missed by a mile." << endl;
					break;
				}
				//   target moves (see instruction for details
				if (!T.hit) moveTarget(T);
			}
		}

		if (hitCount == 3) 
		{
			allHit = true;
			break;
		}
		
		
		// target throws snow ball (see instructions for details)
		
		//   randomize x and y position for the snowball from target
		snowballPos.x = rand() % gridSize;
		snowballPos.y = rand() % gridSize;
		
		endl(cout);
		
		for(auto &T: Targets)
		{
		  if( T.hit == false ){
      	// target throws snow ball (see instructions for details)
      	if (!Player.hit)
      	{
      		// check for hit or miss
      		dist = throwSnowball(snowballPos, Player);
      		
      		// report results
      		switch (dist)
      		{
      		case 0:
      			cout << "Target: " << T.ID << " Hit You! Game Over!" << endl;
      			return 0;
      			break;
      		default:
      			cout << "Target: " << T.ID << " Missed You!" << endl;
      			break;
      		}
      		//   Player moves (see instruction for details
      	}
		  }
		}

    endl(cout);
		if (!Player.hit) moveTarget(Player);
	
		cout << "---Next Turn---" << endl;
		
	}
	// end of loop
	// report score (number of hits vs turns)
	if (allHit) cout << "All targets have been hit!  Great job!" << endl;
	else cout << "You had " << hitCount << " hits out of " << turns << " throws." << endl;
	cin.get();
	// Wait for user input to close program when debugging.
	cin.get();
	return 0;
}
//--end of main program-------------
//----------------------------------

//**begin function definitions******
// Determine hit or distance
int throwSnowball(Coords p, MyStruct &Object)
{
	int aDistance;
	//   compare to the target's position
	if ( p.x == Object.position.x)
	{
		if (p.y == Object.position.y)
		{
			Object.hit = true;
			return 0;
		}
		else
		{
			return abs(p.y - Object.position.y);
		}
	}
	else
	{
		aDistance = abs(p.x -Object.position.x);
		if (aDistance < abs(p.y - Object.position.y)) aDistance = abs(p.y -Object.position.y);
		return aDistance;
	}
}

//  Move the target
void moveTarget(MyStruct &Object)
{
  	enum MyEnum
  	{
  		North, East, South, West, Stay 
  	};
  	
  	bool moveNotFound = true;

    if(Object.characterType == 't')
    {
    	MyEnum ranNum = MyEnum(rand()%5);
    	
    	if (ranNum == Stay){
  			cout << Object.ID << ": Target staying." << endl;

    	  return;
    	}

    	while (moveNotFound)
    	{
  
    		switch (ranNum)
    		{
    		case North:
    			if (Object.position.y == 0)	break; // can't move North
    			Object.position.y--;
    			cout << Object.ID << " moving North." << endl;
    			return;
    		case East:
    			if (Object.position.x == gridSize-1)	break; // can't move East
    			Object.position.x++;
    			cout << Object.ID << " moving East." << endl;
    			return;
    		case South:
    			if (Object.position.y == gridSize -1)	break; // can't move South
    			Object.position.y++;
    			cout << Object.ID << " moving South." << endl;
    			return;
    		case West:
    			if (Object.position.x == 0)	break; // can't move West
    			Object.position.x--;
    			cout << Object.ID << " moving West." << endl;
    			return;
    		default:
    			break;
    		}
    		ranNum = MyEnum(int(ranNum+1)%4);
    	}
  }
  else
  {
    char playerMove;
    
    cout << "Choose a direction: n, w, s, e or d for don't move: ";
    cin >> playerMove;
    
    playerMove = tolower(playerMove);
    
		switch (playerMove)
		{
		case 'n':
			if (Object.position.y == 0)	break; // can't move North
			Object.position.y--;
			cout << "Player moving North." << endl;
			return;
		case 'e':
			if (Object.position.x == gridSize-1)	break; // can't move East
			Object.position.x++;
			cout << "Player moving East." << endl;
			return;
		case 's':
			if (Object.position.y == gridSize -1)	break; // can't move South
			Object.position.y++;
			cout << "Player moving South." << endl;
			return;
		case 'w':
			if (Object.position.x == 0)	break; // can't move West
			Object.position.x--;
			cout << Object.ID << "Player moving West." << endl;
			return;
		case 'd':
			cout << "Player staying." << endl;
		  return;
		default:
			break;
		}
  }
}
//--end of function definitions------
//----------------------------------
