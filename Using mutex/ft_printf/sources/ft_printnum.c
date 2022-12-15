/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:55:54 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 14:58:12 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printnum(int num)
{
	int	counter;

	counter = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (num < 0)
	{
		num = -1 * num;
		counter += ft_printchar('-');
		counter += ft_printnum(num);
	}
	else if (num >= 0 && num <= 9)
		counter += ft_printchar(num + '0');
	else
	{
		counter += ft_printnum (num / 10);
		counter += (ft_printchar((num % 10) + '0'));
	}
	return (counter);
}
