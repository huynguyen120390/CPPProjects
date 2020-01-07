#include <iostream>

void aim_to_overflow_the_stack(int i, int * bottom){
    std::cout << i << ": " << &i << " bottom " << bottom << std::endl;
    aim_to_overflow_the_stack(i+1,bottom);
    
}

int main(){
    int i = 0;
    int * bottom = &i;
    aim_to_overflow_the_stack(i+1,bottom);
    return 0;
}