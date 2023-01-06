#include "../includes/philosophers.h"

void error(char *s)
{
	printf("error: %s\n", s);
	exit(1);
}

long long int   timestamp(void){
	struct	timeval	current_time;
	long long int	timeStamp;

	gettimeofday(&current_time, NULL);
	timeStamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (timeStamp);
}

long	total_time(t_philo *gen)
{
	return (timestamp() - gen->inital_time);
}
