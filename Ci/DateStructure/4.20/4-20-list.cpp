#include <bits/stdc++.h>
#define N 10

using namespace std;

struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
};

struct VNode
{
    char data;
    ArcNode *first;
};

struct ALGraph
{
    VNode vertices[N];
    int vexNum, arcNum;
};

void InsertVex()
{
    
}

int main()
{
    
    return 0;
}
