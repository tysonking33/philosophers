/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:01:27 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:49:19 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_isprint(int c)
{
	int	outcome;

	outcome = 0;
	if (c >= 32 && c <= 126)
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
	printf("%d", ft_isprint('p'));
	return (0);
}
*/
