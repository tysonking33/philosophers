/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:57:22 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 14:41:36 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>*/

#include "../includes/ft_printf.h"

/*
void	ft_printchar_no_return(int c)
{
	write(1, &c, 1);
}*/

int	hex_length_ctr(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		num = num / 16;
		length++;
	}
	return (length);
}

void	ft_print_hex(unsigned int num, char format)
{
	if (num >= 16)
	{
		ft_print_hex(num / 16, format);
		ft_print_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_printchar_no_return(num + '0');
		else
		{
			if (format == 'x')
				ft_printchar_no_return((num - 10) + 'a');
			else if (format == 'X')
				ft_printchar_no_return((num - 10) + 'A');
		}
	}
}

int	ft_printhex(unsigned int num, char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_print_hex(num, format);
	return (hex_length_ctr(num));
}

/*
int	main(void)
{

}*/
