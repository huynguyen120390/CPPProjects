#include <iostream>
#include <cassert>
#include <stdexcept>


class Pyramid{
    private:
        float length;
        float width;
        float height;
        float volumn;

    public:
        Pyramid(float length, float width, float height): length(length), width(width), height(height){};
        void set_length(float length);
        void set_width(float width);
        void set_height(float height);
        float get_length();
        float get_height();
        float get_width();
        void calc_volumn();
        float get_volumn();
};

struct negative_dimension: public std::exception{
    const char * what() const throw(){
        return "Negative Dimension";
    }
};


float Pyramid::get_height(){return this->height;}
float Pyramid::get_width(){return this->width;}
float Pyramid::get_length(){return this->length;}
void Pyramid::set_length(float length){
    try{
        if(length < 0){
            throw negative_dimension();
        }
        this->length = length;
    }
    catch(negative_dimension& e){
        std::cerr << e.what() << std::endl;
    }
}
void Pyramid::set_width(float width){this->width = width;}
void Pyramid::set_height(float height){this->height = height;}
void Pyramid::calc_volumn(){this->volumn = (this->height*this->width*this->length)/3;}
float Pyramid::get_volumn(){return this->volumn;}

int main(){
    Pyramid py(0,0,0);
    py.set_length(-1);
    py.set_width(5);
    py.set_height(6);
    assert(py.get_length() == 5);
    assert(py.get_width() == 5);
    assert(py.get_height() == 6);
    py.calc_volumn();
    assert(py.get_volumn() == 40);
}

