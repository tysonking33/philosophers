/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:27:59 by tytang            #+#    #+#             */
/*   Updated: 2023/01/12 15:33:28 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include "../ft_printf/includes/ft_printf.h"

struct	s_rules;

typedef struct s_philo
{
	int				id;
	long long int	last_ate;
	int				meal_count;
	long long int	inital_time;
	struct s_rules	*the_rules;
}				t_philo;

typedef struct s_rules
{
	int				phil_num;
	int				mill_sec_to_eat;
	int				max_meals;
	int				mill_sec_to_sleep;
	int				mill_sec_to_die;
	pthread_mutex_t	critical_region_mutex;
	pthread_mutex_t	output_mutex;
	pthread_mutex_t	fork_arr[1000];
	struct s_philo	philo_arr[1000];
}				t_rules;

/* found in main.c */
int				main(int argc, char **argv);

/* found in display_message.c */
void			display_message(t_philo *gen, int philo_idx, int type);
char			*return_message(int type);

/* found in start_thread.c */
int				join_threads(t_rules *gen);
void			*routine(void *gen);
void			alive(t_rules *gen);

/* found in routine.c */
void			sleeping(t_philo *gen, int philo_idx, int type);
void			pick_up_fork(t_philo *gen, int philo_idx, int type);
void			eat(t_philo *gen, int philo_idx, int type);
void			put_down_fork(t_philo *gen, int philo_idx, int type);

/* found in destroy_threads.c */
int				destroy_threads(t_rules *gen);

/* found in utils.c */
void			error(char *s);
long long int	timestamp(void);
long			total_time(t_philo *gen);

/* found in initalise.c */
int				init_all(t_rules *gen, int argc, char **argv);
void			init_philo(t_rules *gen);
void			init_mutex(t_rules *gen);
void			loop_rules(t_rules *gen);

#endif
