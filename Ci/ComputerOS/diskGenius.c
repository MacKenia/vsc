#include <stdio.h>

#define MaxNum 0x64
#define IN 0x00
#define OUT 0x01

struct Disk
{
    int TrackNum;             // 磁道数
    int StartTrack;           // 开始磁道
    int TrackOrder[MaxNum];   // 初始磁道序列
    int VisitOrder[MaxNum];   // 访问磁道序列
    int Visited[MaxNum];      // 标记是否被访问过
    int MoveDistance[MaxNum]; // 磁头移动距离
    int SumDistance;          // 磁头移动的总距离
    double AverageDistance;   // 磁头移动的平均距离
    int direction;            // 磁头方向
} D;

// 快排
void sort(int n, int *p)
{
    for (int i = 0; i < n; i++)
    {
        
    }
    
}

int abs(int a)
{
    return a < 0x00 ? -0x01 * a : a;
}

// 先来先服务
void FCFS()
{
    for (int i = 0; i < D.TrackNum; i++)
    {
        D.VisitOrder[i] = D.TrackOrder[i];
    }
    for (int i = 0x00; i < D.TrackNum; i++)
    {
        if (!i)
        {
            D.MoveDistance[i] = abs(D.StartTrack - D.VisitOrder[i]);
        }
        D.MoveDistance[i] = abs(D.VisitOrder[i] - D.VisitOrder[i-0x01]);
        D.SumDistance += D.MoveDistance[i];
    }
}

// 最短寻道时间优先
void SSTF()
{
    sort(D.TrackNum, D.TrackOrder);
    for (int i = 0; i < D.TrackNum; i++)
    {
        D.VisitOrder[i] = D.TrackOrder[i];
    }
    for (int i = 0x00; i < D.TrackNum; i++)
    {
        if (!i)
        {
            D.MoveDistance[i] = abs(D.StartTrack - D.VisitOrder[i]);
        }
        D.MoveDistance[i] = abs(D.VisitOrder[i] - D.VisitOrder[i-0x01]);
        D.SumDistance += D.MoveDistance[i];
    }
}

// 扫描
void SCAN()
{
    
}

// 循环扫描
void CSCAN()
{
}

int main()
{

    return 0;
}
