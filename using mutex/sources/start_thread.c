#include "../includes/philosophers.h"

int join_threads(t_rules *gen)
{
    int i = 0;
    pthread_t tid[1000];
	
	gen->inital_time = timestamp();
    while (i < gen->phil_num)
	{
        if (pthread_create(&tid[i], NULL, routine, &(gen->philo_arr[i])))
			return 0;
        i++;
	}
	i = 0;
	while (i < gen->phil_num)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
    return 1;
}

void *routine(void *gen)
{
    t_philo *phillu;

    phillu = (t_philo *)malloc(sizeof(t_philo *));
    phillu = (t_philo *)gen;
	/*printf("phillu->id %d is here\n", phillu->id);
	while (phillu->is_working == 0)
	{
		printf("test1\n");
		sleeping(phillu, phillu->id, 2);
		printf("test2\n");
		pick_up_fork(phillu, phillu->id, 3);
		printf("test3\n");
		eat(phillu, phillu->id, 1);
		printf("test4\n");
		put_down_fork(phillu, phillu->id, 4);
	}*/
	if (phillu->id % 2 == 0)
		sleeping(phillu, phillu->id, 2);
	else
		pick_up_fork(phillu, phillu->id, 3);
    
    return ((void *)0);
}
