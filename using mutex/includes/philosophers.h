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
    int mill_sec_to_die;
    int mill_sec_to_eat;
    int mill_sec_to_sleep;
    int min_meal_to_stop;
    pthread_mutex_t *chopstick;
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


#endif