#include <iostream>
#include <thread>
#include <vector>

void print_hello(){
    std::cout << "Hello from Worker thread #" <<std::this_thread::get_id() <<std::endl;

}
/**
 * Note the code below has a problem about order of executions
 * Out put:  
    Hello from main thread #Hello from Worker thread #Hello from Worker thread #Hello from Worker thread #0x700002c590000x700002bd6000
    0x115c7bdc0
    Hello from Worker thread #0x700002ad0000
    0x700002cdc000
    Hello from Worker thread #0x700002b53000
* It is disordered
*/
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