#include <string>
#include <cstring>
#include <iostream>

class Car{
    private:
        float horsepower;
        float weight;
        char brand[];
    public:
        void Brand(std::string brand);
        std::string Brand();
};

void Car::Brand(std::string brand){
    int i;
    for(i = 0; i < brand.size(); i++){
        *(this->brand + i) = brand[i];
        std::cout << brand[i] << " " << *(this->brand + i) << std::endl;
    }
    *(this->brand + i) = '\0';
}

std::string Car::Brand(){
    return this->brand;
}




int main(){
    Car car;
    car.Brand("Toyota");
    std::cout << car.Brand();
}