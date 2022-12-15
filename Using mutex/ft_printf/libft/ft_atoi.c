/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:25:04 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:52:42 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	ctr;
	long	outcome;

	sign = 0;
	ctr = 0;
	outcome = 0;
	while ((str[ctr] != '\0') && (str[ctr] == 32 || str[ctr] == '\t'
			|| str[ctr] == '\n' || str[ctr] == '\r' || str[ctr] == '\v'
			|| str[ctr] == '\f'))
		ctr++;
	if ((str[ctr] != '\0') && (str[ctr] == '-'))
	{
		sign = 1;
		ctr++;
	}
	else if (str[ctr] == '+')
		ctr++;
	while ((str[ctr] != '\0') && ((str[ctr] >= '0') && (str[ctr] <= '9')))
	{
		outcome = (outcome * 10) + (str[ctr++] - '0');
	}
	if (sign == 1)
		return (-outcome);
	return (outcome);
}
/*
int	main(void)
{
	printf("3. %d = 0\n", ft_atoi("--1"));
	printf("4. %d = 0\n", ft_atoi("++1"));
	printf("12. %d = 0\n", ft_atoi("-+42"));
	printf("13. %d = 0\n", ft_atoi("+-42"));
	return (0);
}
*/
