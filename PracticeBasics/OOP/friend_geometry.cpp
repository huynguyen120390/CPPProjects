#include <iostream>

using namespace std;

class Square{
    private:
        float side;
        
    public:
        Square(float side):side(side){};
        friend class Rectangle;
    
};
class Rectangle{
    private:
        float width;
        float height;
    public:
        Rectangle(Square square):width(square.side),height(square.side){};
        float Area(){return width*height;};
};

int main(){
    Square sq(5);
    Rectangle rec(sq);
    std::cout << rec.Area() << std::endl;
}


