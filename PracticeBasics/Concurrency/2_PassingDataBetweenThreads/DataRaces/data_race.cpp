#include <iostream>
#include <thread>
#include <future>

class Vehicle{
    public:
        Vehicle(): _id(0){
            std::cout << "Vehicle #" << _id << "Default constructor called " <<std::endl;
        }
        Vehicle(int id) : _id(id){
            std::cout << "Vehicle #" << _id << "Initializing constructor called " << std::endl;
        }
        void set_id(int id){_id = id;}
        int get_id(){return _id;}

    private:
        int _id;
};

int main(){
    Vehicle v0;
    Vehicle v1(1);

    std::future<void> ftr = std::async([](Vehicle v){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        v.set_id(2);
    },v0);
    v0.set_id(3);
    ftr.wait();
    std::cout << "Vehicle #" << v0.get_id() <<std::endl;
    return 0;
}