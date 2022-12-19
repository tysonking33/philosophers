#include "../includes/philosophers.h"

void error(char *s)
{
	printf("error: %s\n", s);
	exit(1);
}

int	init_all(t_rules *gen, int argc, char **argv){
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
	
    //initalise mutex - mutex locks are the forks
    init_mutex(gen);

	//initalise philosophers
    init_philo(gen);

	return (1);
}

void init_philo(t_rules *gen){
	int	ctr;

	ctr = 0;
	gen->philo_arr = (t_philo *)malloc(gen->phil_num * sizeof(t_philo));

	while (ctr < gen->phil_num)
	{
		gen->philo_arr[ctr].id = ctr;
		gen->philo_arr[ctr].left_fork = ctr;
		gen->philo_arr[ctr].right_fork = (ctr + 1) % gen->phil_num;
		gen->philo_arr[ctr].last_ate = 0;
		gen->philo_arr[ctr].is_eating = 0;
		ctr++;
	}
}

void    init_mutex(t_rules *gen){
	gen->chopstick = (pthread_mutex_t *)malloc((gen->phil_num)sizeof(pthread_mutex_t *);
	int ctr = 0;
	while (ctr < gen->phil_num)
	{
		if (!pthread_mutex_init(&gen->chopstick[i], NULL))
			error("failed mutex init\n") ;
		ctr++;
	}
}

void    init_threads(t_rules *gen){
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

