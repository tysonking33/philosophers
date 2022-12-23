#include "../includes/philosophers.h"

void    pick_up_fork(t_rules *gen, int i){
    pthread_mutex_lock(gen->fork_arr[i]);
    pthread_mutex_lock(gen->fork_arr[(i+1)%gen->phil_num]);
    display_message(gen, i, 3);
}

void    eat(t_rules *gen, int i){
    usleep(gen->mill_sec_to_sleep);
    display_message(gen, i, 1);
}

void    put_down_fork(t_rules *gen, int i){
    pthread_mutex_unlock(gen->fork_arr[i]);
    pthread_mutex_unlock(gen->fork_arr[(i+1)%gen->phil_num]);
    display_message(gen, i, 4);
}
