#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

pthread_mutex_t chopsticks[5];

int sWait(pthread_mutex_t *left, pthread_mutex_t *right)
{
    if(!pthread_mutex_trylock(left) && !pthread_mutex_trylock(right))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sSignal(pthread_mutex_t *left, pthread_mutex_t *right)
{
    pthread_mutex_unlock(left);
    pthread_mutex_unlock(right);
}

void *Philosopher(void* tid)
{
    int id = *(int*)tid + 1;
    printf("[Philosopher %d] is ready.\n", id);
    while (1)
    {
        if (sWait(&chopsticks[id], &chopsticks[(id + 1) % 5]))
        {
            printf("Philosopher %d is eating\n", id);
            sSignal(&chopsticks[id], &chopsticks[(id + 1) % 5]);
        }
        Sleep(rand()%1000);
    }
}

int main()
{
    pthread_t threads[5];
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, Philosopher, (void*)&i);
        Sleep(1); // 等待当前线程创建完成再进行下一个线程的创建
    }
    Sleep(1000*10);
    return 0;
}
