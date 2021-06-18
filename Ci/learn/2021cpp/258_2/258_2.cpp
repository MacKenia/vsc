#include <bits/stdc++.h>

using namespace std;

template<typename T>
void writequeue(T &queue,const char *s)
{
    fstream file(s, ios::out);
    while(!queue.empty())
    {
        file.put(queue.front());
        queue.pop();
    }
    file.close();
}

int main()
{
    fstream File("inputs.txt", ios::in);
    queue<char> cr;
    char t;
    if(File.fail())
    {
        cout << "文件打开失败！" << endl;
        exit(0);
    }
    while(!File.eof())
    {
        if(File.fail()) break;
        File.get(t);
        if(t >= 'a' && t <= 'z')
            t -= 32;
        cr.push(t);
        cout << cr.back();
    }
    File.close();
    cout << endl;
    writequeue(cr, "inputs.txt");
    return 0;
}