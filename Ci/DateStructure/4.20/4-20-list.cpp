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
    int pos = -1;
    for (int i = 0; i < g->vexNum; i++)
    {
        if(g->vertices[i].data == w) pos = i; // find w's position
        if (g->vertices[i].data == v)
        {
            if(pos == -1) // find w's position
            {
                for(int j = i; j < g->vexNum; j++)
                {
                    if(g->vertices[j].data == w)
                    {
                        pos = j;
                        break;
                    }
                }
            }
            if(pos == -1) break;

            if (g->vertices[i].first == nullptr)
            {   // generate the first Node
                g->vertices[i].first = new ArcNode;
                g->vertices[i].first->adjvex = pos;
                g->vertices[i].first->nextarc = nullptr;
            }
            else
            {   //already has a Node
                ArcNode *p = g->vertices[i].first;
                for (;;p=p->nextarc)
                    if(!p->nextarc) break;
                p->nextarc = new ArcNode;
                p = p->nextarc;
                p->adjvex = pos;
                p->nextarc = nullptr;
            }
            g->arcNum++;
            break;
        }
    }
}

void DeleteArc(ALGraph *g, char v, char w)
{
    int pos = -1;
    for (int i = 0; i < g->vexNum; i++)
    {
        if(g->vertices[i].data == w) pos = i;
        if(g->vertices[i].data == v)
        {
            ArcNode *p = g->vertices[i].first;
            ArcNode *q = nullptr;
            for(int j = i; j < g->vexNum; j++)
            {
                if(g->vertices[j].data == w)
                {
                    pos = j;
                    break;
                }
            }
            if(pos == -1) break;

            for(q=p;;q=p,p=p->nextarc)
            {
                if(g->vertices[i].first == q)
                {
                    g->vertices[i].first = q->nextarc;
                    delete(p);
                } else if(p->adjvex == pos)
                {
                    q->nextarc = p->nextarc;
                    delete(p);
                    break;
                }
            }
            g->arcNum--;
            break;
        }
    }
}

void print(ALGraph g)
{
    for(int i = 0; i < g.vexNum; i++)
    {
        cout << g.vertices[i].data << " ";
        for(ArcNode *p = g.vertices[i].first; p != nullptr; p=p->nextarc)
        {
            cout << p->adjvex << " ";
        }
        cout << endl;
    }
}

int main()
{
    ALGraph test;
    for(int i = 0; i < N; i++)
    {
        test.vertices[i].first = nullptr;
    }
    InsertVex(&test, 'a');
    InsertVex(&test, 'b');
    InsertVex(&test, 'c');
    InsertArc(&test, 'a', 'b');
    InsertArc(&test, 'a', 'c');
    DeleteArc(&test, 'a', 'b');
    print(test);
    return 0;
}
