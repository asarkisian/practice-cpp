#include <iostream>

using namespace std;


class Being{

    public:
        Being()
        {
            cout << "Constructor: Being" << endl;
        }

        ~Being()
        {
            cout << "Destructor: Being" << endl;
        }
};


class Monster : Being{

    public:
        Monster()
        {
            cout << "Constructor: Monster" << endl;
        }

        ~Monster()
        {
            cout << "Destructor: Monster" << endl;
        }
};


class Beast : Monster{
    public:
        Beast()
        {
            cout << "Constructor: Beast" << endl;
        }

        ~Beast()
        {
            cout << "Destructor: Beast" << endl;
        }
};


class Human : Being{

    public:
        Human()
        {
            cout << "Constructor: Human" << endl;
        }

        ~Human()
        {
            cout << "Destructor: Human" << endl;
        }
};


int main(int argc, char** argv){

    Beast* b = new Beast();
    delete b;

    return(0);
}
