#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Car{
    public:
        string Drive() { return "I'm driving";}


};

class Boat{


};

class AmphibiousCar : public Boat, public Car{};

int main(){

}