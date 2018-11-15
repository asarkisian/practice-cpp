#ifndef _MY_CLASS_H
#define _MY_CLASS_H

#include <string>

using std::string;

typedef string name_t;

class MyClass{

    public:

        // constructors
        MyClass();
        MyClass(string n);

        // destructors
        ~MyClass();

        // modifiers

        // accessors
        string return_name() const;

    private:
        name_t name;
};

#endif
