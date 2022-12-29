#include "../includes/philosophers.h"

int    join_threads(t_rules *gen){
    int i = 0;
    void *philo;
    while (i < gen->phil_num)
    {
        philo = (void *)(&gen->philo_arr[i]);
        if (pthread_create(gen->fork_arr[i], NULL, routine, gen->philo_arr[i]) != 0)
            return 0;
        pthread_join(gen->fork_arr[i], NULL);
    }
    return 1;
}

void    *routine(void *gen){
    int i;
    t_philo *phillu;

    i = 0;
    phillu = (t_philo *)malloc(sizeof(t_philo *));
    phillu = (t_philo *)gen;
    pick_up_fork(phillu, i, 3);
    eat(phillu, i, 1);
    put_down_fork(phillu, i, 4);
    display_message(i, 5);
}