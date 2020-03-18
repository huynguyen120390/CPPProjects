#include <iostream>
#include <memory>

int main(){
    std::shared_ptr<int> mySharedPtr(new int);
    std::cout << "shared pointer count =" << mySharedPtr.use_count() <<std::endl;
    std::weak_ptr<int> myWeakPtr1(mySharedPtr);
    std::weak_ptr<int> myWeakPtr2(myWeakPtr1);

    std::cout << "shared pointer cout =" << mySharedPtr.use_count() << std::endl;

    //Creating weak point not relied on a shared or another weak pointer cause Compile Error 
    //std::weak_ptr<int> myWeakPtr3(new int) 
}