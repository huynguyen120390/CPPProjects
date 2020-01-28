#include <stdlib.h> //or <malloc.h>
#include <iostream>

class MClass{
    private:
        int * _mIntPtr;
    public:
        MClass(int mInt){
            this->_mIntPtr = (int *)malloc(sizeof(int)); 
            *this->_mIntPtr=mInt;
        }
        ~MClass(){
            free(this->_mIntPtr);
        }
        void mFunc(){}

        void *operator new(size_t size){ void *p = malloc(size);return p;}
        void operator delete(void *p){free(p);}
        void *operator new[](size_t size){void *p = malloc(size);return p;}
        void operator delete[](void *p){free(p);}
};

int main(){
    MClass *mObj = new MClass(2);
    mObj->mFunc();
    delete mObj;

    int * myInt = new int;
    delete myInt;

    int * myIntArr = new int[10];
    delete[] myIntArr;
}