#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

void divideByNumber(std::promise<double> && prms, double num, double denom){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    try{
        if(denom == 0){
            throw std::runtime_error("Exception from Thread : DVision by Zero");
        }else{
            prms.set_value(num/denom);
        }

    }catch(...){
        prms.set_exception(std::current_exception());
    }
}

int main(){
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    double num = 42.0, denom = 0.0;

    std::thread t(divideByNumber,std::move(prms), num, denom); //when the error is encountered, it is wait to throw out
    try{
        double result = ftr.get(); // this is where the error thrown out 
        std::cout << "Result = " << result << std::endl;
    }catch(std::runtime_error e){
        std::cout << "There error is " << e.what() <<std::endl;
    }
    t.join();
    return 0;
}