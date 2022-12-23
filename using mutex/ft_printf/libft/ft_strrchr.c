/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:08:26 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:51:56 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;
	int	outcome;

	counter = 0;
	outcome = -1;
	if (c == '\0')
	{
		while (s[counter])
			counter++;
		return ((char *)(&(s[counter])));
	}
	while (s[counter])
	{
		if (s[counter] == (char)c)
			outcome = counter;
		counter++;
	}
	if (outcome == -1)
		return (NULL);
	return ((char *)(&(s[outcome])));
}
/*
int main(void)
{
	const char	source[] = "tripouille";
	printf("%s", ft_strrchr(source, 't'));
	return (0);
}
*/
