/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:39:11 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 12:00:26 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/
#include "libft.h"

int	ft_mstrlen(long long_n)
{
	int	ctr;

	ctr = 0;
	if (long_n < 0)
	{
		long_n = long_n * -1;
		ctr++;
	}
	while (long_n > 0)
	{
		long_n = long_n / 10;
		ctr++;
	}
	return (ctr);
}

char	*ft_itoa(int n)
{
	long	long_n;
	int		length_long_n;
	char	*dest;

	long_n = n;
	length_long_n = ft_mstrlen(long_n);
	dest = (char *)malloc((sizeof (char)) *(length_long_n) + 1);
	if (dest == NULL)
		return (NULL);
	dest[length_long_n--] = '\0';
	if (long_n == 0)
		dest[0] = 48;
		dest[1] = '\0';
	if (long_n < 0)
	{
		dest[0] = '-';
		long_n = long_n * -1;
	}
	while (long_n > 0)
	{
		dest[length_long_n] = 48 + (long_n % 10);
		long_n = long_n / 10;
		length_long_n--;
	}
	return (dest);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(0));
	return (0);
}
*/
