/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:52:29 by tytang            #+#    #+#             */
/*   Updated: 2022/06/29 13:51:55 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		dest_ctr;
	int		ctr_s1;
	int		ctr_s2;

	dest_ctr = 0;
	ctr_s1 = 0;
	ctr_s2 = 0;
	dest = (char *)malloc((sizeof (char))
			* ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[ctr_s1 + dest_ctr] != '\0')
	{
		dest[dest_ctr] = s1[ctr_s1 + dest_ctr];
		dest_ctr++;
	}
	while (s2[ctr_s2] != '\0')
	{
		dest[dest_ctr] = s2[ctr_s2];
		dest_ctr++;
		ctr_s2++;
	}
	dest[dest_ctr] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	s1[] = "peepee";
	const char	s2[] = "poopoo";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}
*/
