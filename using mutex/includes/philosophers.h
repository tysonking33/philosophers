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
    int left_fork;
    int right_fork;
    int last_ate;
    int is_eating;
	int is_working;
	char state;
    struct s_rules *the_rules;
}               t_philo;


typedef struct s_rules
{
    int phil_num;
    int mill_sec_to_eat;
    int min_meal_to_stop;
    int mill_sec_to_sleep;
    int mill_sec_to_die;
	pthread_mutex_t critical_region_mutex;
	pthread_mutex_t output_mutex;
    pthread_mutex_t fork_arr[1000];
    struct s_philo philo_arr[1000];
}               t_rules;



/* found in main.c */
int     main(int argc, char **argv);

/* found in display_message.c */
void    display_message(int philo_idx, int type);
char    *return_message(int type);

/* found in start_thread.c */
int     join_threads(t_rules *gen);
void    *routine(void  *gen);

/* found in routine.c */
void    thinking(t_philo *gen, int philo_idx, int type);
void    pick_up_fork(t_philo *gen, int philo_idx, int type);
void    eat(t_philo *gen, int philo_idx, int type);
void    put_down_fork(t_philo *gen, int philo_idx, int type);
void    test(t_philo *gen, int philo_idx);
int     find_left_N(t_philo *gen, int philo_idx);
int     find_right_N(t_philo *gen, int philo_idx);
void    acquire(t_philo *gen, int philo_idx);

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
