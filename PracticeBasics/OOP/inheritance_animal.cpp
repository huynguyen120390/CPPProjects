/**
 * 
 * 
 * 
 * 
*/

#include <iostream>
#include <string>

using namespace std;

class Animal{
    public:
        string color = "color";
        string name = "name";
        string age = "0";
        void make_sound() const {cout << "animal";}
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
};

int main(){
    Snake snake;
    Cat cat;
    snake.make_sound();
    cat.make_sound();
}


