#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <sys/time.h>

typedef struct s_rules
{
    int phil_num;
    int mill_sec_to_eat;
    int min_meal_to_stop;
    int mill_sec_to_sleep;
    int mill_sec_to_die;
    pthread_mutex_t *fork_arr;
    struct s_philo *philo_arr;
}               t_rules;

typedef struct s_philo
{
    int id;
    int left_fork;
    int right_fork;
    int last_ate;
    int is_eating;
}               t_philo;

/* found in main.c */
int     main(int argc, char **argv);

/* found in display_message.c */
void    display_message(int philo_idx, int type);
char    *return_message(int type);

/* found in start_thread.c */
int     join_threads(t_rules *gen);
void    routine(t_rules *gen);

/* found in routine.c */
void    pick_up_fork(t_rules *gen, int philo_idx);
void    eat(t_rules *gen, int philo_idx);
void    put_down_fork(t_rules *gen, int philo_idx);

/* found in destroy_threads.c */
int     destroy_threads(t_rules *gen);

/* found in utils.c */
void    error(char *s);

/* found in initalise.c */
int     init_all(t_rules *gen, int argc, char **argv);
void    init_philo(t_rules *gen);
void    init_mutex(t_rules *gen);


#endif