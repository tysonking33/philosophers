/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:36:05 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:49:12 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_isascii(int c)
{
	int	outcome;

	outcome = 0;
	if (c >= 0 && c <= 127)
	{
		outcome = 1;
	}
	else
	{
		return (0);
	}
	return (outcome);
}
/*
int	main(void)
{
	
	printf("%d", ft_isascii('f'));
	return (0);
}
*/
