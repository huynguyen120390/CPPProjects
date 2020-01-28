#include <iostream>

class MyInt{
    int *_p;
    public:
        //create a constructor passing null pointer
        MyInt(int * p = NULL){ _p = p;}
        //create a destructor to deallocate
        ~MyInt(){
            std::cout <<"Resource "<< *_p <<" Deallocated"<<std::endl;
            delete _p;
        }
        
        //create an operator overloading * 
        int &operator*(){return *_p;}
};

int main(){
    double den[] = {1.0,2.0,3.0,4.0,5.0};
    for(size_t i = 0; i < 5; i++){
        MyInt en(new int(i));
        std::cout << *en << "/"<<den[i]<<"="<<*en/den[i]<<std::endl;
    }
    return 0;
}