//
//  Header.hpp
//  114_1
//
//  Created by MacKenia on 2021/4/9.
//

#ifndef Date_h
#define Date_h
class Date
{
private:
    int day;
    int month;
    int year;
    char wm[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
public:
    void setDate(int, int, int);
    void setDate();
    void shownum();
    void showmonth();
    void showday();
    
};

#endif /* Header_h */

void Date::setDate(int a, int b, int c)
{
    if(c>=1&&c<=31) day = c;
    else {
        std::cout << "输入有误，请重新输入：";
        std::cin >> a >> b >> c;
        setDate(a,b,c);
        return;
    }
    if(b>=1&&b<=12) month = b;
    else {
        std::cout << "输入有误，请重新输入：";
        std::cin >> a >> b >> c;
        setDate(a,b,c);
        return;
    }
    year = a;
}

void Date::setDate()
{
    int a, b, c;
    std::cout << "请输入年 月 入：";
    std::cin >> a >> b >> c;
    setDate(a,b,c);
}

void Date::shownum()
{
    std::cout << day << "-" << month << "-" << year << std::endl;
}

void Date::showmonth()
{
    std::cout << wm[month-1] << " " << day << "," << year << std::endl;
}

void Date::showday()
{
    std::cout << day << " " << wm[month-1] << " " << year << std::endl;
}
