#include <cassert>
#include <vector>

class Matrix{
    private:
        int __rows;
        int __columns;
        std::vector<int> __values;
    public:
        Matrix(int rows,int columns):__rows(rows),__columns(columns),__values(rows*columns){};
        int& operator()(int row, int column){
            return __values[row*__columns + __columns];
        }
        int operator()(int row, int column) const{
            return __values[row*__columns + __columns];
        }

};

int main(){
    Matrix matrix(2,2);
    matrix(0,0) = 4;
    assert(matrix(0,0) == 4);
}