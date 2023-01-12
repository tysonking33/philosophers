/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:45 by tytang            #+#    #+#             */
/*   Updated: 2023/01/12 15:17:16 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	*gen;

	gen = (t_rules *)malloc(sizeof(t_rules *));
	if (!gen)
		return (0);
	if (init_all(gen, argc, argv) != 1)
		return (0);
	if (join_threads(gen) != 1)
		return (0);
	if (destroy_threads(gen) != 1)
		return (0);
	return (0);
}
