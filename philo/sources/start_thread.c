/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:19:21 by tytang            #+#    #+#             */
/*   Updated: 2023/01/12 15:24:06 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	join_threads(t_rules *gen)
{
	int			i;
	pthread_t	tid[1000];

	i = 0;
	while (i < gen->phil_num)
	{
		if (pthread_create(&tid[i], NULL, routine, &(gen->philo_arr[i])))
			return (0);
		i++;
	}
	if (gen->phil_num == 1)
		pthread_mutex_lock(&gen->fork_arr[0]);
	if (!pthread_mutex_lock(&gen->fork_arr[gen->phil_num]))
		return (0);
	alive(gen);
	i = 0;
	while (i < gen->phil_num)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (1);
}

void	*routine(void *gen)
{
	t_philo	*phillu;

	usleep(700);
	phillu = (t_philo *)malloc(sizeof(t_philo *));
	phillu = (t_philo *)gen;
	if (phillu->id % 2 == 0)
		sleeping(phillu, phillu->id, 2);
	else
		pick_up_fork(phillu, phillu->id, 3);
	return ((void *)0);
}

void	alive(t_rules *gen)
{
	int	i;
	int	c;

	i = 0;
	while (i == 0)
	{
		c = 0;
		while (c < gen->phil_num)
		{
			usleep(100);
			if (gen->philo_arr[c].meal_count >= gen->max_meals)
				return ;
			if ((timestamp() - gen->philo_arr[c].last_ate)
				>= gen->mill_sec_to_die)
			{
				display_message(&gen->philo_arr[c], c + 1, 6);
				i = 1;
				exit(0);
			}
			c++;
		}
	}
}
