/*
    Directives
*/
#include <iostream>
#include <vector>
/*
    Namespace
*/
using std::vector;
using std::cout;
/*
    Prototypes
*/
void make_threeVectors(void);
void make_2DVectors(void);
/*
    Main function
*/
int main(){
    make_threeVectors();
    make_2DVectors();
}
/*
    Function Definition
*/
void make_threeVectors(void){
    //Three ways to declare and init vector;
    vector<int> v_1{0,1,2};
    vector<int> v_2 = {3,4,5};
    vector<int> v_3; v_3 = {6};

    for(int i : v_2){ 
        cout << i << " ";
    }
}

void make_2DVectors(void){
    //Use index-based loop, v is called vector
    vector<vector<int>> v = {{1,2},{3,4}};
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout <<"\n";
    }
    cout <<"\n";
    //Use range-based loop, v is called container of vectors
    for(vector<int> row:v){
        for(int item:row){
            cout<<item;
        }
        cout<<"\n";
    }
    cout<<"\n";
    //Use range-based loop, auto keyword
    for(auto row:v){
        for(auto item:row){
            cout<<item;
        }
        cout<<"\n";
    }
}



