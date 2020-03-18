#include <iostream>
#include <memory>

int main(){
    std::unique_ptr<int> uniquePtr(new int); // create a unique ptr 

    std::shared_ptr<int> sharedPtr = std::move(uniquePtr); //move resource of a unique ptr to a shared ptr 

    std::weak_ptr<int> weakPtr(sharedPtr); //point weak pointer to shared pointer

    std::shared_ptr<int> sharedPtr2 = weakPtr.lock();

    int *rawPtr = sharedPtr2.get(); // co-point a new raw pointer to that of a shared pointer
    //Deallocating raw pointer which pointing to a shared pointer , will cause Run Time Error
    //because the shared pointer will deallocate itself when leaving the scope 
    //At nothing else left to deallocate , so avoid do this conversion, and stick with shared pointer 
    delete rawPtr; 
    return 0;

}