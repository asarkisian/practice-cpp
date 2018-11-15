#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::rand;
using std::srand;

class GuessingGame{

    public:
        // constructor/destructor
        GuessingGame();
        GuessingGame(int, int);
        ~GuessingGame();

        // modifiers
        void play_game();
        
        //accessors

    private:
        unsigned int random_range;
        unsigned int chances;

        unsigned int secret_number;
        int user_number;
};


GuessingGame::GuessingGame()
{
}


GuessingGame::GuessingGame(int r, int c)
     :random_range(r),
      chances(c),
      secret_number(0),
      user_number(0)
{
    srand(time(NULL));

    secret_number = rand() % random_range + 1;
}


GuessingGame::~GuessingGame()
{
}


void GuessingGame::play_game()
{
    unsigned int count = 0;

    while(user_number != secret_number){

        cout << "You have " << chances << " chances left" << endl;
        cout << "Guess the number: ";
        cin >> user_number;

        if(user_number == secret_number){
            cout << "You win!" << endl;
            break;
        }

        cout << "Try again, you are too ";
        if(user_number < secret_number){
            cout << "low!" << endl;
        }
        else{
            cout << "high!" << endl;
        }

        chances = chances - 1;

        if(chances <= 0){
            cout << "Sorry you lose. The answer was: " << secret_number << endl;
            break;
        }

    }

    return;
}


int main(int argc, char** argv){

    if(argc == 1){

        cout << "You need to specify RANGE and CHANCES" << endl;
        cout << "For Example: guessinggame 10000 10" << endl;
    }
    else if(argc == 2){
        cout << "You need to also specify CHANCES" << endl;
        cout << "For Example: guessinggame 10000 10" << endl;
    }
    else{

        try{

            unsigned int random = atoi(argv[1]);
            unsigned int chances = atoi(argv[2]);

            // instantiate the object
            GuessingGame* my_game = new GuessingGame(random, chances);

            // play the game
            my_game->play_game();

            // release the object
            delete my_game;
        }
        catch(const exception& e){
            // display the specific error message
            cerr << e.what() << endl;
        }
        catch(...){
            // display unknokwn error message
            cerr << "Unknown internal error!" << endl;
        }
    }

    return(0);
}
