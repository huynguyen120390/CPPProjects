#include <iostream>

// class MyInt{
//     int *_p;
//     public:
//         //create a constructor passing null pointer
//         MyInt(int * p = NULL){ _p = p;}
//         //create a destructor to deallocate
//         ~MyInt(){
//             std::cout <<"Resource "<< *_p <<" Deallocated"<<std::endl;
//             delete _p;
//         }
        
//         //create an operator overloading * 
//         int &operator*(){return *_p;}
// };

// int main(){
//     double den[] = {1.0,2.0,3.0,4.0,5.0};
//     for(size_t i = 0; i < 5; i++){
//         MyInt en(new int(i));
//         std::cout << *en << "/"<<den[i]<<"="<<*en/den[i]<<std::endl;
//     }
//     return 0;
// }

class MyInt{
    private:
        int * _intptr;
    public:
        MyInt(int * p = NULL){
            std::cout << "allocate " << *p << std::endl;
            _intptr=p;
        }
        MyInt(int i){*_intptr = i; }
        ~MyInt(){
            std::cout << "deallocate " << *_intptr << std::endl;
            delete _intptr;
        }
        int &operator*(){return *_intptr;}
};
int main(){
    for(int i = 0; i < 5; i++){
        MyInt num(new int(i));
    }
    /*  Outputs: this shows that in scope {} of the for loop,
        MyInt num lives on stack , and was killed when leaving scope
        , and go back the scope in next loop
        allocate 0
        deallocate 0
        allocate 1
        deallocate 1
        allocate 2
        deallocate 2
        allocate 3
        deallocate 3
        allocate 4
        deallocate 4
    */
    
    
}

