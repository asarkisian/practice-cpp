#include <iostream>

using namespace std;

/*
x y     total

0+1 =   1
1+1 =   2
1+2 =   3
2+3 =   5
3+5 =   8
5+8 =   13
8+13 =  21
13+21 = 34
21+34 = 55
34+55 = 89
55+89 = 144
*/

int main(int argc, char** argv){

    int count = 0;
    int x=0, y=1, total=0;

    cout << "Fibonacci Sequence: "; 

    while(count < 11){
        total = x+y;
        cout << total << ", ";

        x = y;
        y = total;

        count = count + 1;
    }

    return(0);
}
