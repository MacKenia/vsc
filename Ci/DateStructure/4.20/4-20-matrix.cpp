/**
 * 分别以邻接矩阵和邻接链表作为储存结构，实现一下图的基本操作：
 * 1. 增加一个新顶点v, InsertVex(G, v);
 * 2. 删除顶点v及其相关的边，DeleteVex(G, v);
 * 3. 增加一条边<v, w>, InsertArc(G, v, w);
 * 4. 删除一条边<v, w>, DeleteArc(G, v, w);
 */

#include <bits/stdc++.h>
#define N 9

using namespace std;

struct AMGraph
{
    char vex[N];
    int arcs[N][N];
    int vexNum = 0, arcNum = 0;
};

int InsertVex(AMGraph *g, char v)
{
    g->vex[g->vexNum++] = v;
    return 1;
}

int DeleteVex(AMGraph *g, char v)
{
    int i;
    for (i = 0; i < g->vexNum; i++)
    {
        if(g->vex[i] == v) g->vex[i] = 0;
    }
    strcpy(&g->vex[i],&g->vex[i+1]);
    g->vex[g->vexNum--] = 0;
    for(int j = 0; j < g->vexNum; j++)
    {
        g->arcs[i][j] = 0;
        g->arcs[j][i] = 0;
    }
    return 1;
}

int InsertArc(AMGraph *g, char v, char w)
{
    int a, b, i;
    for(i = 0; i < g->vexNum; i++){
        if(g->vex[i] == v) a = i;
        if(g->vex[i] == w) b = i; 
    }
    g->arcs[a][b] = 1;
    // g->arcs[b][a] = 1;
    g->arcNum++;
    return 1;
}

int DeleteArc(AMGraph *g, char v, char w)
{
    int a, b, i;
    for(i = 0; i < g->vexNum; i++){
        if(g->vex[i] == v) a = i;
        if(g->vex[i] == w) b = i; 
    }
    g->arcs[a][b] =  0;
    g->arcs[b][a] = 0;   
    g->arcNum--;
    return 1;
}

void Print(AMGraph g)
{
    cout << "Vexs:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << g.vex[i] << " ";
    }
    cout << endl << "Arcs:" << endl << "  ";
    for (int i = 0; i < N; i++)
    {
        if(g.vex[i]) cout << g.vex[i] << " ";
        else cout << "  ";
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        if(g.vex[i]) cout << g.vex[i] << " ";
        else cout << "  ";
        for (int j = 0; j < N; j++)
        {
            cout << g.arcs[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    AMGraph g;
    memset(g.arcs, 0, sizeof(g.arcs));
    memset(g.vex, 0, sizeof(g.vex));
    InsertVex(&g, 'a');
    InsertVex(&g, 'c');
    InsertVex(&g, 'b');
    InsertArc(&g, 'a', 'b');
    InsertArc(&g, 'b', 'c');
    DeleteArc(&g, 'b', 'c');
    Print(g);
    return 0;
}
