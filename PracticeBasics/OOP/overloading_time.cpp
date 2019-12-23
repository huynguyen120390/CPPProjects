#include <ctime>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year): day(day), month(month), year(year){}
        Date(int day, int month, int year): day(day), month(month){
            time_t t = time(NULL);
            tm* timePtr = localtime(&t);
            year = timePtr->tm_year;
        }
};