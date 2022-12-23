/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:39:51 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 14:42:25 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <stdarg.h*/

#include "../includes/ft_printf.h"

/*
void	ft_printchar_no_return(int c)
{
	write(1, &c, 1);
}*/

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_printhexptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_printhexptr(ptr / 16);
		ft_printhexptr(ptr % 16);
	}
	else if (ptr >= 0 && ptr <= 9)
	{
		ft_printchar_no_return(ptr + '0');
	}
	else if (ptr >= 10 && ptr <= 15)
	{
		ft_printchar_no_return('a' + ptr - 10);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	size_t	length;

	length = 2;
	write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_printhexptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}
/*
int	main(void)
{
	int	c;
	int	*ptr_to_i;

	c = 35;
	ptr_to_i = &c;
	printf("%d \n", ft_printptr(*ptr_to_i));

	printf("%p", ptr_to_i);
	return (0);
}*/
