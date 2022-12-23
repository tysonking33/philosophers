/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:39:53 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:49:38 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		*(p++) = (unsigned char)c;
		len--;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[] = "TheDuolingoOwlIsHoldingHostages";
	int		sub_char = '$';
	size_t	nbr_of_char = 7;

	printf("%s", ft_memset(str, sub_char, nbr_of_char));
	return (0);
}
*/
