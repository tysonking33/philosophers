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
void    display_message(t_rules *gen, int i, int type);
char    *return_message(int type);

/* found in start_thread.c */
int     join_threads(t_rules *gen);
void    routine(void *gen);

/* found in routine.c */
void    pick_up_fork(t_rules *gen, int i);
void    eat(t_rules *gen, int i);
void    put_down_fork(t_rules *gen, int i);

/* found in destroy_threads.c */
int     destroy_threads(t_rules *gen);

/* found in utils.c */
void    error(char *s);

#endif