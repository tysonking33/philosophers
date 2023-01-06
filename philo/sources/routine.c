#include "../includes/philosophers.h"

void	sleeping(t_philo *gen, int philo_idx, int type){
	display_message(gen, philo_idx, 1);
	usleep((useconds_t)gen->the_rules->mill_sec_to_sleep * 1000);
	display_message(gen, philo_idx, 5);
	pick_up_fork(gen, philo_idx, type);
}

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
	gen->state = 'H';
	pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
	if (philo_idx != gen->the_rules->phil_num)
		pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx + 1]);
	else
		pthread_mutex_lock(&gen->the_rules->fork_arr[0]);
	display_message(gen, philo_idx, 2);
	eat(gen, philo_idx, type);
}

void    eat(t_philo *gen, int philo_idx, int type){
	gen->last_ate = timestamp();
	usleep((useconds_t)gen->the_rules->mill_sec_to_eat * 1000);
	display_message(gen, philo_idx, 3);
	gen->meal_count++;
	printf("philosopher %d ate %d times\n", philo_idx, gen->meal_count);
	put_down_fork(gen, philo_idx, type);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
	gen->the_rules->routine_count++;
	gen->state = 'T';
	pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx]);
	if (philo_idx != gen->the_rules->phil_num)
		pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx + 1]);
	else
		pthread_mutex_unlock(&gen->the_rules->fork_arr[0]);
	display_message(gen, philo_idx, 4);
	if ((gen->meal_count >= gen->the_rules->max_meals) && (gen->the_rules->max_meals > 0))
	{
		printf("philosopher %d ate %d times and is full\n", philo_idx, gen->meal_count);
		pthread_exit(NULL);
	}
	/*if (gen->the_rules->routine_count >= 50)
	{
		printf("philosopher %d has done routines 50 times\n", philo_idx);
		pthread_exit(NULL);
	}*/
	sleeping(gen, philo_idx, type);
}

