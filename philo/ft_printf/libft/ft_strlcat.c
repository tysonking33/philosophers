/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:25:20 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:51:31 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include <stdio.h>*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*ptr_to_src;
	size_t	len_dst;
	size_t	len_src;
	size_t	counter;
	size_t	outcome;

	ptr_to_src = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	counter = 0;
	outcome = 0;
	if (len_dst < dstsize)
		outcome = len_dst + len_src;
	else
		outcome = len_src + dstsize;
	while (ptr_to_src[counter] && (len_dst + 1) < dstsize)
	{
		dst[len_dst] = ptr_to_src[counter];
		len_dst++;
		counter++;
	}
	dst[len_dst] = '\0';
	return (outcome);
}
/*
int	main(void)
{
	char	dest[] = "four";
	char	source[] = "hunnid";
	printf("%zu", ft_strlcat(dest, source, 12));
	return (0);
}
*/
