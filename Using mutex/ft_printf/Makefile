# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tytang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 15:40:57 by tytang            #+#    #+#              #
#    Updated: 2022/12/07 12:43:06 by tytang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS_DIR = sources/

FILES = ft_printf \
		ft_printnull \
		ft_printstr \
		ft_printptr \
		ft_printnum \
		ft_print_unsigned_dex \
		ft_printhex \
		ft_printpcent \
		
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS_DIR = sources/

OBJS = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(MAKE) re -C ./libft
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(RM) $(OBJS) $(OBJS_B)
	@$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean


re: clean all

.PHONY: all clean fclean re
