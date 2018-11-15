#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class Car{

    public:
        Car(string, string);
        ~Car();

    // modifiers
    bool turn_on();
    void increase_speed(unsigned int);
    void decrease_speed(signed int);

    // accessors
    void display_speed()const;
    void display_specs()const;

    private:
        bool is_on;
        unsigned int speed;
        string color;
        string body_type;
};


Car::Car(string clr, string bt)
    :is_on(false),
     speed(0),
     color(clr),
     body_type(bt)
{}


Car::~Car(){}


bool Car::turn_on(){

    is_on = true;

    cout << "The car is now powered on!" << endl;

    return(is_on);
}


void Car::increase_speed(unsigned int amount){

    // modify speed only if the car is in motion
    if(is_on){
        if(amount <= 0){
            cout << "Cannot increase without a proper speed amount!" << endl;
        }
        else{
            speed += amount;
        }
    }
    else{
        cout << "The car is not powered on!" << endl;
    }
}



void Car::decrease_speed(signed int amount){

    // modify speed only if the car is in motion
    if(is_on){
        if(amount < 0){
            cout << "Cannot decrease without a proper speed amount!" << endl;
        }
        else{
            speed -= amount;
        }
    }
    else{
        cout << "The car is not powered on!" << endl;
    }
}


void Car::display_speed()const{

    cout << "Car is driving: " << speed << " MPH!" << endl;
}
    

void Car::display_specs()const{

    cout << "Car color is: " << color << "!" << endl;
    cout << "Body type is: " << body_type << "!" << endl;
}



int main(int argc, char** argv){

    Car honda_civic1 = Car("Yellow", "Coupe");

    honda_civic1.turn_on();
    honda_civic1.increase_speed(25);
    honda_civic1.display_speed();
    honda_civic1.decrease_speed(10);
    honda_civic1.display_speed();
    honda_civic1.display_specs();


    return(0);
}
