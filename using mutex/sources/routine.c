#include "../includes/philosophers.h"

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
<<<<<<< HEAD
	pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
	pthread_mutex_lock(&gen->the_rules->fork_arr[(philo_idx
				+ gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num)]);
	display_message(philo_idx, type);
	//printf("forks locked: %d, %d\n\n", philo_idx, (philo_idx + gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num));
=======
    pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
    pthread_mutex_lock(&gen->the_rules->fork_arr[(philo_idx+1)%gen->the_rules->phil_num]);
    display_message(philo_idx, type);
>>>>>>> 30c9b8554862147d9b110d7df4de57b2781810df
}

void    eat(t_philo *gen, int philo_idx, int type){
    usleep(gen->the_rules->mill_sec_to_sleep);
    display_message(philo_idx, type);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
    pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx]);
<<<<<<< HEAD
    pthread_mutex_unlock(&gen->the_rules->fork_arr[(philo_idx + gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num)]);
=======
    pthread_mutex_unlock(&gen->the_rules->fork_arr[(philo_idx+1)%gen->the_rules->phil_num]);
>>>>>>> 30c9b8554862147d9b110d7df4de57b2781810df
    display_message(philo_idx, type);
	//printf("forks unlocked: %d, %d\n\n", philo_idx, (philo_idx + gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num));
}
