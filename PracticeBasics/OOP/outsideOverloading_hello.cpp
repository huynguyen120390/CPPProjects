#include <iostream>
using namespace std;
void hello(){
    cout << "Hello, Wolrd!";
}
class Human{
};

void hello(Human human){

}

void hello(int age){
    if(age < 18){
        cout << "I'm a kid";
    }else if(age > 18 && age < 35){
        cout << "I'm young adult";
    }else if(age > 35){
        cout << "I'm getting old";
    }
}

void hello(float height){
    if(height > 5){
        cout << "I'm tall";
    }else{
        cout << "I'm short";
    }
}
int main(){
    hello(2);
}