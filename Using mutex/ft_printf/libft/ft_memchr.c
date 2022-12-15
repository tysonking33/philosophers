/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:20 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:52:11 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include <stdio.h>*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*ptr_to_s;
	unsigned char	char_of_c;

	char_of_c = (unsigned char)c;
	ptr_to_s = (unsigned char *)s;
	counter = 0;
	while ((ptr_to_s != (void *)0) && (counter < n))
	{
		if (*ptr_to_s == char_of_c)
		{
			return (ptr_to_s);
		}
		ptr_to_s++;
		counter++;
	}
	return (0);
}
/*
int main(void)
{
	const   char    source[] = "zumun";
	puts(ft_memchr(source, 'u', 4));
	return (0);
}
*/
