#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    set<char> test;
    string dict[1000];

    vector<char> cdict;

    char t;
    int i, j;
    // cout << dict[0] << ' ' << dict[1] << endl;
    while(cin >> dict[i] && dict[i++][0] != '#');
    for(i = 0; dict[j][0]!='#'; j++)
        for(i = 0; dict[j][i] != '\0'; i++)
        {
            (*(cdict.begin()+i)).insert(dict[j][i]);
        }
    for(vector<set<char>>::iterator p = cdict.begin(); p != cdict.end(); p++) cout << *p << ' ';
    for(i = 0;dict[i][0] != '#'; i++) cout << dict[i] << ' ';
    return 0;
}

void getkey(char *k)
{
    if(*k>='A'&&*k<='Z'||*k>='a'&&*k<='z')
        if(*k>='A'&&*k<='Z') *k-=32;
        else *k+=32;
    return;
}
