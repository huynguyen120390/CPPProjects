#include <iostream>
#include <thread>

void print_message(std::string message){
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Thread 1: " << message << std::endl;
}

int main(){
    //define message 
    std::string message = "My Message";

    //start thread using variadic templates
    std::thread t1(print_message,message);

    //start thread using a Lambda
    std::thread t2([message]{
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Thread 2 " << message << std::endl;
    });

    //thread barrier
    t1.join();
    t2.join();
}