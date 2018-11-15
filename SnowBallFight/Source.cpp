// Week 6 Assignment-1
// Description: Snowball Fight - version 3
//----------------------------------

//**begin #include files************
#include <iostream> // provides access to cin and cout
#include <array>	// provides access to std::array
#include <ctime>	// provides access to time() for srand()
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
//I added for player being hit
// define a struct of the target
struct MyStruct
{
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
void moveTarget(MyStruct &Target);
//--end of function prototypes------
//----------------------------------

//**begin main program**************
int main()
{
	// initialization
	srand(static_cast<int>(time(NULL)));
	bool allHit = false;
	int hitCount = 0;	// number of hits.
	int dist = 0;		// distance of miss
	Coords snowballPos;	// position of snowball hit
	array <MyStruct, targetCount> Targets;
	// Initialize targets
	int idNum = 0;
	for (auto &T : Targets) //**Error 1: add the "&"
	{
		T.ID = idNum++;		// set identification number
							// set target at random location
		T.position.x = rand() % gridSize;
		T.position.y = rand() % gridSize;
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
		// throw snow ball (see instructions for details)
		for (auto &T : Targets)
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
int throwSnowball(Coords p, MyStruct &Target)
{
	int aDistance;
	//   compare to the target's position
	if (p.x == Target.position.x)
	{
		if (p.y == Target.position.y)
		{
			Target.hit = true;
			return 0;
		}
		else
		{
			return abs(p.y - Target.position.y);
		}
	}
	else
	{
		aDistance = abs(p.x - Target.position.x);
		if (aDistance < abs(p.y - Target.position.y)) aDistance = abs(p.y - Target.position.y);
		return aDistance;
	}
}

//  Move the target
void moveTarget(MyStruct &Target)
{
	enum MyEnum
	{
		North, East, South, West, Stay
	};
	bool moveNotFound = true;
	MyEnum ranNum = MyEnum(rand() % 5);
	if (ranNum == Stay) return;
	while (moveNotFound)
	{
		switch (ranNum)
		{
		case North:
			if (Target.position.y == 0)	break; // can't move North
			Target.position.y--;
			cout << Target.ID << " moving North." << endl;
			return;
		case East:
			if (Target.position.x == gridSize - 1)	break; // can't move East
			Target.position.x++;
			cout << Target.ID << " moving East." << endl;
			return;
		case South:
			if (Target.position.y == gridSize - 1)	break; // can't move South
			Target.position.y++;
			cout << Target.ID << " moving South." << endl;
			return;
		case West:
			if (Target.position.x == 0)	break; // can't move West
			Target.position.x--;
			cout << Target.ID << " moving West." << endl;
			return;
		default:
			break;
		}
		ranNum = MyEnum(int(ranNum + 1) % 4);
	}
}

//--end of function definitions------

//----------------------------------
