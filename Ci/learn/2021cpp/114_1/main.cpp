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
    bool f = true;
    while(f)
    {
        cout << "1.输入日期" << endl
        << "2.以数字方式显示日期" << endl
        << "3.以月在前显示" << endl
        << "4.以日在前显示" << endl
        << "5.退出" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                i.setDate();
                break;
            case 2:
                i.shownum();
                break;
            case 3:
                i.showmonth();
                break;
            case 4:
                i.showday();
                break;
            case 5:
                f = false;
        }
        cout << endl;

    }
    return 0;
}
