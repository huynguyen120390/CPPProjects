#include <iostream>
#include <thread>

int main()
{
    int id = 0;

    auto f1 = [&id](){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Call by ref id=" << id << " at " << &id << std::endl; 
    };

    auto f2 = [id]() mutable {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        //std::cout << "Call by val id=" << id  << " at " << &id << std::endl;
        std::cout << "Call by val id=" << ++id  << " at " << &id << std::endl;
    };

    std::thread t1(f1);
    std::thread t2(f2);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Main thread " << id << " at " << &id << std::endl;


    t1.join();
    t2.join();
    


    return 0;
}