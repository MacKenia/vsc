#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>
#include <cmath>
#include "sc.h"
#ifndef frd_h
#define frd_h

using namespace std;

struct peo //结构体用于储存个人信息
{ 
    int num;
    char name[25];
    char gender[5];
    int age;
    int grader;
    char tel[12];
    char hobby[255];
    bool operator==(int a){ //重载运算符用于查找
        return num == a;
    }
    bool operator==(const char *a){ //同上
        return !strcmp(name,a);
    }
};

class frd
{
private:
    sc frd(); //sc的对象
    fstream frdFile; //所有对象共用同一个文件
    vector<peo> vec; //用于存放好友的容器
    vector<peo>::iterator vp; //指向容器的指针
    struct peo fri; //用于读取和缓存的中间变量
    struct peo me; //账号主人的身份信息
public:
    frd(const char *); //构造函数
    ~frd(); //析构函数
    void addf(); //添加好友
    void rmvf(); //删除好友
    void rmvf(const char *); //删除好友（名字方式）
    void rmvf(int); //删除好友（编号方式）
    void shwf(); //展示所有好友
    void showall(); //直接展示
    void genders(); //同性好友
    void ages(); //同龄好友
    void modf(); //修改好友
    void modf(const char *); //修改好友信息（姓名方式查找）
    void modf(int); //修改好友信息（编号方式）
    void secf(); //查找好友
    vector<peo>::iterator secf(const char *); //查找好友（姓名方式查找）
    vector<peo>::iterator secf(int); //查找好友（编号方式）
    void createme(); //创建个人信息
    void funa(struct peo); //无条件输出信息
    void funb(struct peo); //按性别输出
    void func(struct peo); //按年龄输出
};
#endif