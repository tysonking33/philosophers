#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
    t_rules *gen;
    gen = (t_rules *)malloc(sizeof(t_rules));
    if (!gen)
        return 0;
    

    
    
    

    for (i = 0; i<5; i++)
    {
        pthread_join(T[i], NULL); //making the parent program wait for each thread to finish
    }


    //initalise rules
    if (init_all(gen, argc, argv) != 1)
        return 0;




    //initalise threads
    init_threads(gen);

    //jointhreads
    do_your_thing_21();
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