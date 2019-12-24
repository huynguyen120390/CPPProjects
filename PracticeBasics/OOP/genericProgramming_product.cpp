#include <assert.h>

template <typename myType>
myType Product(myType a, myType b){return a*b;}

int main(){
    assert(Product<int>(2,3) == 6);
}