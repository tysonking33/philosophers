#include "../includes/philosophers.h"

void    pick_up_fork(t_rules *gen, int philo_idx){
    pthread_mutex_lock(&gen->fork_arr[philo_idx]);
    pthread_mutex_lock(&gen->fork_arr[(philo_idx+1)%gen->phil_num]);
    display_message(philo_idx, 3);
}

void    eat(t_rules *gen, int philo_idx){
    usleep(gen->mill_sec_to_sleep);
    display_message(philo_idx, 1);
}

void    put_down_fork(t_rules *gen, int philo_idx){
    pthread_mutex_unlock(&gen->fork_arr[philo_idx]);
    pthread_mutex_unlock(&gen->fork_arr[(philo_idx+1)%gen->phil_num]);
    display_message(philo_idx, 4);
}
