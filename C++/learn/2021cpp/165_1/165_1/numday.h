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
    void converse(const bool&);
    numdays& operator+(numdays&);
    numdays& operator-(numdays&);
    numdays& operator+(int);
    numdays& operator-(int);
    bool operator==(const float);
    float operator++(int);
    float operator--(int);
    float operator++();
    float operator--();
    float da();
    int hou();
    friend std::ostream& operator<<(std::ostream&, numdays&);
    friend std::istream& operator>>(std::istream&, numdays&);
};
#endif
