/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:51:38 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:52:21 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				outcome;
	size_t			counter;
	unsigned char	*ptr_to_s1;
	unsigned char	*ptr_to_s2;

	outcome = 0;
	counter = 0;
	ptr_to_s1 = (unsigned char *)s1;
	ptr_to_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (ptr_to_s1[counter] != ptr_to_s2[counter])
		{
			outcome = (ptr_to_s1[counter] - ptr_to_s2[counter]);
			return (outcome);
		}
		counter++;
	}
	return (0);
}
/*
int	main(void)
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d = NULL\n", ft_memcmp(s, sCpy, 4));
	printf("%d = NULL\n", ft_memcmp(s, s2, 0));
	printf("%d > 0\n", ft_memcmp(s, s2, 1));
	printf("%d < 0\n", ft_memcmp(s2, s, 1));
	printf("%d = NULL\n", ft_memcmp(s, s2, 0));
	printf("%d != 0\n", ft_memcmp(s2, s3, 4));
	return (0);
}
*/
