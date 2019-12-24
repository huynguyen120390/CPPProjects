#include <assert.h>
#include <cassert>
#include <iostream>

using namespace std;
// TODO: Define Point class
class Point{
    private:
        
    public:
        float __x,__y;
        Point(){}
        Point(float x, float y):__x(x),__y(y){}
        Point operator+(Point p){
            Point addedP;
            addedP.__x = __x + p.__x;
            addedP.__y = __y + p.__y;
            return addedP;
        }
        void repr(){
            cout << "Point::__x = " << __x << ",Point::__y = " << __y << endl;
        }

};
  

// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.__x == p1.__x + p2.__x);
  assert(p3.__y == p1.__y + p2.__y);
  p3.repr();
}