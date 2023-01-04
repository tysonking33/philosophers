#include "../includes/philosophers.h"

int	run_routine(t_rules *gen)
{
	while (1)
	{
		think(gen);
		take_forks(gen);
		eat(gen);
		put_forks(gen);
	}
	return (1);
}


