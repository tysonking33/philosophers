#include "../includes/philosophers.h"

void error(char *s)
{
	printf("error: %s\n", s);
	exit(1);
}

long long int   timestamp(void){

	struct	timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}

long	total_time(t_philo *gen)
{
	return (timestamp() - gen->inital_time);
}
