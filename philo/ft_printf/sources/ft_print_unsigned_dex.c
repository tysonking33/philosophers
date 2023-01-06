/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_dex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:44:46 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 14:40:55 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>*/

#include "../includes/ft_printf.h"

void	ft_printchar_no_return(char c)
{
	write(1, &c, 1);
}

int	ft_print_unsigned_dex(long long int num)
{
	static int				counter;
	long long int			two_pow_thirtytwo;

	counter = 0;
	two_pow_thirtytwo = 4294967296;
	if (num < 0)
		ft_print_unsigned_dex(two_pow_thirtytwo + num);
	else if (num >= 0 && num <= 9)
	{
		counter++;
		ft_printchar(num + '0');
	}
	else
	{
		ft_print_unsigned_dex(num / 10);
		ft_printchar_no_return((num % 10) + '0');
		counter++;
	}
	return (counter);
}
/*
int	main(void)
{
	printf("\n%d\n", ft_print_unsigned_dex(121));
	printf("\n%d\n", ft_print_unsigned_dex(-121));
	printf("\n121:  %u\n", 121);
	printf("\n-121: %u\n", -121);
	return (0);
}*/
