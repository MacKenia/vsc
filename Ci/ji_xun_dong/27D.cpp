#include<iostream>
using namespace std;


int main()
{
    int stair[40];
    stair[0] = stair[1] = 1;
    for(int i = 2; i < 40; i++) stair[i] = stair[i-1] + stair[i-2];
    int n, nn;
    cin >> n;
    while (n--)
    {
        cin >> nn;
        cout << stair[nn-1] << endl;
    }
    return 0;
}
