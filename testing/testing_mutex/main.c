#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
    t_philo gen;
    gen = (t_philo *)malloc(sizeof(t_philo));
    if (!gen)
        return 0;
    if ((argc != 5) || (argc != 6))
    {
        error("invalid arguments");
    }

    gen->phil_num = argc[1];
    gen->mill_sec_to_die = argc[2];
    gen->mill_sec_to_eat = argc[3];
    gen->mill_sec_to_sleep = argc[4];

    if (argc == 6)
        gen->min_meal_to_stop = argc[5];

    pthread_mutex_t *chopstick[gen->phil_num];
    int ctr = 0;
    while (ctr < gen->phil_num)
    {
        pthread_mutex_init(&chopstick[i], 1);
        ctr++;
    }
    
    int n[gen->phil_num];
    pthread_t T[5]; //each philospher has 1 thread

    ctr = 0;
    while (ctr < gen->phil_num)
    {
        n[ctr] = ctr;
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
