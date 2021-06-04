//
//  main.cpp
//  222_1
//
//  Created by MacKenia on 2021/6/2.
//

#include <iostream>
using namespace std;

template <class t>
t Max(t a, t b)
{
    if(a > b) return a;
    else return b;
}

template <class t>
t Min(t a, t b)
{
    if(a < b) return a;
    else return b;
}

int main() {
    // insert code here...
    cout << "较大的：" << endl;
    cout << Max(1, 2) << endl;
    cout << Max(1.0f, 2.0f) << endl;
    cout << Max('a', 'b') << endl;
    cout << "较小的：" << endl;
    cout << Min('a', 'b') << endl;
    cout << Min(1.0f, 2.0f) << endl;
    cout << Min(1, 2) << endl;
    return 0;
}
