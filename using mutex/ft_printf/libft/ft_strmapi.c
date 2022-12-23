/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:25:37 by tytang            #+#    #+#             */
/*   Updated: 2022/04/04 12:00:44 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	char	*result_str;

	counter = 0;
	if (!s || !f)
		return (NULL);
	result_str = (char *)malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (result_str == NULL)
		return (NULL);
	while (s[counter] != '\0')
	{
		result_str[counter] = f(counter, s[counter]);
		counter++;
	}
	result_str[counter] = '\0';
	return (result_str);
}

/*char f(unsigned int c, char car)
{
	printf("poopy index %d, poopy char %c\n", c, car);
	return (car - 32);
}

int	main(void)
{
	char	str[] = "ibs is pain";
	char *result = ft_strmapi(str, f);
	printf("%s", result);
	return (0);
}*/
