/**
 * 总降雨量，平均降雨量，最大最小降雨量
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    float record[12], total = 0, average = 0;
    int mas = 0, mis = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> record[i];
        if(record[i] < 0) cout << "输入的数包含负数请重新输入" << endl, i = 0, cin.clear();
        mas = record[i]==max(record[mas],record[i])?record[i]==record[mas]?mas:i:mas;
        mis = record[i]==min(record[mis],record[i])?record[i]==record[mis]?mis:i:mis;
        total += record[i];
    }
    average = total / 12.0;
    cout << "总降雨量为： " << total << endl;
    cout << "平均降雨量为： " << setprecision(2) << average << endl;
    cout << "降雨最多的月份为： " << mas+1 << endl;
    cout << "降雨最少的月份为： " << mis+1 << endl;
    return 0;
}
