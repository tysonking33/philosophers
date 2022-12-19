#include "../includes/philosophers.h"

void error(char *s)
{
	printf("error: %s\n", s);
	exit(1);
}

int	init_rules(t_philo *gen, int argc, char **argv){
	if (!gen)
		return (0);
	if ((argc != 5) || (argc != 6))
        error("invalid arguments");
	gen->phil_num = ft_atoi(argc[1]);
    gen->mill_sec_to_die = ft_atoi(argc[2]);
    gen->mill_sec_to_eat = ft_atoi(argc[3]);
    gen->mill_sec_to_sleep = ft_atoi(argc[4]);
    if (argc == 6)
        gen->min_meal_to_stop = ft_atoi(argc[5]);
	else
		gen->min_meal_to_stop = 0;
	if 	((gen->phil_num < 2) || (gen->phil_num < 0) || (gen->mill_sec_to_die < 0)
		|| (gen->mill_sec_to_sleep < 0) || (gen->min_meal_to_stop < 0))
		error("invalid values");
	return (1);
}


void    init_mutex(t_philo *gen){
	pthread_mutex_t *chopstick;
	
	chopstick = (pthread_mutex_t *)malloc((gen->phil_num)sizeof(pthread_mutex_t *);
	int ctr = 0;
	while (ctr < gen->phil_num)
	{
		pthread_mutex_init(&chopstick[i], 1);
		ctr++;
	}
}

void    init_threads(t_philo *gen){
	int n;
    pthread_t ph_thread[5]; //each philospher has 1 thread

	n = (int *)malloc(gen->phil_num * sizeof (int));
	ph_thread = (pthread_t *)malloc(gen->phil_num * sizeof (pthread_t));

    ctr = 0;
    while (ctr < gen->phil_num)
    {
        n[ctr] = ctr;
        pthread_create(&ph_thread[i], NULL, philos_werk, (void *)&n[i]); //creating threads, 1 thread = 1 philospher
    }
}

void *philos_werk(void *n)
{
		

}
