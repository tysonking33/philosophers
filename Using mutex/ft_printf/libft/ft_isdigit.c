/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:30:32 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:48:54 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_isdigit(int c)
{
	int	outcome;

	outcome = 0;
	if (c == '\0')
	{
		return (0);
	}
	if (c >= '0' && c <= '9')
	{
		return (1);
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
	printf("%d", ft_isdigit('2'));
	return  (0);
}
*/
