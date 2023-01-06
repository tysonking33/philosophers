#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

struct s_rules;

typedef struct s_philo
{
    int id;
    int last_ate;
	int is_working;
	int	meal_count;
	char state;
    struct s_rules *the_rules;
}               t_philo;


typedef struct s_rules
{
    int phil_num;
    int mill_sec_to_eat;
    int max_meals;
    int mill_sec_to_sleep;
	int mill_sec_to_die;
	long long int	inital_time;
	pthread_mutex_t critical_region_mutex;
	pthread_mutex_t output_mutex;
    pthread_mutex_t fork_arr[1000];
    struct s_philo philo_arr[1000];
}               t_rules;



/* found in main.c */
int     main(int argc, char **argv);

/* found in display_message.c */
void    display_message(t_rules *gen, int philo_idx, int type);
char    *return_message(int type);

/* found in start_thread.c */
int     join_threads(t_rules *gen);
void    *routine(void  *gen);

/* found in routine.c */
void    sleeping(t_philo *gen, int philo_idx, int type);
void    pick_up_fork(t_philo *gen, int philo_idx, int type);
void    eat(t_philo *gen, int philo_idx, int type);
void    put_down_fork(t_philo *gen, int philo_idx, int type);

/* found in destroy_threads.c */
int     destroy_threads(t_rules *gen);

/* found in utils.c */
void    error(char *s);
long long int	timestamp(void);

/* found in initalise.c */
int     init_all(t_rules *gen, int argc, char **argv);
void    init_philo(t_rules *gen);
void    init_mutex(t_rules *gen);
void	loop_rules(t_rules *gen);

#endif
