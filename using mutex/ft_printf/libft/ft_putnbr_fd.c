/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:00:18 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 12:02:29 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd ('-', fd);
		ft_putchar_fd ('2', fd);
		ft_putnbr_fd (147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		ft_putnbr_fd (-n, fd);
	}
	else if (n < 10)
		ft_putchar_fd (n + '0', fd);
	else
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
}
/*
int	main(void)
{
	int	s;

	s = 3556;
	ft_putnbr_fd(s, 1);
	return (0);
}
*/
