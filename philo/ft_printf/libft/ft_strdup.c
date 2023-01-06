/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:54:49 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:52:59 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	int		counter;

	counter = 0;
	mem = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) +1));
	if (!s1 || !mem)
		return (NULL);
	while (s1[counter])
	{
		mem[counter] = s1[counter];
		counter++;
	}
	mem[counter] = '\0';
	return (mem);
}
/*
int	main(void)
{
	const char	s1[] = "pooky";
	printf("%s", ft_strdup(s1));
	return (0);
}
*/
