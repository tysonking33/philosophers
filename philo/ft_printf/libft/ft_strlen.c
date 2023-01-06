/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:00:15 by tytang            #+#    #+#             */
/*   Updated: 2022/06/29 13:01:18 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
/*
int	main(void)
{
	char	str[] = "ionknowboutubutifeel22";
	int	number_of_characters;
	number_of_characters = ft_strlen(str);
	printf("%d", number_of_characters);
	return (0);
}
*/
