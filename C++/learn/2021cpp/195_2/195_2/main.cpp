//
//  main.cpp
//  195_2
//
//  Created by MacKenia on 2021/5/14.
//

#include <iostream>
#include "employee.h"
using namespace std;

int main() {
    // insert code here...
    employee a[2];
    char b[10] = "233-L";
    for(int i = 0; i < 2; i++)
    {
        if(a[i].findnum(b)) cout << "Yes" << endl;
    }
    return 0;
}
