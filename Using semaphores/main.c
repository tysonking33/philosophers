#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5]; //declare 5 semaphore variables, 1 per chopstick variable
void *philos(void *);
void eat(int);

int main()
{
    int i, n[5];
    pthread_t T[5]; //each philospher has 1 thread
    for (i = 0; i < 5; i++)
    {
        sem_init(&chopstick[i], 0, 1); //initalising the semaphore variables, w/ init value 1
    }
    for (i = 0; i<5; i++)
    {
        n[i] = i;
        pthread_create(&T[i], NULL, philos, (void *)&n[i]); //creating threads, 1 thread = 1 philospher
    }
    for (i = 0; i<5; i++)
    {
        pthread_join(T[i], NULL); //making the parent program wait for each thread to finish
    }
}

void * philos(void * n)
{
    int ph=*(int *)n;
    printf("Philosopher %d wants to eat\n",ph);
    printf("Philosopher %d tries to pick left chopstick\n",ph);
    sem_wait(&chopstick[ph]); //sem_wait() = picking up the chopstick
    printf("Philosopher %d picks the left chopstick\n",ph);
    printf("Philosopher %d tries to pick the right chopstick\n",ph);
    sem_wait(&chopstick[(ph+1)%5]); // have to go around to the other side of the philopsher (5 is number of philosphers)
    printf("Philosopher %d picks the right chopstick\n",ph);
    eat(ph); //only occurs if both chopsticks are picked up
    sleep(2); //pauses current thread for 2 seconds, allowng for other philosophers to eat
    printf("Philosopher %d has finished eating\n",ph);
    sem_post(&chopstick[(ph+1)%5]); // put down right chopstick
    printf("Philosopher %d leaves the right chopstick\n",ph);
    sem_post(&chopstick[ph]); // put down left chopstick
    printf("Philosopher %d leaves the left chopstick\n",ph);
}

void eat(int ph)
{
    printf("Philosopher %d begins to eat\n",ph);
}