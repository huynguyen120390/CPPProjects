#include <iostream>
#include <cassert>
class Date{
    public:
        void Day(int d){
            if(d > 0 && d < 31) day = d;
        }
        int Day(){
            return day;
        }
        void Month(int m){
            if(m > 0 && m < 13) month = m;
        }
        int Month(){
            return month;
        }
        void Year(int y){
            year = y;
        }
        int Year(){
            return year;
        }
    private:
        int day{1};
        int month{1};
        int year{0};

};
// Test in main
int main()
{
    Date date;
    date.Day(-1);
    date.Month(14);
    date.Year(2000);
    assert(date.Day() != -1);
    assert(date.Month() != 14);
    assert(date.Year() == 2000);
}
