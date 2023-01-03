#include "../includes/philosophers.h"

int join_threads(t_rules *gen)
{
    int i = 0;
    pthread_t tid;
	
    while (i < gen->phil_num)
	{
        if (pthread_create(&tid/*gen->philo_arr[i]*/, NULL, routine, &(gen->philo_arr[i])))
			return 0;
		pthread_join(tid/*gen->philo_arr[i]*/, NULL);
        i++;
	}
    return 1;
}

void *routine(void *gen)
{
    t_philo *phillu;

    phillu = (t_philo *)malloc(sizeof(t_philo *));
    phillu = (t_philo *)gen;
	pick_up_fork(phillu, phillu->id, 3);
    eat(phillu, phillu->id, 1);
    put_down_fork(phillu, phillu->id, 4);
    display_message(phillu->id, 5);
    
    return ((void *)0);
}
