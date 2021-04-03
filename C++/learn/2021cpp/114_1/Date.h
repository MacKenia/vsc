#ifndef DATE_H
#define DATE_H
class Date
{
    private:
        int iday;
        int imonth; 
        int iyear;
        int icentury;
        char *sx;
    public:
        void set(int year,int month,int day,int century, char *sx);
        int day(){return iday;}
        int month(){return imonth;}
        int year(){return iyear;}
        int century(){return icentury;}
        char *sxx(){return sx;}
        protected:

};
#endif