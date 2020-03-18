#include <iostream>
#include <memory>
class MyClass{
    private:
        int member;
    public:
        MyClass(int val): member{val}{};
        void print_val(){std::cout << ",managed object" << this << " with val =" <<member<<std::endl;}
};

void transfer_to_unique_ptr(std::unique_ptr<MyClass> ptr){
    std::cout << "unique_ptr" << &ptr;
    ptr->print_val();
}

void transfer_to_shared_ptr(std::shared_ptr<MyClass> ptr){
    std::cout <<"shared_ptr (count = " << ptr.use_count() << ")" << &ptr;
    ptr->print_val();
}

void transfer_to_weak_ptr(std::weak_ptr<MyClass> ptr){
    std::cout << "weak_ptr (count = " <<ptr.use_count() << ")"<< &ptr << std::endl;
   // ptr->print_val();//week pointer is used to keep reference for another smart pointer can't use to access resource
}

int main(){

    std::cout << "Demo on passing unique pointer to a function through unique pointer argument " <<std::endl;
    //create unique pointer 
    std::unique_ptr<MyClass> unique_ptr = std::make_unique<MyClass>(23);
    //check
    std::cout << "unique_ptr" << &unique_ptr;
    unique_ptr->print_val();
    //move resource of unique ptr and pass tp the function, 
    transfer_to_unique_ptr(std::move(unique_ptr)); //Need to move resource to a unique pointer
    if(unique_ptr){
        std::cout << "There is resource ?" <<std::endl;
        unique_ptr->print_val();
    }else{
        std::cout << "There
         is no more resource" <<std::endl;
    }


    std::cout << "Demo on passing shared pointer to a function through shared pointer argument" <<std::endl;
    std::shared_ptr<MyClass> shared_ptr = std::make_shared<MyClass>(24);
    std::cout << "shared_ptr (count = " <<shared_ptr.use_count() << ")" << &shared_ptr;
    shared_ptr->print_val();
    transfer_to_shared_ptr(shared_ptr); //Look! No need to move resource to a shared pointer
    std::cout <<"shared_ptr (count = " <<shared_ptr.use_count() << ")" <<&shared_ptr;
    shared_ptr->print_val();


    std::cout << "Demo on passing shared pointer to a function through shared pointer argument" <<std::endl;
    std::weak_ptr<MyClass> weak_ptr = shared_ptr;
    std::cout << "weak_ptr (count = " <<weak_ptr.use_count() << ")" << &weak_ptr <<std::endl;
   // weak_ptr->print_val();
    transfer_to_weak_ptr(weak_ptr); //Look! No need to move resource to a shared pointer
    std::cout <<"weak_ptr (count = " <<weak_ptr.use_count() << ")" <<&weak_ptr<<std::endl;
   // weak_ptr->print_val();

    return 0;
}


