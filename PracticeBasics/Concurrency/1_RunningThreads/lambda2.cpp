#include <iostream>
#include <stdio.h>

int main()
{
    int id = 0; // Define an integer variable

    // capture by reference (immutable)
    auto f0 = [&id]() { std::cout << "a) ID in Lambda = " << id << " at " << &id << std::endl; }; 

    // capture by value (mutable)
    auto f1 = [id]() mutable { std::cout << "b) ID in Lambda = " << ++id << std::endl; };
    f1(); //1 // call the closure and execute the code witin the Lambda
    std::cout << "c) ID in Main = " << id << std::endl; // 0, because id in f1 is passed by value

    // capture by reference (mutable)
    auto f2 = [&id]() mutable { std::cout << "d) ID in Lambda = " << ++id << std::endl; };
    f2(); //1
    std::cout << "e) ID in Main = " << id << " at " << &id << std::endl; //1
    
    // pass parameter 
    auto f3 = [](const int id) { std::cout << "f) ID in Lambda = " << id << " at " << &id << std::endl; };   
    f3(++id);//2

    // observe the effect of capturing by reference at an earlier point in time
    f0(); //2
    //Output:
    // b) ID in Lambda = 1
    // c) ID in Main = 0
    // d) ID in Lambda = 1
    // e) ID in Main = 1 at 0x7ffeeedd0888
    // f) ID in Lambda = 2 at 0x7ffeeedd0834
    // a) ID in Lambda = 2 at 0x7ffeeedd0888

    return 0;
}