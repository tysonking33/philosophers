#include "../includes/philosophers.h"

void    display_message(t_philo *gen, int philo_idx, int type){
    printf("%ld philosopher %d %s\n", total_time(gen), philo_idx, return_message(type));
    //printf("philo id: %d, philo idx: %d, type: %d\n", gen->id, philo_idx, type);
}

char *return_message(int type)
{
    if (type == 1)
        return (" is sleeping\n");
    else if (type == 2)
        return (" has taken the forks\n");
    else if (type == 3)
        return (" is eating\n");
    else if (type == 4)
        return (" has finished eating, put down the dork, aka is thinking\n");
	else if (type == 5)
		return (" is thinking\n");
    else
        return (" died\n");
}
