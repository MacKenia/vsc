#include "frd.h"
using namespace std;
 

frd::frd(const char *filename)
{
    frdFile.open(filename, ios::binary);
    if(frdFile.fail())
    {
        cout << "文件打开失败！" << endl;
        exit(0);
    }
    while(frdFile.eof())
    {
        
        frdFile.read((char *)&fri, sizeof(fri));
        
    }
}

frd::~frd()
{
    sc lo;
}


