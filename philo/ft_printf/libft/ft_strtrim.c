/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:20:04 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:54:21 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

static int	ft_isinset(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (ft_isinset(set, s1[count]))
		count++;
	if (count == (int)ft_strlen(s1))
	{
		cp = (char *)malloc(sizeof(char) * 1);
		cp[0] = 0;
		return (cp);
	}
	i = ft_strlen(s1) - 1;
	while (ft_isinset(set, s1[i]))
		i--;
	cp = ft_substr(s1, count, i - count + 1);
	return (cp);
}

/*
int	main(void)
{
	char const	str[] = "cumandandandandcumcum";
	char const	set[] = "cum";
	printf("%s", ft_strtrim(str, set));
	return (0);
}
*/
