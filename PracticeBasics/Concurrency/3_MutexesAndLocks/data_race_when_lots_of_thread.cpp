/*
It seems that not all the vehicles could be added to the queue. 
But why is that? Note that in the thread function "pushBack" there is a call to sleep_for, 
which pauses the thread execution for a short time. This is the position where the data race occurs: 
First, the current value of _tmpVehicles is stored in a temporary variable oldNum, 
even without oldNum the result might not be much better. 
While the thread is paused, there might (and will) be changes to _tmpVehicles performed by other threads. 
When the execution resumes, the former value of _tmpVehicles is written back, thus invalidating the contribution 
of all the threads who had write access in the mean time. Interestingly, when sleep_for is commented out, 
the output of the program is the same as with std::launch::deferred - 
at least that will be the case for most of the time when we run the program. 
But once in a while, there might be a scheduling constellation which causes the bug to expose itself
*/
#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <algorithm>
#include <mutex>

class Vehicle{
    public:
        Vehicle(int id):_id(id){}

    private:
        int _id;
};

class WaitingVehicles{
    public:
        WaitingVehicles(): _tmpVehicles(0){}

        void printSize(){
            std::cout << "Vehicle = " << _tmpVehicles <<std::endl;
        }

        void pushBack(Vehicle &&v){
           // _mutex.lock();  //Use mutex to prevent other threads access to the resource, othe threads will be on hold
            int oldNum = _tmpVehicles;
            std::this_thread::sleep_for(std::chrono::microseconds(1));
            _tmpVehicles = oldNum + 1;
            //_tmpVehicles = _tmpVehicles + 1;
          // _mutex.unlock(); //Allow 
        }
    
    private:
        int _tmpVehicles;
        //std::mutex _mutex;
};

int main(){
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
    std::vector<std::future<void>> futures;
    for(int i = 0; i < 1000 ; ++i){
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async,&WaitingVehicles::pushBack,queue,std::move(v)));
    }
    std::for_each(futures.begin(),futures.end(),[](std::future<void> &ftr){
        ftr.wait();
    });
    queue->printSize();
    std::cout << "End" <<std::endl;
}