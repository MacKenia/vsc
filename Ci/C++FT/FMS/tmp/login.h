#include "sc.h"
#include <fstream>
using namespace std;

#ifndef login_h
#define login_h
class login
{
private:
    sc lo;
    fstream pasFile;
    char filename[9] = "data.dat";
    char username[20];
public:
    login(); //构造函数
    char* log(); //登录界面
    void sign(); //注册界面
};

#endif