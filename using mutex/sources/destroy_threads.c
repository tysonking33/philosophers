#include "../includes/philosophers.h"

int     destroy_threads(t_rules *gen){
    int i = 0;
	
    while (i < gen->phil_num)
	{
        pthread_mutex_destroy(&gen->fork_arr[i]);
		printf("destroyed fork %d\n", i);
		i++;
	}
    return 1;
}
