#ifndef DATE_H
#define DATE_H
class Date
{
    private:
        int iday;
        int imonth; 
        int iyear;
        void e(int, char *);
    public:
        void set(int year,int month,int day);
        void set();
        void shownum();
        void showmon();
        void showday();
        protected:

};
#endif