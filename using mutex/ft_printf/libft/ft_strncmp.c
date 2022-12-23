/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:48:47 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:52:04 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ctr;

	ctr = 0;
	while ((ctr < n) && (s1[ctr] || s2[ctr]))
	{
		if (s1[ctr] != s2[ctr])
			return (((unsigned char *)s1)[ctr] - ((unsigned char *)s2)[ctr]);
		ctr++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d == 0\n", ft_strncmp("t", "", 0));
	printf("%d == 0\n", ft_strncmp("1234", "1235 ", 3));
	printf("%d == 0\n", ft_strncmp("", "1", 0));
	printf("%d == 0\n", ft_strncmp("1", "", 0));
	printf("%d > 0\n", ft_strncmp("Tripouille", "TripouilleX", 42));
	return (0);
}
*/
