#include <bits/stdc++.h>
#include "Date.h"
using namespace std;

int main()
{
    Date i;
    char ha[] = "哦"; 
    i.set(2021,6,9,8,ha);
    cout << i.day() << endl;
    cout << i.month() << endl;
    cout << i.year() << endl;
    cout << i.century() << endl;
    cout << i.sxx() << endl;
    system("pause");
    return 0;
}
