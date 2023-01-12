/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:09:31 by tytang            #+#    #+#             */
/*   Updated: 2023/01/12 15:11:16 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	display_message(t_philo *gen, int philo_idx, int type)
{
	printf("%ld philosopher %d %s\n", total_time(gen), philo_idx,
		return_message(type));
}

char	*return_message(int type)
{
	if (type == 1)
		return (" is sleeping\n");
	else if (type == 2)
		return (" has taken a fork\n");
	else if (type == 3)
		return (" is eating\n");
	else if (type == 4 || type == 5)
		return (" is thinking\n");
	else
		return (" died\n");
}
