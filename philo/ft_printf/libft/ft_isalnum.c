/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:51:39 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:49:02 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_isalnum(int c)
{
	int	outcome;

	outcome = 0;
	if (c == '\0')
	{
		return (0);
	}
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
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
	printf("%d", ft_isalnum('s'));

	printf("%d", ft_isalnum('1'));

	printf("%d", ft_isalnum('+'));

	printf("%d", ft_isalnum(' '));

	return (0);
}
*/
