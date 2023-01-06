#include "../includes/philosophers.h"

int join_threads(t_rules *gen)
{
    int i = 0;
    pthread_t tid[100];
	
    while (i < gen->phil_num)
	{
        if (pthread_create(&tid[i], NULL, routine, &(gen->philo_arr[i])))
			return 0;
		i++;
	}
	alive(gen);
	while (i >= 0)
	{
        pthread_join(tid[i], NULL);
		i--;
	}
    return 1;
}

void *routine(void *gen)
{
    t_philo *phillu;

    phillu = (t_philo *)malloc(sizeof(t_philo *));
    phillu = (t_philo *)gen;
	if (phillu->id % 2 == 0)
		sleeping(phillu, phillu->id, 2);
    else
		pick_up_fork(phillu, phillu->id, 3);
    return ((void *)0);
}
