/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:17:02 by tytang            #+#    #+#             */
/*   Updated: 2022/06/30 15:14:23 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

void	ft_printchar_no_return(char c);
int		hex_length_ctr(unsigned int num);
int		ft_ptr_len(uintptr_t num);
int		ft_decimal_len(int c);
void	ft_printnull(char *str);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printstr(char *str);
int		ft_printnum(int num);
int		ft_print_unsigned_dex(long long int num);
void	ft_print_hex(unsigned int num, char format);
int		ft_printhex(unsigned int num, char format);
int		ft_printpcent(void);
int		ft_format(va_list *args, const char format, int *i);
int		ft_printf(const char *src, ...);

#endif
