#include <iostream>

int main(){
    double den[] = {1.0,2.0,3.0,4.0};
    for(size_t i = 0; i < 5; ++i){
        double *en = new double(i); // malloc and create a new double with value of i 
        std::cout << *en << "/" << den[i] << "=" << *en/den[i] << std::endl;
        delete en;//free and delete en 
    }
    return 0;
}