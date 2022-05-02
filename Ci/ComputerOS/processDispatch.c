#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 0x05
#define MAX_TIME 0xFF

#define WAIT 0x01
#define RUN 0x02
#define FINISH 0x03

#define ID_ERROR 0x10
#define MIN_PRIORITY 0xFF
#define MAX_PRIORITY 0x00

typedef unsigned int uint;

struct PCB_info
{
    char p_name[0x0a];
    uint p_id;
    uint p_static_priority;
    uint p_dynamic_priority;
    uint p_arrive_time;
    uint p_need_time;
    uint p_used_time;
    uint p_state;
} q_queue[MAX_PROCESSES];

uint g_time = 0x00;

void Simulator();                                           // simulate the process
void Init_Process();                                        // initialize the PCBs
void Init_Queue();                                          // initialize the queue
uint Create_Process(int p_id, uint pri, uint need_time);    // create a process
void Run_Process();                                         // run a process
uint Get_PriProcess();                                      // get the process with the highest priority
void Work_Process(uint id);                                 // work a process
void Change_Process(uint id);                               // change the state of a process
void Print_State();                                         // print the queue
void End_Process();                                         // end a process

int main()
{
    return 0;
}

void Simulator()
{
    Init_Process();
    Run_Process();
    End_Process();
}

void Init_Process()
{
    uint i, id;
    srand((unsigned)time(NULL));
    Init_Queue();
    for (i = 0x00; i < MAX_PROCESSES; i++)
    {
        id = Create_Process(i ,rand() % 4, rand() % 10);
        if (id == ID_ERROR)
        {
            printf("Create_Process error\n");
            exit(0x00);
        }
        else
        {
            printf("-----------------------------------------------------\n");
            printf("Create_Process success\n");
            printf("id: %d\n", id);
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
        id = q_queue[id].p_id;
        q_queue[id].p_static_priority = pri;
        q_queue[id].p_dynamic_priority = MIN_PRIORITY;
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
        q_queue[i].p_static_priority = MIN_PRIORITY;
        q_queue[i].p_dynamic_priority = MIN_PRIORITY;
        q_queue[i].p_arrive_time = 0x00;
        q_queue[i].p_need_time = 0x00;
        q_queue[i].p_used_time = 0x00;
        q_queue[i].p_state = FINISH;
    }
}

void Run_Process()
{
    uint id;
    