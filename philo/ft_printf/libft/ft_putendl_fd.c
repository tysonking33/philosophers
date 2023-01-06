/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:54:59 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 12:01:27 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	char	s[] = "bock";
	ft_putendl_fd(s, 1);
	return (0);
}*/
