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
	timeStamp = current_time.tv_usec;
	return (timeStamp);
}
