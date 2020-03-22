//Using std::async , the system will decide if the function will be run synchronously or asunchronously
#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom){
    std::cout << "Worker thread id =" << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if(denom == 0){
        throw std::runtime_error("Exception from thread: Division by Zero");
    }
    return num/denom;
}

int main(){
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;
    double num = 42.0, denom = 2.0;
    //The argument std::launch::deferred makes the thread divideByNumber not diverge, 
    //Main thread id = 0x1131bddc0
    //Worker thread id =0x1131bddc0
    //
    std::future<double> ftr = std::async(std::launch::deferred,divideByNumber, num, denom);
    try{
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }catch(std::runtime_error e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}