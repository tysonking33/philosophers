/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:41:32 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 12:01:12 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		write(fd, &s[counter], 1);
		counter++;
	}
}
/*
int	main(void)
{
	char	s[] = "bet";
	ft_putstr_fd(s, 1);
	return (0);
}*/
