/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:12:22 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 11:48:47 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_isalpha(int c)
{
	int	outcome;

	outcome = 0;
	if (c == '\0')
	{
		return (0);
	}
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
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
int main(void)
{
	int	result;

	result = ft_isalpha(' ');
	printf("%d", result);
	return (0);
}
*/
