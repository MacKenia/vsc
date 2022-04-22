#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 0x05
#define MAX_TIME 0xFF

#define WAIT 0x01

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
}q_queue[MAX_PROCESSES];

uint g_time = 0x00;

void Simulator(); // simulate the process
void Init_PCB(); // initialize the PCB
void Init_Queue(); // initialize the queue
uint Create_Process(uint pri, uint need_time); // create a process
void Run_Process(); // run a process
uint Get_PriProcess(); // get the process with the highest priority
void Work_Process(); // work a process
void Change_Process(uint id); // change the state of a process
void Print_State(); // print the queue
void End_Process(); // end a process



int main()
{
    return 0;
}


void Init_PCB()
{
    for(uint i = 0x00; i < MAX_PROCESSES; i++)
    {
        q_queue[i].p_id = i;
        q_queue[i].p_static_priority = MIN_PRIORITY;
        q_queue[i].p_dynamic_priority = MIN_PRIORITY;
        q_queue[i].p_arrive_time = 0x00;
        q_queue[i].p_need_time = 0x00;
        q_queue[i].p_used_time = 0x00;
        q_queue[i].p_state = WAIT;
    }
}

void Init_Queue()
{
    for(uint i = 0x00; i < MAX_PROCESSES; i++)
    {
        q_queue[i].p_id = i;
        q_queue[i].p_static_priority = MIN_PRIORITY;
        q_queue[i].p_dynamic_priority = MIN_PRIORITY;
        q_queue[i].p_arrive_time = 0x00;
        q_queue[i].p_need_time = 0x00;
        q_queue[i].p_used_time = 0x00;
        q_queue[i].p_state = WAIT;
    }

}
