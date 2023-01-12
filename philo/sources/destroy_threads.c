/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:07:13 by tytang            #+#    #+#             */
/*   Updated: 2023/01/12 15:09:09 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	destroy_threads(t_rules *gen)
{
	int	i;

	i = 0;
	while (i < gen->phil_num)
	{
		pthread_mutex_destroy(&gen->fork_arr[i]);
		i++;
	}
	pthread_mutex_destroy(&gen->critical_region_mutex);
	pthread_mutex_destroy(&gen->output_mutex);
	return (1);
}
