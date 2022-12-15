#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*gen;
	gen = (t_philo *)malloc(sizeof(t_philo));
	
	if (!gen)
		return 0;
	if ((argc != 5) || (argc != 6))
		error("invalid arguments");
	init_all(gen, argc, argv);
	
