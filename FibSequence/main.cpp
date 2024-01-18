// ————————————————

// GENERATE FIBONNACI SEQUENCE

#include <iostream>
#include <vector>

using namespace std;

vector<int> getFibSequence(int maxFib) {
    int a = 1;
    int b = 0;
    int c = 0;
    
    vector<int> seq;

    for (int i = 0; i < maxFib; i++) {
        c = a + b;
        seq.push_back(c);
        a = b;
        b = c;
    }

    return seq;
}

int main() {
    int MAX_FIB = 15;
    vector<int> seq = getFibSequence(MAX_FIB);
    
    for(int fib : seq) {
      cout << fib << ", ";
    }
}
