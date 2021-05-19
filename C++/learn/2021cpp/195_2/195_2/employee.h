//
//  employee.h
//  195_2
//
//  Created by MacKenia on 2021/5/14.
//

#ifndef employee_h
#define employee_h
struct number
{
    char s[4];
    bool operator==(const char *n)
    {
        if(s[0]-n[0]&&s[1]-n[1]&&s[2]-n[2]&&s[3]-n[3]&&s[4]-n[4]) return true;
        else return false;
    }
};

class employee
{
private:
    char *name;
    struct number num;
    int hire[8];
public:
    employee();
    employee(employee &a);
    ~employee();
};

#endif /* employee_h */
