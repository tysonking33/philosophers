/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:03:10 by tytang            #+#    #+#             */
/*   Updated: 2022/12/07 18:03:52 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdlib.h>

int	ft_word_count(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

void	*memalloc(char const*s, char c)
{
	void	*lst;

	if (!s)
		return (NULL);
	lst = malloc((ft_word_count(s, c) + 3) * sizeof(char *));
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		word_len;
	int		i;

	lst = memalloc(s, c);
	if (!lst)
		return (0);
	i = 1;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
