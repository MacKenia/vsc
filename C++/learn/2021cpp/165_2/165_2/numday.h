#include <iostream>
#ifndef numdays_h
#define numdays_h
class numdays
{
private:
    float hour;
    float day;
public:
    numdays();
    void converse();
    numdays& operator+(numdays&);
    numdays& operator-(numdays&);
    numdays& operator+(int);
    numdays& operator-(int);
    float operator++(int);
    float operator--(int);
    float operator++();
    float operator--();
    friend std::ostream& operator<<(std::ostream&, numdays&);
    friend std::istream& operator>>(std::istream&, numdays&);
};
#endif
