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
    int level;
    char tel[12];
    char hobby[255];
    bool operator==(int a){
        return num == a;
    }
    bool operator==(const char *a){
        return strcmp(name,a);
    }
};

class frd
{
private:
    static fstream frdFile; //所有对象共用同一个文件
    vector<peo> vec; //用于存放好友的容器
    struct peo fri;
public:
    frd();
    ~frd();
    void addf();
    void rmvf(const char *);
    void rmvf(int);
    void shwf();
    void modf(const char *);
    void modf(int);
    void secf(const char *);
    void secf(int);
};
#endif