#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>


void *func(int n);
pthread_t philosopher[5];
pthread_mutex_t chopstick[5];

int main()
{
    int i,k;
    void *msg;
    for(i=1;i<=5;i++)
    {
        k=pthread_mutex_init(&chopstick[i],NULL);
        if(k==-1)
        {
            printf("\n Mutex initialization failed");
            exit(1);
        }
	}
	printf("wub wub 1\n");
	int *ptr_to_i;
    for(i=1;i<=5;i++)
    {
		ptr_to_i = &i;
        k=pthread_create(&philosopher[i],NULL,(void *)func, ptr_to_i);
        if(k!=0)
        {
            printf("\n Thread creation error \n");
            exit(1);
        }
	}
	printf("wub wub 2\n");
    for(i=1;i<=5;i++)
    {
        k=pthread_join(philosopher[i],&msg);
        if(k!=0)
        {
            printf("\n Thread join failed \n");
            exit(1);
        }
	}
	printf("wub wub 3\n");
    for(i=1;i<=5;i++)
    {
        k=pthread_mutex_destroy(&chopstick[i]);
        if(k!=0)
        {
            printf("\n Mutex Destroyed \n");
            exit(1);
        }
	}
	printf("wub wub 4\n");
    return 0;
}

void *func(int n)
{
    printf("\nPhilosopher %d is thinking ",n);
    pthread_mutex_lock(&chopstick[n]);//when philosopher 5 is eating he takes fork 1 and fork 5
    pthread_mutex_lock(&chopstick[(n+1)%5]);
    printf("\nPhilosopher %d is eating ",n);
    sleep(3);
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n+1)%5]);
    printf("\nPhilosopher %d Finished eating ", n);
	return ((void *)0);
}
