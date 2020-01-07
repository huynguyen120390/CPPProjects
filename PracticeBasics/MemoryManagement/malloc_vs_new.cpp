#include <iostream>
#include <stdlib.h>

class MyClass{
    private:
        int * _number;
    public:
        MyClass(){//Constructor
            std::cout << "Allocate memory\n";
            this->_number = (int *)malloc(sizeof(int));
        }

        ~MyClass(){//Destructor 
            std::cout << "Delete memory\n";
            free(_number);
        }

        void set_number(int number){
            *this->_number = number;
            std::cout << "Number: " << _number << "\n";
        }
};

int main(){
    //Comment out either code snippets to run
    /**
     * With malloc, the program crashes on calling the method setNumber,
     *  as no memory has been allocated for _number - because the constructor 
     * has not been called. Hence, an EXC_BAD_ACCESS error occurs, 
     * when trying to access the memory location to which _number is pointin
     **/
    
    MyClass *myClass = (MyClass *)malloc(sizeof(MyClass));
    myClass->set_number(42);
    free(myClass);
    
    /**
     * With _new, the output looks like the following:
        Allocate memory
        Number: 42
        Delete memory
     * */
    MyClass *myClass = new MyClass();
    myClass->set_number(42);
    delete myClass;

    return 0;
}

