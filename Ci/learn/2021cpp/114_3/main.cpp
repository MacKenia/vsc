//
//  main.cpp
//  114_3.cpp
//
//  Created by MacKenia on 2021/4/7.
//

#include "Float.h"
#include <iostream>
using namespace std;

int main() {
    // insert code here...
    int a;
    cout << "请输入创建float的个数：";
    cin >> a;
    Float jk(a);
    jk.insert();
    jk.check();
    return 0;
}
