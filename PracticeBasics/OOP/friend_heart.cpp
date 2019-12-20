#include <iostream>

class Heart{
    private:
        int rate = 80;
        friend class Human;
};

class Human{
    private:
        int height = 0;
        int weight = 0;
        Heart heart;
    public:
        void do_excercise(){heart.rate = 150;}
        int ret_heartRate(){return heart.rate;}
};

int main(){
    Human human;
    human.do_excercise();
    std::cout << human.ret_heartRate() <<std::endl;

}


