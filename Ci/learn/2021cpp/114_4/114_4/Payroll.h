//
//  Payroll.hpp
//  114_4
//
//  Created by MacKenia on 2021/4/22.
//

#ifndef Payroll_h
#define Payroll_h
class payroll
{
private:
    static float hSalary;
    float salary = 0;
    float wTime = 0;
    float wWage = 0;
public:
    static bool flag;
    payroll();
    static void setM();
    float pay();
};

#endif /* Payroll_h */
