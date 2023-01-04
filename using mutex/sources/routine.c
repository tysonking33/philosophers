#include "../includes/philosophers.h"

void	thinking(t_philo *gen, int philo_idx, int type){
	int	thinking_time;

	thinking_time = 400;
	pthread_mutex_lock(&gen->output_mutex);
	display_message(philo_idx, type);
	usleep(thinking_time);
}

void    pick_up_fork(t_philo *gen, int philo_idx, int type){
	pthread_mutex_lock(&gen->critical_region_mutex);
	gen->state = "Hungry";
	pthread_mutex_lock(&gen->output_mutex);

	display_message(philo_idx, type);
}

void    eat(t_philo *gen, int philo_idx, int type){
	display_message(philo_idx, type);
}

void    put_down_fork(t_philo *gen, int philo_idx, int type){
	display_message(philo_idx, type);
}
