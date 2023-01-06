/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:01:19 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 14:54:17 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>*/

#include "../includes/ft_printf.h"

int	ft_printstr(char *str)
{
	int	str_ctr;

	str_ctr = 0;
	if (str == NULL)
	{
		ft_printnull("(null)");
		return (6);
	}
	while (str[str_ctr] != '\0')
	{
		write(1, &str[str_ctr], 1);
		str_ctr++;
	}
	return (str_ctr);
}
/*
int	main(void)
{
	printf("%lu", strlen("dub"));
	printf("%d", ft_printstr("dub"));
	return (0);
}*/
