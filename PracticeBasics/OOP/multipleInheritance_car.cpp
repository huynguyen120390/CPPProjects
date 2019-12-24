#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Car{
    public:
        string Drive() { return "I'm driving";}
};

class Boat{
    public:
        string Cruise() { return "I'm cruising";}
};

class AmphibiousCar : public Boat, public Car{};

int main(){
    Car car;
    Boat boat;
    AmphibiousCar duck;
    assert(duck.Drive() == car.Drive());
    assert(duck.Cruise() == boat.Cruise());
}