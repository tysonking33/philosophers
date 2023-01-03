#include "../includes/philosophers.h"

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
	pthread_mutex_lock(&gen->the_rules->fork_arr[philo_idx]);
	pthread_mutex_lock(&gen->the_rules->fork_arr[(philo_idx
				+ gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num)]);
	//printf("forks locked: %d, %d\n\n", philo_idx, (philo_idx + gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num));
	display_message(philo_idx, type);
}

void    eat(t_philo *gen, int philo_idx, int type){
	usleep(gen->the_rules->mill_sec_to_sleep);
	display_message(philo_idx, type);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
    pthread_mutex_unlock(&gen->the_rules->fork_arr[philo_idx]);
    pthread_mutex_unlock(&gen->the_rules->fork_arr[(philo_idx + gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num)]);
    display_message(philo_idx, type);
	//printf("forks unlocked: %d, %d\n\n", philo_idx, (philo_idx + gen->the_rules->phil_num - 1) % (gen->the_rules->phil_num));
}
