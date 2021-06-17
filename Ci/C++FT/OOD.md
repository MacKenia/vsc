[toc]

# OOD

## frd.h 个人信息类

``` C++ {.line-numbers}
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "sc.h"
#ifndef frd_h
#define frd_h

using namespace std;

struct peo //结构体用于储存个人信息
{ 
    int num;
    char name[255];
    bool gander;
    int age;
    int grade1;
    char tel[12];
    char hobby[255];
    bool operator==(int a){ //重载运算符用于查找
        return num == a;
    }
    bool operator==(const char *a){ //同上
        return strcmp(name,a);
    }
};

class frd
{
private:
    static fstream frdFile; //所有对象共用同一个文件
    vector<peo> vec; //用于存放好友的容器
    struct peo fri; //用于读取和缓存的中间变量
    struct peo me; //账号主人的身份信息
public:
    frd(); //构造函数
    ~frd(); //析构函数
    void addf(); //添加好友
    void rmvf(const char *); //删除好友（名字方式）
    void rmvf(int); //删除好友（编号方式）
    void shwf(); //展示所有好友
    void modf(const char *); //修改好友信息（姓名方式查找）
    void modf(int); //修改好友信息（编号方式）
    void secf(const char *); //查找好友（姓名方式查找）
    void secf(int); //查找好友（编号方式）
    
};
#endif
```

## login.h 登录管理

``` C++ {.line-numbers}
#include "sc.h"
#include <fstream>
using namespace std;

#ifndef login_h
#define login_h
class login
{
private:
    static fstream pasFile;
public:
    login(); //构造函数
    bool log(); //登录界面
};

#endif
```

## sc.h 控制台控制类

``` C++ {.line-numbers}
#include <windows.h>
#include <cstring>
#include <iostream>
#ifndef sc_h
#define sc_h

class sc //ScreenControl 窗口控制
{
private:
    static HANDLE had;
    COORD cr;
    static CONSOLE_SCREEN_BUFFER_INFO csbi;
public:
    sc(const char*); //构造函数
    void setT(const char*); //设置窗口标题
    void color(int a); //修改文字输出的颜色
    void ccp(int, int); //ConsoleCursorPosition 控制台指针位置
    void setW(int, int); //设置窗口大小
    void setbc(const char *); //SetBackGroundColor 设置窗口背景颜色
    void cls(); //清空控制台
    friend char *intTochar(char*, int); //将整转换为字符型
};

#endif

```
