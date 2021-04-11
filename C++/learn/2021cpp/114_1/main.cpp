//
//  main.cpp
//  114_1
//
//  Created by MacKenia on 2021/4/9.
//

#include <iostream>
#include "Date.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Date i;
    int choice;
    cin >> choice;
    cout << "1.输入日期" << endl
    << "2.以数字方式显示日期" << endl
    << "3.以月在前显示" << endl
    << "4.以日在前显示" << endl;
    switch (choice) {
        case 1:
            <#statements#>
            break;
            
        default:
            break;
    }
    i.setDate();
    i.showmonth();
    i.showday();
    i.shownum();
    return 0;
}
