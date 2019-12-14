#include <cassert>
class Date{
    public:
        Date(int d, int m, int y){
            Day(d);
            Month(m);
            Year(y);
        }
        int Day() {
            return day;
        }
        void Day(int d){
            day = d;
        }
        int Month(){
            return month;
        }
        void Month(int m){
            month = m;
        }
        int Year(){
            return year;
        }
        void Year(int y){
            year = y;
        }
    private:
        int day {1};
        int month {1};
        int year {0};
};

int main(){
    Date date(12,3,1990);
    assert(date.Day() == 12);
    assert(date.Month ()== 3);
    assert(date.Year() == 1990);

}