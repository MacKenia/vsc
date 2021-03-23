#include <bits/stdc++.h>
using namespace std;

struct info{
    char name[21];
    int age;
    char address[51];
    char phone[14];
    char Email[51];
}buf = {"SBSBSBS",5,"alsdfj","808089","-089@080"},buf1= {"SSDS",5,"alsdfj","808089","-089@080"};

vector<info> stu;


int main()
{
    // ofstream inputfile;
    // inputfile.open("a.txt",ios::out);
    // if(inputfile.fail()) printf("打开失败");
    // else printf("打 开成功！");
    // system("pause");
    // inputfile.close();
    // cin >> buffar[0].name;
    // buffar[0].length = 0;
    // int arr1[4] = {1,2,3,4},arr2[2];
    fstream inputfile("a.dat",ios::out|ios::binary);
    if(inputfile.fail()) printf("打开失败！");
    vector<info>::iterator p = stu.begin();
    cout << sizeof(p);
    // inputfile.seekp(1L,ios::beg);
    // inputfile.put('b');
    // inputfile.close();
    int a = 1, b = 2;
    char c[8] = "asldjk";
    info en = {*c,a,*"asdf",*"asdf",*"asdfasdf"};
    inputfile.write((char*)&buf,sizeof(buf));
    inputfile.write((char*)&buf1,sizeof(buf1));
    return 0;
}
