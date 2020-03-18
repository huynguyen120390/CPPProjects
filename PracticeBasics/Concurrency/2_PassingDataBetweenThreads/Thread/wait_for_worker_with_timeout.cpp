#include <iostream>
#include <thread>
#include <future>
#include <cmath>

void computeSqrt(std::promise<double> &&prms, double input){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    double output = sqrt(input);
    prms.set_value(output);
}

int main(){
    double inputData = 42.0;
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(computeSqrt,std::move(prms), inputData);

    auto status = ftr.wait_for(std::chrono::milliseconds(1000));
    if(status == std::future_status::ready){
        std::cout << "Result = " << ftr.get() << std::endl;
    }else if(status == std::future_status::timeout){
        std::cout << "Timeout"  << std::endl;
    }else if(status == std::future_status::deferred){
        std::cout << "Thread has not started" <<std::endl;
    }
    else{
        std::cout << "Some error" << std::endl;
    }

    t.join();
    return 0;
}