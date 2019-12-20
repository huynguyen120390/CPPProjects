/**
 * 
 * 
 * 
 * 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
    public:
        string color = "color";
        string name = "name";
        int age = 0;
        int leg = 0;

        void make_sound() const {cout << "animal";}
};

class Leg{
    public:
        string color = "color";
        bool has_toe = false;
        bool has_nail = false;
};

class Snake : public Animal{
    public:
        float length = 0;
        void make_sound() const {cout << "hiss";}
};

class Cat : public Animal{
    public:
        float height = 0;
        void make_sound() const {cout << "meow";}
        Cat() : legs(4,Leg()){}
    private:
        vector <Leg> legs;
};

int main(){
    Snake snake;
    Cat cat;
    snake.make_sound();
    cat.make_sound();
}


