#include <iostream>
#include <memory>

int main(){
    std::shared_ptr<int> shared1(new int);
    std::shared_ptr<int> shared0(new int);
    std::cout <<"shared pointer count says" << shared1.use_count() <<std::endl;
    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "shared2 is pointing to shared1, so their shared pointer count says" <<shared1.use_count() <<std::endl;
        std::cout << "no pointer is pointing to shared0 yet so its counter says "  <<shared0.use_count() <<std::endl;
        


    }
    std::cout <<"shared2 is end of life due to leaving its own scope, shared pointer count says" <<shared1.use_count() <<std::endl;
    std::cout << "never a pointer is pointing to shared0 yet so its counter says "  <<shared0.use_count() <<std::endl;
    std::cout <<"The counter will become 0 after this scope is done;" <<std::endl;
    return 0;
}