#include <iostream>
#include <stdlib.h>
/**
 * The idea of this policy is to transfer values of instances from Source class to Destination class
 * The pointers to those values in Source class will be set to nullptr to give up ownership
 * */
class ExclusiveCopy{
    private:
        int *myInt;
    public:
        ExclusiveCopy(){
            myInt = (int*) malloc(sizeof(int));
            std::cout << "resource allocated" << std::endl;
        }
        ~ExclusiveCopy(){
            if(myInt != nullptr){
                free(myInt);
                std::cout << "resource freed" << std::endl;
            }
        }
        ExclusiveCopy(ExclusiveCopy &source){
            myInt = source.myInt; // note the dot , although myInt is private, but we are in the context of this class
                                 // transfer
            source.myInt = nullptr;//set to null to give up ownership
        }
        ExclusiveCopy &operator=(ExclusiveCopy &source){
            myInt = source.myInt; //transfer
            source.myInt = nullptr; //set to null, to give up ownership
            return *this;
        }
};

int main(){
    ExclusiveCopy source;
    ExclusiveCopy destination(source);
}