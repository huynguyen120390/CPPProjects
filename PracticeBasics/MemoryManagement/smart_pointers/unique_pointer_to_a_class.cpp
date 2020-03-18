#include <iostream>
#include <memory>
using namespace std;
class MyClass{
    private:
        std::string _text;
        int _num;
    public:
        MyClass(){}
        MyClass(std::string text){_text = text;}
        ~MyClass(){std::cout << _text <<" destroyed"<<std::endl;}//with unique_pointer we dont need to use 'delete'}
        void set_text(std::string text){_text = text;}   
        std::string get_text(){return _text;}
        void set_num(int num){_num = num;}
        int get_num(){return _num;}
};

int main(){
    // std::unique_ptr<MyClass> myClassPtr1(new MyClass());//create a unique pointer called myClassPtr1, and point to a new MyClass obj on heap
    // std::unique_ptr<MyClass> myClassPtr2(new MyClass("String2 "));//same as above, but for myClassPtr1, and put "String here" in the obj
    // myClassPtr1->set_text("String1 ");
    // myClassPtr1->set_num(1); //set ptr1 num as 1
    // myClassPtr2->set_num(2); //set ptr2 num as 2
    // *myClassPtr1 = *myClassPtr2; //assign ALL pointee content of myClassPtr2 to myClassPtr1
    // std::cout << myClassPtr1->get_text() << " " << myClassPtr1.get() << std::endl;
    // std::cout << myClassPtr1->get_num() << std::endl;
    std::unique_ptr<MyClass> ptr1 (new MyClass());
    

}