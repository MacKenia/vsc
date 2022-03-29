#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

struct chopstick
{
    pthread_mutex_t mutex;
}chopsticks[5];

int sWait(struct chopstick *left, struct chopstick *right)
{
    if(!pthread_mutex_trylock(&left->mutex) && !pthread_mutex_trylock(&right->mutex))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sSignal(struct chopstick *left, struct chopstick *right)
{
    pthread_mutex_unlock(&left->mutex);
    pthread_mutex_unlock(&right->mutex);
}

void *Philosopher(void* tid)
{
    int id = *((int*)tid);
    while (1)
    {
        if (sWait(&chopsticks[id], &chopsticks[(id + 1) % 5]))
        {
            printf("%d is eating\n", id);
            sSignal(&chopsticks[id], &chopsticks[(id + 1) % 5]);
        }
        Sleep(1000);
    }
}

int main()
{
    pthread_t threads[5];
    for(int i; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, Philosopher, (void*)&i);
    }
    Sleep(1000*10);
    return 0;
}
