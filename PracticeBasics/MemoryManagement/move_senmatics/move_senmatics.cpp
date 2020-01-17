#include <iostream>

class MyMoveableClass{
    private:
        int size;
        int * data;
    public:
        MyMoveableClass(size_t size){
            size = size;
            data = new int[size];
        }
        ~MyMoveableClass(){
            delete[] data;
        }
        MyMoveableClass(const MyMoveableClass &source){
            size = source.size;
            data = new int[size];
            *data = *source.data;
        }
        MyMoveableClass &operator=(const MyMoveableClass &source){
            if(this == &source){
                return *this;
            }
            delete[] data;
            data = new int[source.size];
            *data = *source.data;
        }

};


int main(){
    MyMoveableClass mo1(10);
    MyMoveableClass mo2(mo1);
    MyMoveableClass mo3 = mo1;

}