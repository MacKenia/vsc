//
//  main.cpp
//  114_4
//
//  Created by MacKenia on 2021/4/22.
//

#include <iostream>
#include "Payroll.h"
using namespace std;

int main() {
    // insert code here...
    char t;
    cout << "大家的时薪一样吗？(Y/N): ";
    cin >> t;
    if(t=='N'||t=='n') payroll::flag = false;
    if(payroll::flag) payroll::setM();
    payroll employee[10];
    for (int i = 0; i < 10; i++) {
        cout << "第一个的工资是：" << employee[i].pay() << endl;
    }
    return 0;
}
