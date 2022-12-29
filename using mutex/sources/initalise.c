#include "../includes/philosophers.h"

int	init_all(t_rules *gen, int argc, char **argv){
	if (!gen)
		return (0);
	if ((argc != 5) || (argc != 6))
        error("invalid arguments");
	gen->phil_num = atoi(argv[1]);
    gen->mill_sec_to_die = atoi(argv[2]);
    gen->mill_sec_to_eat = atoi(argv[3]);
    gen->mill_sec_to_sleep = atoi(argv[4]);
    if (argc == 6)
        gen->min_meal_to_stop = atoi(argv[5]);
	else
		gen->min_meal_to_stop = 0;
	if 	((gen->phil_num < 2) || (gen->mill_sec_to_die < 60)
		|| (gen->mill_sec_to_sleep < 60) || (gen->min_meal_to_stop < 0))
		error("invalid values");

    gen->philo_arr = NULL;
    gen->fork_arr = NULL;
	
    //initalise mutex - mutex locks are the forks
    init_mutex(gen);

	//initalise philosophers
    init_philo(gen);

	return (1);
}

void init_philo(t_rules *gen){
	int	ctr;

	ctr = 0;
	gen->philo_arr = (t_philo *)malloc(gen->phil_num * sizeof(t_philo *));
	if (!gen->philo_arr)
		error("gen->philo_arr, initalisation fail\n");

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
	gen->fork_arr = (pthread_mutex_t *)malloc((gen->phil_num) * sizeof(pthread_mutex_t *));
	int ctr = 0;
	while (ctr < gen->phil_num)
	{
		if (!pthread_mutex_init(&gen->fork_arr[ctr], NULL))
			error("failed mutex init\n");
		ctr++;
	}
}