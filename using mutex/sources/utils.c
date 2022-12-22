#include "../includes/philosophers.h"

void error(char *s)
{
	printf("error: %s\n", s);
	exit(1);
}

void    init_threads(t_rules *gen){
	int n;
    pthread_t ph_thread[5]; //each philospher has 1 thread

	n = (int *)malloc(gen->phil_num * sizeof (int));
	ph_thread = (pthread_t *)malloc(gen->phil_num * sizeof (pthread_t));

    ctr = 0;
    while (ctr < gen->phil_num)
    {
        n[ctr] = ctr;
        pthread_create(&ph_thread[i], NULL, philos_werk, (void *)&n[i]); //creating threads, 1 thread = 1 philospher
    }
}

