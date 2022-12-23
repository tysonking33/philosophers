/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:27:02 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:50:34 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *)dst)[counter] = ((unsigned char *)src)[counter];
		counter++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	dest[100] = " ";
	char	source[] = "Burger King Foot Lettuce";
	printf("%s", ft_memcpy(dest, source, 4));
	return (0);
}
*/
