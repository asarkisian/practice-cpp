#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    enum {POSITIVE, NEGATIVE};
    int charge = NEGATIVE;
    int charge2 = POSITIVE;

    enum numbers{ONE, TWO, THREE};
    cout << ONE;
    cout << TWO;

    typedef enum{BLACK, RED} colors;
    colors my_color = BLACK;
    colors my_color2 = RED;

    return(0);
}
