class NoCopyClass1{
    private: 
        // Hack: Try to declare private constructor and operator for the class itself
        // then we cannot copy these classes by accessing to these classes 
        NoCopyClass1(const NoCopyClass1 &);
        NoCopyClass1 &operator=(const NoCopyClass1 &);
    public:
        NoCopyClass1(){};
};

class NoCopyClass2{
    public:
        NoCopyClass2(){}
        // Hack: Try to link the class copy syntaxes to delete function
        // This hack is more explicit, clearer to programmer
        NoCopyClass2(const NoCopyClass2 &) = delete;
        NoCopyClass2 &operator=(const NoCopyClass2 &) = delete;
};
class Class3{

};

int main(){
    //The following code are caught by editor , so just comment out , but usable to understand NoCopy Policy
    //NoCopyClass1 original1;
    //NoCopyClass1 copy1a(original1); //error:private constructor
    //NoCopyClass1 copy1b= original1; //error:private operator

    //NoCopyClass2 original2;
    //NoCopyClass2 copy2a(original2); //error:use of deleted function ‘NoCopyClass2::NoCopyClass2(const NoCopyClass2&)’
    //NoCopyClass2 copy2b= original2; //error:use of deleted function ‘NoCopyClass2::NoCopyClass2(const NoCopyClass2&)’

    //Class3 class3;
   // NoCopyClass1 original1(class3); //cant copy different class 
    return 0; 
}

