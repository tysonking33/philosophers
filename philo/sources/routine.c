#include "../includes/philosophers.h"

void	sleeping(t_philo *gen, int philo_inx, int type){
	display_message(philo_inx, type, gen);
	usleep((useconds_t)(gen->the_rules->mill_sec_to_sleep) * 1000);
	display_message(philo_inx, 5, gen);
	pick_up_fork(gen, philo_inx, 3);
}

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
	gen->state = 'H';
	pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
	if (philo_idx != gen->the_rules->phil_num)
		pthread_mutex_lock(&gen->the_rules->fork_arr[(philo_idx + 1)]);
	else 
		pthread_mutex_lock(&gen->the_rules->fork_arr[0]);
	display_message(philo_idx, type, gen);
	eat(gen, philo_idx, 1);
}

void    eat(t_philo *gen, int philo_idx, int type){
	gen->last_ate = timestamp();
	display_message(philo_idx, type, gen);
	usleep((useconds_t)(gen->the_rules->mill_sec_to_eat) * 1000);
	gen->time_eaten++;
	put_down_fork(gen, philo_idx, 4);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
	gen->state = 'T';
	pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx]);
	if (philo_idx != gen->the_rules->phil_num)
		pthread_mutex_unlock(&gen->the_rules->fork_arr[(philo_idx + 1)]);
	else 
		pthread_mutex_unlock(&gen->the_rules->fork_arr[0]);
	if (gen->time_eaten >= gen->the_rules->min_meal_to_stop)
	{
		printf("%d is full\n", philo_idx);
		pthread_exit(NULL);
	}
	display_message(philo_idx, type, gen);
	sleeping(gen, philo_idx, 2);
}


