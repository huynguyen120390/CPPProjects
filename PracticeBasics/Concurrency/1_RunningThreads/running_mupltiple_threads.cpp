#include <iostream>
#include <thread>
#include <vector>

void print_hello(){
    std::cout << "Hello from Worker thread #" <<std::this_thread::get_id() <<std::endl;

}

int main(){
    std::vector<std::thread> threads;
    for(size_t i = 0; i < 5; ++i){
        //copying thread objects causes a compile error
        /*
            std::thread t(print_hello);
            threads.push_back(t);
        */
       threads.emplace_back(std::thread(print_hello)); //emplace_back() apply move semantices 
    }
    std::cout <<"Hello from main thread #" << std::this_thread::get_id() <<std::endl;

    for(auto &t: threads){
        t.join();
    }

    return 0;
}