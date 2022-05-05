#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX_PROCESSES 0x05
#define MAX_TIME 0xFF

#define WAIT 0x01
#define RUN 0x02
#define FINISH 0x03

#define ID_ERROR 0x10
#define IMIN_PRIORITY 0xFF
#define IMAX_PRIORITY 0x00

typedef unsigned int uint;

struct PCB_info
{
    char p_name[0x0a];       // 进程名称
    uint p_id;               // 进程ID
    uint p_static_priority;  // 进程静态优先级
    uint p_dynamic_priority; // 进程动态优先级
    uint p_arrive_time;      // 进程到达时间
    uint p_need_time;        // 进程需要的时间
    uint p_used_time;        // 进程已经运行的时间
    uint p_state;            // 进程状态
} q_queue[MAX_PROCESSES];

uint g_time = 0x00;

void Simulator();                                        // 模拟运行
void Init_Process();                                     // 初始化进程
void Init_Queue();                                       // 初始化队列
uint Create_Process(int p_id, uint pri, uint need_time); // 创建进程
void Run_Process();                                      // 运行所有进程
uint Get_PriProcess();                                   // 获取优先级最高的进程
void Work_Process(uint id);                              // 运行单个并更改time等信息
void Change_Process(uint id);                            // 更改进程运行状态
void Print_Process();                                    // 打印进程信息
void End_Process(uint id);                               // 结束一个进程

int main()
{
    Simulator();
    return 0;
}

void Simulator()
{
    Init_Process();
    Run_Process();
}

void Init_Process()
{
    uint i, id;
    srand((unsigned)time(NULL));
    Init_Queue();
    for (i = 0x00; i < MAX_PROCESSES; i++)
    {
        id = Create_Process(i, rand() % 4, rand() % 10);
        if (id == ID_ERROR)
        {
            printf("Create_Process error\n");
            exit(0x00);
        }
        else
        {
            printf("-----------------------------------------------------\n");
            printf("Create_Process success\n");
            printf("id: %d\nInput Process name: ", id);
            scanf("%s", q_queue[id].p_name);
            printf("name: %s\n", q_queue[id].p_name);
            printf("static_priority: %d\n", q_queue[id].p_static_priority);
            printf("dynamic_priority: %d\n", q_queue[id].p_dynamic_priority);
            printf("arrive_time: %d\n", q_queue[id].p_arrive_time);
            printf("need_time: %d\n", q_queue[id].p_need_time);
            printf("used_time: %d\n", q_queue[id].p_used_time);
            printf("state: %d\n", q_queue[id].p_state);
            printf("-----------------------------------------------------\n");
        }
    }
}

uint Create_Process(int p_id, uint pri, uint need_time)
{
    uint id = ID_ERROR;
    if (q_queue[p_id].p_state == FINISH)
    {
        q_queue[id].p_id = p_id;
        id = q_queue[id].p_id;
        q_queue[id].p_static_priority = pri;
        q_queue[id].p_dynamic_priority = IMIN_PRIORITY;
        q_queue[id].p_need_time = need_time;
        q_queue[id].p_state = WAIT;
        q_queue[id].p_used_time = 0x00;
    }
    return id;
}

void Init_Queue()
{
    for (uint i = 0x00; i < MAX_PROCESSES; i++)
    {
        q_queue[i].p_id = i;
        q_queue[i].p_static_priority = IMIN_PRIORITY;
        q_queue[i].p_dynamic_priority = IMIN_PRIORITY;
        q_queue[i].p_arrive_time = 0x00;
        q_queue[i].p_need_time = 0x00;
        q_queue[i].p_used_time = 0x00;
        q_queue[i].p_state = FINISH;
    }
}

void Run_Process()
{
    uint id, time = 0x00;
    while ((id = Get_PriProcess()) != ID_ERROR)
    {
        printf("T: %ds\n", time++);
        // 模拟运行
        Work_Process(id);
        // 输出状态
        Print_Process();
        // 更换程序
        Change_Process(id);
        Sleep(0x3E8); // 等待1s
    }
    printf("所有进程已结束\n");
    Print_Process();
}

uint Get_PriProcess()
{
    uint id = ID_ERROR;
    uint pri = IMIN_PRIORITY*2;
    // 选出优先级最高的程序
    for (int i = 0x00; i < MAX_PROCESSES; i++)
    {
        if (q_queue[i].p_state != FINISH)
        {
            uint temp = q_queue[i].p_dynamic_priority + q_queue[i].p_static_priority;
            if (temp < pri)
            {
                pri = temp;
                id = i;
            }
        }
    }
    printf("Pri_Process is %d", id);
    return id;
}

void Work_Process(uint id)
{
    q_queue[id].p_used_time++;
    q_queue[id].p_state = RUN;
}

void Print_Process()
{
    printf("id\tname\tstatic_priority\tdynamic_priority\tarrive_time\tneed_time\tused_time\tstate\n");
    for (uint i = 0x00; i < MAX_PROCESSES; i++)
    {
        printf("%d\t", q_queue[i].p_id);
        printf("%s\t", q_queue[i].p_name);
        printf("%d\t", q_queue[i].p_static_priority);
        printf("\t%d\t", q_queue[i].p_dynamic_priority);
        printf("\t\t%d\t", q_queue[i].p_arrive_time);
        printf("\t%d\t", q_queue[i].p_need_time);
        printf("\t%d\t\t", q_queue[i].p_used_time);
        if (q_queue[i].p_state == WAIT)
            printf("WAIT\n");
        else if (q_queue[i].p_state == RUN)
            printf("RUN\n");
        else if (q_queue[i].p_state == FINISH)
            printf("FINISH\n");
    }
}

void Change_Process(uint id)
{
    // 更改当前进程的状态
    if (q_queue[id].p_need_time == q_queue[id].p_used_time)
        q_queue[id].p_state = FINISH;
    else
    {
        q_queue[id].p_state = WAIT;
        q_queue[id].p_dynamic_priority = IMIN_PRIORITY;
    }

    // 更新其他进程的优先级
    for (int i = 0x00; i < MAX_PROCESSES; i++)
        if ((i != id) && (q_queue[i].p_state != FINISH))
            q_queue[i].p_dynamic_priority > 0x00 ? q_queue[i].p_dynamic_priority-- : q_queue[i].p_dynamic_priority;
}

void End_Process(uint id)
{
    q_queue[id].p_state = FINISH;
}