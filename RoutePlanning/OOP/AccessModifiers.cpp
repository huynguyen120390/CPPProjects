/*
Access Modifiers like public, private, protected allow users allowances to access to data 
*/
#include <iostream>
#include <string>

class Animal{
    public:
        void say() const {std::cout <<"Talk\n";}

};

class Human : public Animal{ //Human inherits all Animal members, 
    public:
        void talk(std::string content) const {std::cout << content << "\n";}
};

class Baby : private Human{ //Baby inherits a
    public:
        void cry() {talk("Whaaa!");}
};

int main(){
    Human human;
    human.talk("Hello!");
    human.say();
    Baby baby;
    baby.cry();

    //baby.talk("Hello dad!"); 
    //This won't work, class Baby inherits public members from private class Human to define the members of Baby class
    //But when Baby class becomes an object, we can't explicitly call Human members any more, but implicitly

}