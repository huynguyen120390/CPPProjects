/**
 * Vehicle -> Car 
 * Vehicle -> Bike
 * 
 * Inheritance rules:
 *      public parent -> child takes traits to define , and allowed to explitly use traits if the child becomes object
 *      private parent -> child takes traits to define itself, not allowed to use parents explitcitly if the child become object
 *      protected parent -> ??/
 * 
 * Encapsulation rules:
 *      public : instances & functions:
 *                +  used to define the class itself
 *                +  explicitly accessable when the class becomes object
 *                +  inheritable.
 *      private : instances & functions:
 *                + used to define the class itself
 *                + accessed through setters/getters of the class itself
 *                + accessed by friends
 *                + inheritable. 
 *      protected : instances & functions:
 *                + used to define the class itself
 *                + accessed through setters/getters of the class itself
 *                + accessed by ....
 *                + inheritable
 *              
 * 
 * 
 * 
 * 
 * 
*/

#include <iostream>
#include <string>
using std::string;
using std::cout;

class Vehicle{
    private:
        int wheel = 0;
        string color = "blue";
    public:
        void repr() const{
            cout << "Vehicle has " << this->wheel << " and color of " << this->color;
        }
};

class Car: public Vehicle{
    private:
        bool sunroof = true;
    public:
        void set_sunroof(bool v){
            this->sunroof = v;
        }
        bool get_sunroof(){
            return this->sunroof;
        }

};

class Bike: private Vehicle{
    private:
        bool kickstand = true;
    public:
        void set_kickstand(bool v){
            this->kickstand = v;
        }
        bool get_sunroof(){
            return this->kickstand;
        }
};

class Scooter: protected Vehicle{
    private:
        bool electric_engine = true;
    public:
        void set_electric_engine(bool v){
            this->electric_engine = v;
        }

        bool get_electric_enginer(){
            return this->electric_engine;
        }
};

int main(){
    Car car;
    car.set_sunroof(true);

    Bike bike;
    car.repr();
}