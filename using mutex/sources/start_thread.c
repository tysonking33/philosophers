#include "../includes/philosophers.h"

int    join_threads(t_rules *gen){
    int i = 0;
    void *philo;
    while (i < gen->phil_num)
    {
        philo = (void *)(&gen->philo_arr[i]);
        if (pthread_create(&gen->fork_arr[i], NULL, &routine, philo) != 0)
            return 0;
        pthread_join(&gen->fork_arr[i], NULL);
    }
    return 1;
}

void    routine(t_rules *gen){
    int i;

    i = 0;
    while (i < gen->phil_num){
        pick_up_fork(i, 3);
        eat(i, 1);
        put_down_fork(i, 4);
        display_message(i, 5);
        i++;
    }
}