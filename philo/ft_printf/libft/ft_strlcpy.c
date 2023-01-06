/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:43:55 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:51:20 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (dstsize < 1)
		return (i);
	while ((src[counter]) && (counter < (dstsize - 1)))
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (i);
}
/*
int	main(void)
{
	char src[] = "coucou";
	char dest[10];
	memset(dest, 'A', 10);
	printf("1. %zu \n\n", ft_strlcpy(dest, src, 0));
	printf("2. %zu \n\n", ft_strlcpy(dest, src, 1));
	printf("3. %zu \n\n", ft_strlcpy(dest, src, 2));
	printf("9. %zu \n\n", ft_strlcpy(dest, "1", 0));
	return (0);
}
*/
