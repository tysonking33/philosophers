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

void	alive(t_rules *gen){
	int i;
	int c;

	i = 0;
	while (i == 0){
		c = 0;
		while (c < gen->phil_num){
			usleep(100);
			if ((timestamp() - gen->philo_arr[c].last_ate) >= gen->mill_sec_to_die){
				display_message(c, 100, &gen->philo_arr[c]);
				printf("%lld, %ld\n", timestamp(), gen->philo_arr[c].last_ate);
				i = 1;
				exit(0);
			}
			c++;
		}
	}

}

long	totaltime(t_philo *gen)
{
	return (timestamp() - gen->init);
}

