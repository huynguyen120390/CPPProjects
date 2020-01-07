/**
 * To measure runtime, we can use chrono lib
 * 
 */
#include <chrono>
#include <iostream>
template <typename T>
void measure_in_microseconds(T t1, T t2);
template <typename T>
void measure_in_nanoseconds(T t1, T t2);

int main(){
    const int size = 4;
    static int x[size][size];

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            x[j][i] = i+ j;
           // std::cout << &x[i][j] << ": i=" << i << ", j=" << j <<std::endl;
        }
    }
   
    auto t2 = std::chrono::high_resolution_clock::now();
    //std::cout << typeid(t1).name() << "\n";  // NSt3__16chrono10time_pointINS0_12steady_clockENS0_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE
    measure_in_microseconds(t1,t2);
    measure_in_nanoseconds(t1,t2);
    
    return 0;
}

template <typename T>
void measure_in_microseconds(T t1, T t2){
    //Measure in microseconds
    auto duration = std::chrono::duration_cast <std::chrono::microseconds> (t2-t1).count();
    std::cout << "Excution time: " << duration << " microseconds" << std::endl;
};

template <typename T>
void measure_in_nanoseconds(T t1, T t2){
    auto duration = std::chrono::duration_cast <std::chrono::nanoseconds> (t2-t1).count();
    std::cout << "Excution time: " << duration << " nanoseconds" << std::endl;
};