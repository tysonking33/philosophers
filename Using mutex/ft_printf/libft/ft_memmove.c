/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:38:28 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:51:05 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			ctr;
	unsigned char	*ptr_to_dst;
	unsigned char	*ptr_to_src;

	ctr = 0;
	ptr_to_dst = (unsigned char *)dst;
	ptr_to_src = (unsigned char *)src;
	if ((ptr_to_dst == 0) && (ptr_to_src == 0))
		return (0);
	if (dst > src)
	{
		ptr_to_src = ptr_to_src + len - 1;
		ptr_to_dst = ptr_to_dst + len - 1;
		while (len--)
		{
			*(ptr_to_dst--) = *(ptr_to_src--);
		}
	}
	while ((dst <= src) && (len-- > 0))
	{
		*(ptr_to_dst++) = *(ptr_to_src++);
	}
	return (dst);
}
/*
int	main(void)
{
	char	dest[100] = "Burger Bing Boot Bettuce";
	char	source[] = "Bruh";
	printf("test 1 %s", ft_memmove(dest, source, 4));
	
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {'1', '2', '3', '4'};
	
	printf("%s \n", ft_memmove(sResult + 1, sResult2, 2));
	printf("%s", sResult + 1);
	return (0);
}
*/
