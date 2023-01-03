#include "../includes/philosophers.h"

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
	pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
	pthread_mutex_lock(&gen->the_rules->fork_arr[gen->the_rules->philo_arr[philo_idx].right_fork]);
	//printf("forks locked: %d, %d\n\n", philo_idx, gen->the_rules->philo_arr[philo_idx].right_fork);
	display_message(philo_idx, type);
}

void    eat(t_philo *gen, int philo_idx, int type)
{
	pthread_mutex_lock(&gen->mutex);
	gen->the_rules->philo_arr[philo_idx].is_eating = 1;
	usleep(gen->the_rules->mill_sec_to_sleep);
	display_message(philo_idx, type);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
	pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx]);
	pthread_mutex_unlock(&gen->the_rules->fork_arr[gen->the_rules->philo_arr[philo_idx].right_fork]);
    display_message(philo_idx, type);
	//printf("forks unlocked: %d, %d\n\n", philo_idx, gen->the_rules->philo_arr[philo_idx].right_fork);
}
