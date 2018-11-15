#include <iostream>

using std::cin;
using std::cout;
using std::endl;


char calc_grade(double p){

    char lg = ' ';

    if(p >= 0 && p <= 59){
        lg = 'F';
    }
    else if(p >= 60 && p <= 69){
        lg = 'D';
    }
    else if(p >= 70 && p <= 79){
        lg = 'C';
    }
    else if(p >= 80 && p <= 89){
        lg = 'B';
    }
    else if(p >= 90 && p <= 99){
        lg = 'A';
    }
    else{
        lg = '?';
    }

    return(lg);
}

int main(int argc, char** argv){

    double percentage = 0.0;
    char letter_grade = ' ';

    cout << "Enter student\'s percentage: ";
    cin >> percentage;

    letter_grade = calc_grade(percentage);

    cout << "Student\'s grade: " << letter_grade << endl;

    return(0);
}
