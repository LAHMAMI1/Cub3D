# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 14:57:06 by fdiraa            #+#    #+#              #
#    Updated: 2023/08/20 13:35:09 by fdiraa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



.PHONY = all clean fclean re bonus

NAME = libft.a

CC = cc

CFLAGS	= -Wall -Werror -Wextra

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_isnumber.c\
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_long_atoi.c\
		ft_calloc.c ft_strdup.c ft_isspace.c ft_free_split.c ft_swap_strings.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_strcmp_char.c
		
SRCS_BNS = 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstswap.c	
		

OBJS = ${SRCS:%.c=%.o}
OBJS_BNS = ${SRCS_BNS:%.c=%.o}

all : ${NAME}
bonus : ${OBJS_BNS}
	ar rcs ${NAME} $^

${NAME} : ${OBJS}
	ar rcs $@ $^

clean:
#	@echo "Cleaning up..."
	rm -rf $(OBJS)
	rm -rf $(OBJS_BNS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all 
