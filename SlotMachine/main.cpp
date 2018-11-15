// Week 7 Assignment-1
// Description: 
//----------------------------------

//**begin #include files************
#include <iostream> // provides access to cin and cout
#include <iomanip>
#include <array>
#include <vector>
#include <sstream>
#include <fstream>
//--end of #include files-----------
//----------------------------------

using namespace std;
//----------------------------------

//**begin global constants**********
// number of positions on a reel (10)
const int reelPositions = 10;
// create enum for symbols
enum symbol
{
    Lemon, Cherry, Orange, Bell, Bar, Jackpot
};


// define a struct for slot machine wheel
struct Wheel
{
    array <string, reelPositions> symbols;
    array <symbol, reelPositions> eSymbols;
    int position;
    string selected;
};//--end of global constants---------
//----------------------------------

//**begin function prototypes*******
void loadWinSheet(vector <array <int,4> > &);
int check4Win(vector <int>, vector <array <int,4> > &, int);
//void createSlotMachine(array <Wheel, 3> &);
//--end of function prototypes------
//----------------------------------

//**begin main program**************
int main()
{
    // seed random number generator
    srand(time(NULL));
    // create the payout table
    // define a vector for the payout table
    vector <array <int,4> > winSheet;
    loadWinSheet(winSheet);
    //create an array of three slot machine wheels
    array <Wheel, 3> slotMachine =
    {
        {
            { 
                {"Orange", "Cherry", "Orange", "Lemon", "Orange", "Bar", "Lemon", "Bell", "Jackpot", "Bell"},
                {Orange, Cherry, Orange, Lemon, Orange, Bar, Lemon, Bell, Jackpot, Bell},
                0,"Orange"
            },
            {
                {"Bell", "Lemon", "Orange", "Bar", "Jackpot", "Bar", "Lemon", "Cherry", "Jackpot", "Bell"},
                {Bell, Lemon, Orange, Bar, Jackpot, Bar, Lemon, Cherry, Jackpot, Bell},
                1,"Lemon"
            },
            {
                {"Cherry", "Lemon", "Bar", "Lemon", "Orange", "Orange", "Lemon","Cherry", "Jackpot", "Bell"},
                {Cherry, Orange, Bar, Lemon, Orange, Orange, Lemon, Cherry, Jackpot, Bell},
                3,"Bar"
            }
        }
    };

    bool gameOn = true;
    int thePot = 100;
    int bet = 1;
    bool winner = false;
    int winnings = 0;
    char checkKey ='\n';
    vector <int> combo;
    cout << "Hit 'enter' to bet. Hit 'space' and 'enter' to quit." << endl;
    while (gameOn)
    {
        for (auto &s: slotMachine)
        {
            s.position =(s.position + rand()%reelPositions)%reelPositions;
            s.selected = s.symbols[s.position];
            cout << setw(10) << left << s.selected.c_str() ;
            combo.push_back(s.eSymbols[s.position]);
        }
        winnings = check4Win( combo, winSheet, -bet);
        if (winnings > 0) cout << "You win " << winnings << "!   ";
        thePot += winnings;
        cout << "You now have $" << thePot << endl;
        combo.clear();
        cout << endl;
        if (thePot <= 0) gameOn = false;
        cin.get(checkKey);
        if (checkKey != '\n') gameOn = false;
    }
    while (!cin.get()){};
    if (winner) cout << "You walk away a winner." << endl;
    else if (thePot > 0) cout << "Good bye." << endl;
    else cout << "You have lost all your money." << endl;
    // Wait for user input to close program when debugging.
    cin.get();
    return 0;
}
//--end of main program-------------
//----------------------------------

//**begin function definitions******
// loads the pattern payout table from a text file
void loadWinSheet(vector <array <int,4> > &pT)
{
    stringstream myStream;
    ifstream inFile;
    string myString;
    array <int, 4> combo;
    int pay;
    inFile.open("paytable.txt");
    if (inFile.is_open())
    {
        while ( getline (inFile,myString) )
        {
            myStream << myString;
        }
        inFile.close();
    }
    else{
      cerr << "Error: File paytable.txt not found!" << endl;
      exit(EXIT_SUCCESS);
    
    }
    while (!myStream.eof())
    {
        myStream >> combo[0] >> combo[1] >> combo[2] >> combo[3];
        pT.push_back(combo);

    }
    return;
}
// Check for winning patterns
int check4Win(vector <int> pattern, vector <array <int,4> > &pT, int theBet)
{
    for(auto p: pT)
    {
        if (((pattern[0] == p[0]) && (pattern[1] == p[1]) ) && (pattern[2] == p[2]))
        { 
          return p[3];
        }
        if ((pattern[1] == Cherry) && (pattern[2] == Cherry))
        {
          return 3;
        }
        if (pattern[2] == Cherry)
        { 
          return 1;
        }
    }
    
    return -1;
}
//--end of function definitions------
//----------------------------------
