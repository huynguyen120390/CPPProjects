/* Use this to run in terminal
    g++ -std=c++17 2.AutoKeyword.cpp && ./a.out
*/

#include <iostream>
//#include <vector>
//using std::vector;
using std::cout;

int main(){
    auto v = {7,8,9,10};
    for(auto i: v){
        cout << i;
    }
    cout <<"\n";
}