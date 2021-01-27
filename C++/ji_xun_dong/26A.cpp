#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> vec;
    int num[15], i = 0, j, sum = 0;
    while(scanf("%d", &num[i])&&num[i]!=-1)//判断输入的不是结束标志 
    {
        vec.insert(num[i++]);//不是就放入数组
        while (scanf("%d", &num[i])&&num[i] != 0)//判断不是末尾
            vec.insert(num[i++]); //接收这一行的数据
        //利用set的cout查找方式
        for(set<int>::iterator t = vec.begin(); t != vec.end(); t++) sum += vec.count((*t)*2);
        //输出结果
        cout << sum << endl;
        //将数据归零，准备下一行判断
        i = 0;
        sum = 0;
        vec.clear();
    }
    return 0;
}
