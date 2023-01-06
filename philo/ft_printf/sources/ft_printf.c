/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:16:48 by tytang            #+#    #+#             */
/*   Updated: 2022/12/07 13:01:06 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list *args, const char format, int *i)
{
	if (format == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_printptr(va_arg(*args, unsigned long long)));
	else if ((format == 'd') || (format == 'i'))
		return (ft_printnum(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_print_unsigned_dex(va_arg(*args, unsigned int)));
	else if ((format == 'x') || (format == 'X'))
		return (ft_printhex(va_arg(*args, unsigned int), format));
	else if (format == '%')
		return (ft_printchar('%'));
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *src, ...)
{
	int			src_ctr;
	va_list		args;
	int			output_len;

	src_ctr = 0;
	output_len = 0;
	va_start(args, src);
	while (src[src_ctr] != '\0')
	{
		if (src[src_ctr] == '%')
		{
			src_ctr++;
			output_len += ft_format(&args, src[src_ctr], &src_ctr);
			src_ctr++;
		}
		else
		{
			output_len += ft_printchar(src[src_ctr]);
			src_ctr++;
		}
	}
	va_end(args);
	return (output_len);
}
