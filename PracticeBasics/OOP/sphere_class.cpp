#include <iostream>
using namespace std;
class Sphere{
    private:
        float radius;

    public:
        Sphere(float radius);
        void set_radius(float radius);
        float get_radius();
};

Sphere::Sphere(float radius){
    this->set_radius(radius);
}

void Sphere::set_radius(float radius){
    if( radius < 0){
        throw "Error: Negative Radius";
    }
    this->radius = radius;
}

float Sphere::get_radius(){
    return this->radius;
}


int main(){
    try{
        Sphere sphere(-1);
    }catch(const char * msg){
        cerr << msg << endl;
    }
}
