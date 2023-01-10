#include "../includes/philosophers.h"

int	init_all(t_rules *gen, int argc, char **argv){
	if ((argc < 5) || (argc > 6))
        error("invalid arguments");
	gen->phil_num = atoi(argv[1]);
    gen->mill_sec_to_die = atoi(argv[2]);
    gen->mill_sec_to_eat = atoi(argv[3]);
    gen->mill_sec_to_sleep = atoi(argv[4]);
    if (argc == 6)
        gen->max_meals= atoi(argv[5]);
	else
		gen->max_meals = 9999;
	if 	((gen->phil_num < 1) || (gen->phil_num > 200) || (gen->mill_sec_to_die < 60)
		|| (gen->mill_sec_to_eat < 60) || (gen->mill_sec_to_sleep < 60))
		error("invalid values2");
	if ((gen->max_meals) && (gen->max_meals < 0))
		error("invalid values1");
	gen->routine_count = 0;
    //initalise mutex - mutex locks are the forks
    init_mutex(gen);

	//initalise philosophers
    init_philo(gen);

	//looping the philosopher array back to the generic structure
	loop_rules(gen);

	return (1);
}

void init_philo(t_rules *gen){
	int	ctr;

	ctr = 0;
	while (ctr < gen->phil_num)
	{
		//gen->philo_arr[ctr].state = 'H';
		gen->philo_arr[ctr].id = ctr + 1;
		gen->philo_arr[ctr].last_ate = timestamp();
		gen->philo_arr[ctr].inital_time = timestamp();
		gen->philo_arr[ctr].is_working = 0;
		gen->philo_arr[ctr].meal_count = 0;
		ctr++;
	}
	pthread_mutex_init(&gen->critical_region_mutex, NULL);
	pthread_mutex_init(&gen->output_mutex, NULL);
}

void    init_mutex(t_rules *gen){
	int ctr;
	
	ctr = 0;
	while (ctr < gen->phil_num)
	{
		if (pthread_mutex_init(&gen->fork_arr[ctr], NULL))
			error("pthread_mutex_init failed\n");
		ctr++;
	}
    //pthread_mutex_lock(&gen->fork_arr[0]);
    //pthread_mutex_lock(&gen->fork_arr[ctr + 1]);
    pthread_mutex_lock(&gen->fork_arr[0]);
    pthread_mutex_lock(&gen->fork_arr[ctr]);
}

void	loop_rules(t_rules *gen){
	int	ctr;

	ctr = 0;
	while (ctr < gen->phil_num)
	{
		gen->philo_arr[ctr].the_rules = gen;
		ctr++;
	}
}
