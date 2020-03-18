#include <thread>
#include <vector>

int main(){
    std::vector<std::thread> threads;
    int nThreads = 4;
    //start all threads
    for(int i = 0; i < nThreads; ++i){
        threads.emplace_back(std::thread([](){while(true);}));
    }

    std::for_each(threads.begin(),threads.end(),[](std::thread &t){
        t.join();
    });
    