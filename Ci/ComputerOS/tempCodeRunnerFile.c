#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <windows.h>

pthread_mutex_t mutex;

struct readers
{
    int count;
    int max;
} r;

int readerctl(struct readers *r, pthread_mutex_t *mutex)
{
    if (!pthread_mutex_lock(mutex))
    {
        if (r->count < r->max)
        {
            r->count++;
            pthread_mutex_unlock(mutex);
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int readerdec(struct readers *r, pthread_mutex_t *mutex)
{
    if (!pthread_mutex_lock(mutex))
    {
        if (r->count > 0)
        {
            r->count--;
            pthread_mutex_unlock(mutex);
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int writerctl(struct readers *r, pthread_mutex_t *mutex)
{
    if (!r->count)
    {
        pthread_mutex_trylock(mutex);
        return 1;
    }
    else
        return 0;
}

void *writer()
{
    int c = 1;
    while (c)
    {
        if (writerctl(&r, &mutex))
        {
            printf("Writer is writing chapter %d\n", c++);
            Sleep(1000);
            printf("Writer is done writing\n");
            pthread_mutex_unlock(&mutex);
        }
        Sleep(200);
    }
}

void *reader(void *args)
{
    int id = *(int *)args + 1;
    while (1)
    {
        if (readerctl(&r, &mutex))
        {
            printf("Reader %d is reading\n", id);
            Sleep(1000);
            printf("Reader %d is done reading\n", id);
            readerdec(&r, &mutex);
        }
        Sleep(300);
    }
}

int main()
{
    r.max = 2;
    pthread_t twriter;
    pthread_t treader[2];
    pthread_create(&twriter, NULL, writer, NULL);
    for (int i = 0; i < 2; i++)
    {
        pthread_create(&treader[i], NULL, reader, (void *)&i);
        Sleep(1);
    }
    Sleep(10000);
    return 0;
}