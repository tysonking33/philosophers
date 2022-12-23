/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:24:30 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 12:00:57 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	counter = 0;
	if (!s || !f)
		return ;
	while (s[counter] != '\0')
	{
		f(counter, s + counter);
		counter++;
	}
}
/*
char	f(unsigned int c, char car)
{
	printf("poopy index %d, poopy char %c\n", c, car);
	return (c - 32);
}

int	main(void)
{
	char	str[] = "peepee uwu";
	ft_striteri(str, f);
	//printf("%s", result);
	return (0);
}*/
