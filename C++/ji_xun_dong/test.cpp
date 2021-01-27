#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int main()
{
    int j, i;
    char t[20];
        cin >> t;
        //输入处理
        for(j = 0; t[j] != '\0'; j++)
        {
            if(j == 3)
            {
                char t1[20];
                strcpy(t1, &t[j]);
                strcpy(&t[j+1], t1);
                t[j] = '-';
            }
            else if(t[j] == '-')
            {
                strcpy(&t[j], &t[j+1]);
                j--;
            }
        }
        t[j] = '\0';
        cout << "num is " << t << endl; 
    return 0;
}

