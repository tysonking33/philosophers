#include "../includes/philosophers.h"

int     destroy_threads(t_rules *gen){
    int i = 0;
	
    while (i < gen->phil_num)
	{
        pthread_mutex_destroy(&gen->fork_arr[i]);
		printf("destroyed fork %d\n", i);
		i++;
	}
	pthread_mutex_destroy(&gen->critical_region_mutex);
	printf("destroyed critical_region_mutex\n");
	pthread_mutex_destroy(&gen->output_mutex);
	printf("destroyed output_mutex\n");

    return 1;
}
