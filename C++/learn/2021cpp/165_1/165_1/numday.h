#include <iostream>
#ifndef numday_h
#define numday_h
class numday
{
private:
    float hour;
    float day;
public:
    numday();
    void converse();
    numday& operator+(numday&);
    numday& operator-(numday&);
    numday& operator++(int);
    numday& operator--(int);
    friend std::ostream& operator<<(std::ostream&, numday&);
    friend std::istream& operator>>(std::istream&, numday&);
};
#endif
