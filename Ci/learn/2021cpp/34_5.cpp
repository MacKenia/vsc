/**
 * 对学生的答案进行校对并且指出错误
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ans[20] = {'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A'}, s[20];
    int sum = 0;
    //输入学生答案
    cout << "请输入学生答案: （只能输入ABCD）" << endl;
    for (int i = 0; i < 20; i++)
    {
        char t;
        cout << "请输入第" << i+1 << "个答案: ";
        scanf("%c", &t);
        if(t == 'A' || t == 'B' || t == 'C' || t == 'D') s[i] = t;
        else if(t == ' '||t == '\n'||t==','||t=='\'') i--;
        else
        {
            printf("请输入\"A B C D\"请重新输入\n"); 
            i=-1;
            cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
        }
    }
    //判断
    for (int i = 0; i < 20; i++)
    {
        if(ans[i] == s[i]) s[i] = 1;
        else s[i] = 0,sum++;
    }
    //输出
    cout << "******************" << endl;
    if(sum <= 8) printf("通过\n");
    else printf("不通过\n");
    cout << "******************" << endl;
    cout << "错误题数： " << sum << endl << "错误题号：";
    for(int i = 0; i < 20; i++) if(!s[i]) printf("%d ", i+1);
    return 0;
}
