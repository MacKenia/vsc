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
    for (int i = 0; i < D.TrackNum; i++)
    {
        int t;
        for (int j = 0; j < D.TrackNum; j++)
        {
            int tmp;
            if (!i)
                tmp = abs(D.StartTrack - D.TrackOrder[j]);
            tmp = D.VisitOrder[i-1] - D.TrackOrder[i];
            if(tmp < t)
                t = j;
        }
        
        D.VisitOrder[i] = D.TrackOrder[t];
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
