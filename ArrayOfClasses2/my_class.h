#ifndef _MY_CLASS_H_
#define _MY_CLASS_H_

#include <string>

using std::string;

typedef string name_t;

class MyClass{

    public:
        // constructor(s)
        MyClass();
        MyClass(name_t);

        // destructor(s)
        ~MyClass();

        // modifier(s)
        void change_name(const name_t);

        // accessor(s)
        name_t get_name() const;

    private:
        name_t my_name;
};

#endif
