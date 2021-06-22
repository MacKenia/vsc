#include "sc.h"
#include <fstream>
using namespace std;

#ifndef login_h
#define login_h
class login
{
private:
    fstream pasFile;
    char username[255];
public:
    login(const char *); //构造函数
    char log(); //登录界面
};

#endif