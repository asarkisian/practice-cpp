#include <iostream>

using std::cout;
using std::endl;


class HelloWorld{

    public:
    void say_hello(){
        cout << "Hello, World!" << endl;
    }
};

int main(int argc, char** argv){

    HelloWorld hw;

    hw.say_hello();

    return(0);
}
