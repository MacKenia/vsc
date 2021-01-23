//快速排序
#include<stdio.h>

int mian()
{
    
    return 0;
}

void sort_the_group(int *p, int len)
{
    int *j = p, *l = p + 1, *r = p + len - 1;
    
    for(l = p + 1;*l < *j; l++);
    for (r = p + len - 1; *r > *j; r--);
    if(r == l)
    {
        int t = *j;
        *j = *l;
        *l = t;
    }
    else
    {
        int t = *r;
        *r = *l;
        *l = t;
    }
    


}

