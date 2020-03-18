#include <iostream>
#include <thread>

class Vehicle{
    public:
        Vehicle(int id): _id(id){}
        void operator()(){
            std::cout << "Vehicle #" << _id << " has been created\n" <<std::endl;
        }
    private:
        int _id;
};

int main(){
    std::thread t1 = std::thread(Vehicle(1));
    t1.join();
    std::thread t2 = std::thread(Vehicle(2));
    t2.join();
    std::thread t3 = std::thread(Vehicle(3));
    t3.join();
    std::cout << "Finished work in main\n";
    return 0;

    
}