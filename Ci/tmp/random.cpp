//随机生成成绩

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main()
{
    while (true)
    {
        getchar();
        printf("%.2f\n",pow(sqrt(fmod(rand()/100.0f,100.0)),2));
    }
    return 0;
}

