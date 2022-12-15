void	init_mutex(t_philo *gen)
{
	
	//int pthread_mutex_init(pthread_mutex_t *restrict mutex,const pthread_mutexattr_t *restrict attr);
	pthread_mutex_init

}

void	init_philo(t_philo *gen)
{

}

void	init_all(t_philo *gen, int argc, char **argv)
{
	gen->phil_num = ft_atoi(argc[1]);
	gen->mill_sec_to_die = ft_atoi(argc[2]);
	gen->mill_sec_to_eat = ft_atoi(argc[3]);
	gen->mill_sec_to_sleep = ft_atoi(argc[4]);

	if (argc == 6)
		gen->min_meal_to_stop = ft_atoi(argc[5]);

	if (gen->phil_num < 2)
		error("less than 2 philosophers");

	if ((gen->mill_sec_to_die < 0) || (gen->mill_sec_to_eat < 0)
			|| (gen->mill_sec_to_sleep < 0) || (gen->min_meal_to_stop < 0))
		error("negative time???");
	init_mutex(gen)
