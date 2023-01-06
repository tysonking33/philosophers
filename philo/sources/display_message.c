#include "../includes/philosophers.h"

void    display_message(int philo_idx, int type, t_philo *gen){
    printf("%ld: philosopher %d %s\n", totaltime(gen), philo_idx, return_message(type));
}

char *return_message(int type)
{
    if (type == 1)
        return (" is eating\n");
    else if (type == 2)
        return (" is sleeping\n");
    else if (type == 3)
        return (" has taken a fork\n");
    else if (type == 4)
        return (" has finished eating, put down the dork, aka is thinking\n");
	else if (type == 5)
		return (" is thinking\n");
    else
        return (" died\n");
}
