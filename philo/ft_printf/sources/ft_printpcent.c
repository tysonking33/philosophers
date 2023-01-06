/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:15:00 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 14:42:08 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>*/

#include "../includes/ft_printf.h"

int	ft_printpcent(void)
{
	write(1, "%", 1);
	return (1);
}
/*
int	main(void)
{
	printf("%d", ft_printpcent());
	return (0);
}*/
