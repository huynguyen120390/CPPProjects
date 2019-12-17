#include <iostream>
#include <string>
#include <stdexcept>
#define MIN_GRADE 1
#define MAX_GRADE 12
#define MIN_GPA 0
#define MAX_GPA 4
using namespace std;

class Student{
    private:
        string name;
        int grade;
        float gpa;
    public:
        //Student();
        Student(string name, int grade, float gpa):name(name),grade(grade),gpa(gpa){}
        void set_name(string name);
        void set_grade(int grade);
        void set_gpa(float gpa);
        string get_name();
        int get_grade();
        float get_gpa();
};

void Student::set_name(string name){
    if(name.size() < 1){
        throw "Error: Empty Name Input";
    }
    this->name = name;
}

void Student::set_grade(int grade){
    if(grade < MIN_GRADE  &&  grade > MAX_GRADE){
        throw "Error : Put of School Grade Range ";
    }
    this->grade = grade;
}

void Student::set_gpa(float gpa){
    if(gpa < MIN_GPA && gpa > MAX_GPA){
        throw "Error : Out of GPA Range";
    }
    this->gpa = gpa;
}

string Student::get_name(){ return this->name;}
int Student::get_grade(){ return this->grade;}
float Student::get_gpa(){return this->gpa;}

int main(){
    cout << "Student Class CPP" << endl;
    Student student("Huy",1,3);
    
    //student.set_grade(-1);
    //student.set_gpa(5);

    try{
        student.set_name("");
    }catch(const char * msg){
        cerr << msg << endl;
        exit(1);
    }

}