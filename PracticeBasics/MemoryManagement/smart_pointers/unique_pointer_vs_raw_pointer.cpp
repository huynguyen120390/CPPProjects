#include <memory>
#include <iostream>
using namespace std;

void raw_pointer(){
    //create a raw pointer on the heap
    int *raw = new int;
    //assign a value
    *raw = 22;
    //delete the resource again
    delete raw;

}

void unique_pointer(){
    std::unique_ptr<int> uniPtr(new int);
    *uniPtr = 23;
} //when this scope is done C++ will deallocate the pointer