#include "../includes/philosophers.h"

void	sleeping(t_philo *gen, int philo_idx, int type){
	usleep(gen->the_rules->mill_sec_to_sleep * 1000);
	display_message(gen->the_rules, philo_idx, 1);
	display_message(gen->the_rules, philo_idx, 5);
	pick_up_fork(gen, philo_idx, type);
}

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
	gen->state = 'H';
	pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
	if (philo_idx == gen->the_rules->phil_num)
		pthread_mutex_lock(&gen->the_rules->fork_arr[0]);
	else
		pthread_mutex_lock(&gen->the_rules->fork_arr[(philo_idx + 1)]);
	display_message(gen->the_rules, philo_idx, 2);
	eat(gen, philo_idx, type);
}

void    eat(t_philo *gen, int philo_idx, int type){
	usleep(gen->the_rules->mill_sec_to_eat * 100);
	display_message(gen->the_rules, philo_idx, 3);
	gen->meal_count++;
	printf("philosopher %d ate %d times\n", philo_idx, gen->meal_count);
	put_down_fork(gen, philo_idx, type);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
	static int routine_count = 0;
	routine_count++;
	gen->state = 'T';
	pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx]);
	if (philo_idx == gen->the_rules->phil_num)
		pthread_mutex_unlock(&gen->the_rules->fork_arr[0]);
	else
		pthread_mutex_unlock(&gen->the_rules->fork_arr[(philo_idx + 1)]);
	display_message(gen->the_rules, philo_idx, 4);
	if ((gen->meal_count >= gen->the_rules->max_meals) && (gen->the_rules->max_meals))
	{
		printf("philosopher %d ate %d times and is full\n", philo_idx, gen->meal_count);
		pthread_exit(NULL);
	}
	if (routine_count >= 50)
	{
		printf("philosopher %d has done routines 50 times\n", philo_idx);
		pthread_exit(NULL);
	}
	sleeping(gen, philo_idx, type);
}

