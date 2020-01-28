#include <iostream>
#include <stdlib.h> 
class MyClass{
    private:
        int *_myInt;
    
    public:
        MyClass(){
            _myInt = (int *)malloc(sizeof(int));
        };

        ~MyClass(){
            free(_myInt);
        };

        void print_own_address(){std::cout << " Own Address On The Stack Is " << this << std::endl;}
        void print_member_address(){std::cout << "Managing memory block on the heap at" << _myInt << std::endl;}
        void set_int(int val){*_myInt = val;}
        int get_int(){return *_myInt;}
};

int main(){

    //Instantiate object
    MyClass myClass1;
    myClass1.print_own_address();
    myClass1.print_member_address();

    //Copy object 1 to object 2
    MyClass myClass2(myClass1);
    myClass2.print_own_address();
    myClass2.print_member_address();
    myClass2.set_int(7);
    std::cout << myClass2.get_int() <<"=="<<myClass1.get_int()<< std::endl;
    /**
     * Output: The output shows : myClass1 and myClass2 are the same object, so this is a shallow copy. 
     * This cause freeing twice, and cause Core Dump error
     * hnguyen@wshnguyen01:~/codelab/githubproject/cppnd/CppProjects/PracticeBasics/MemoryManagement$ ./a.out 
 Own Address On The Stack Is 0x7ffc6ba814a0
Managing memory block on the heap at0xddec20
 Own Address On The Stack Is 0x7ffc6ba814b0
 7==7
Managing memory block on the heap at0xddec20
*** Error in `./a.out': double free or corruption (fasttop): 0x0000000000ddec20 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7fe932fc97e5]
/lib/x86_64-linux-gnu/libc.so.6(+0x8037a)[0x7fe932fd237a]
/lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7fe932fd653c]
./a.out[0x400c77]
./a.out[0x400b8b]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7fe932f72830]
./a.out[0x400a19]
======= Memory map: ========
.......
     * 
     * 
    */

   

}