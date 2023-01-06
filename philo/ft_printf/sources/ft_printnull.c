/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:33:38 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 15:04:15 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printnull(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		write(1, &str[counter], 1);
		counter++;
	}
}
