#include "../includes/philosophers.h"

void	thinking(t_philo *gen, int philo_idx, int type){
	int	think_time;

	think_time = 400;
	{
		pthread_mutex_lock(&gen->the_rules->output_mutex);
	}
	usleep(400);
	display_message(philo_idx, type);
	pthread_mutex_unlock(&gen->the_rules->output_mutex);
}

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
	pthread_mutex_lock(&gen->the_rules->critical_region_mutex);
	gen->state = 'H';
	{
		pthread_mutex_lock(&gen->the_rules->output_mutex);
	}
	test(gen, philo_idx);
	pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
	pthread_mutex_lock(&gen->the_rules->fork_arr[(philo_idx + gen->the_rules->phil_num - 1) % gen->the_rules->phil_num]);
	display_message(philo_idx, type);
	pthread_mutex_unlock(&gen->the_rules->critical_region_mutex);
	pthread_mutex_unlock(&gen->the_rules->output_mutex);
	acquire(gen, philo_idx);
}

void    eat(t_philo *gen, int philo_idx, int type){
	pthread_mutex_lock(&gen->the_rules->output_mutex);
	usleep(gen->the_rules->mill_sec_to_sleep);
	display_message(philo_idx, type);
	pthread_mutex_unlock(&gen->the_rules->output_mutex);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
	pthread_mutex_lock(&gen->the_rules->critical_region_mutex);
	gen->state = 'T';
	test(&gen->the_rules->philo_arr[find_left_N(gen, philo_idx)], philo_idx);
	test(&gen->the_rules->philo_arr[find_right_N(gen, philo_idx)], philo_idx);
	display_message(philo_idx, type);
	pthread_mutex_unlock(&gen->the_rules->critical_region_mutex);
}

void	test(t_philo *gen, int philo_idx){
	if (gen->state == 'H'
			&& gen->the_rules->philo_arr[find_left_N(gen, philo_idx)].state != 'E'
			&& gen->the_rules->philo_arr[find_right_N(gen, philo_idx)].state != 'E')
	{
		gen->state = 'E';
		pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx]);
		pthread_mutex_unlock(&gen->the_rules->fork_arr[(philo_idx + gen->the_rules->phil_num - 1) % gen->the_rules->phil_num]);
	}
	else
		gen->is_working = 1;
}

int		find_left_N(t_philo *gen, int philo_idx){
	return ((gen->the_rules->phil_num + philo_idx - 1) % gen->the_rules->phil_num);
}

int		find_right_N(t_philo *gen, int philo_idx){
	return ((philo_idx + 1) % gen->the_rules->phil_num);
}

void	acquire(t_philo *gen, int philo_idx){
	if (!(pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx])) || !(pthread_mutex_lock(&gen->the_rules->fork_arr[(philo_idx + gen->the_rules->phil_num - 1) % gen->the_rules->phil_num]))){
		gen->is_working = 1;
	}
}
