#include<bits/stdc++.h>
using namespace std;

int main()
{
    char score1[3][2] = {0}, score2[3][2] = {0}, t;
    int i = 0, con = 1, j = 0;
    while (scanf("%c", &t)&&t != 'E')
    {
        con++;
        if(t=='L') score1[i][1]++,score2[j][1]++;
        else if(t=='W') score1[i][0]++,score2[j][0]++;
    
        if(con%12 == 0) i++;
        if(con%23 == 0) j++;
    }
    for(int i = 0; score1[i][0] != 0 || score1[i][1] != 0; i++) printf("%d:%d\n", score1[i][0], score1[i][1]);
    cout << endl;
    for(int i = 0; score2[i][0] != 0 || score2[i][1] != 0; i++) printf("%d:%d\n", score2[i][0], score2[i][1]);
    return 0;
}
