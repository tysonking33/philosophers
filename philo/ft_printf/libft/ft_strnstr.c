/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:22:57 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:52:36 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_ctr;
	size_t	n_ctr;

	h_ctr = 0;
	n_ctr = 0;
	if ((*needle == '\0') || (needle == NULL))
		return ((char *)haystack);
	while ((haystack[h_ctr] != '\0') && (h_ctr < len))
	{
		n_ctr = 0;
		while ((needle[n_ctr] == haystack[h_ctr + n_ctr])
			&& (h_ctr + n_ctr < len))
		{
			if (needle[n_ctr + 1] == '\0')
			{
				return ((char *)haystack + h_ctr);
			}
			n_ctr++;
		}
		h_ctr++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	haystack[] = "cucumber";
	const char	needle[] = "cudi";
	size_t		length;

	length = 9;
	printf("%p", ft_strnstr(haystack, needle, length));
	return (0);
}
*/
