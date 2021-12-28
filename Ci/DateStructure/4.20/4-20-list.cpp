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
    int vexNum = 0, arcNum = 0;
};

void InsertVex(ALGraph *g, char v)
{
    (g->vertices[g->vexNum++]).data = v;
}

void DeleteVex(ALGraph *g, char v)
{
    int i;
    for (i = 0; g->vertices[i].data != v; i++)
        ;
    g->vertices[i - 1].data = 0;
    for (int j = i; j < g->vexNum; j++)
    {
        g->vertices[i - 1].data = g->vertices[i].data;
        g->vertices[i - 1].first = g->vertices[i].first;
    }
    g->vexNum--;
}

void InsertArc(ALGraph *g, char v, char w)
{
    for (int i = 0; i < g->vexNum; i++)
    {
        if (g->vertices[i].data == v)
        {
            if (g->vertices == NULL)
            {   // generate the first Node
                g->vertices[i].first = new ArcNode;
                for (int k = 0; k < g->vexNum; k++)
                {
                    if (g->vertices[i].data == v)
                    {
                        g->vertices[i].first->adjvex = k;
                        g->vertices[i].first->nextarc = NULL;
                    }
                }
            }
            else
            {
                ArcNode *p = g->vertices[i].first;
                for (;;p=p->nextarc)
                    if(!p) break;
                
            }
            break;
        }
        break;
    }
}

void DeleteArc(ALGraph *g, char v, char w)
{
}

int main()
{

    return 0;
}
