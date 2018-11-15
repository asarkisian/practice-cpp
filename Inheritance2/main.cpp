#include <iostream>

using std::cout;
using std::endl;

class Being{

    public:
        // default constructor
        Being()
            :our_is_alive(true),
             my_is_ethereal(true)
        { 
            cout << "Being: Constructor" << endl;
        }

        // overloaded constructor(s)
        Being(bool ia, bool ie)
            :our_is_alive(ia),
             my_is_ethereal(ie)
        { 
            cout << "Being: Overloaded Constructor" << endl;
        }

        // destructor
        ~Being(){ cout << "Being: Destructor" << endl; }

        // modifier(s)

        // accessor(s)
        bool is_alive() const
        {
            return(our_is_alive);
        }

    protected:
        bool our_is_alive;

    private:
        bool my_is_ethereal;
};


class Human : public Being{

    public:
        Human(){ cout << "Human: Constructor" << endl; }

        ~Human(){ cout << "Human: Destructor" << endl;  }
};


int main(int argc, char** argv){

    Human* h = new Human();

    cout << h->is_alive() << endl;

    delete h;

    return(0);
}
