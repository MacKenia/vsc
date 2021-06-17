#include "login.h"
using namespace std;

fstream login::pasFile("data.dat", ios::binary | ios::in | ios::out);

login::login()
{
    if(pasFile.fail())
    {
        cout << "文件打开失败！" << endl;
        getchar();
        exit(0);
    }
}

bool login::log()
{
    sc lo;
    lo.

}

