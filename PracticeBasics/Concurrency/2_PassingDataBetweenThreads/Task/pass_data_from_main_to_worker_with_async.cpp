#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if(denom == 0){
        throw std::runtime_error("Exception from thread: Division by Zero");
    }
    return num/denom;
}

int main(){
    double num = 42.0, denom = 0.0;
    // with async , no need to make promise things, and threads
    //Eg: std::promise<double> prms;
    //std::future<double> ftr = prms.get_future();
    //std::thread t(divideByNumber, std::move(prms),num,denom)
    //and codes in divideByNymber such as args of std::promise<double> && prms

    std::future<double> ftr = std::async(divideByNumber, num, denom); 
    try{
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }catch(std::runtime_error e){
        std::cout << e.what() <<std::endl;
    }
}