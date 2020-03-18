#include <iostream>
#include <thread>
#include <future>

void modify_message(std::promise<std::string> && promise, std::string message){
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::string modifiedMessage = message + "has been modified";
    promise.set_value(modifiedMessage); // ready to pass data to the future port, wait for the future call it
    std::cout << "ready to pass data to the future port, wait for the future call it, now waiting" << std::endl;
 }

int main(){
    //define message
    std::string messageToThread = "My message";

    //create promise and future
    //Set a promise port of passing data , set a future port to receive data
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future();

    //start thread and pass promise as argument
    //Promises can not be copied, because the promise-future concept
    // is a two-point communication channel for one-time use. 
    //Therefore, we must pass the promise to the thread function using std::move.
    std::thread t(modify_message,std::move(promise),messageToThread);
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    //print original message to console 
    std::cout << "Original Message from Main()" << messageToThread << std::endl;

    //retrieve modified message via future and print to console
     // notice the timing, set_value() before get(), when reach get(), the data will passed immediately
     //if set_value() before get(), when reach get(), the thread with get() will be hung to wait 
    std::string messageFromThread = future.get(); //receive data , this thread will be hold here to wait for data from promise
    std::cout << "Modified Message from thread()" << messageFromThread << std::endl;

    //thread barrier
    t.join();

    return 0;
}