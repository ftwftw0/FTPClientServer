#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:32:10 by flagoutt          #+#    #+#              #
#    Updated: 2015/05/22 15:05:54 by flagoutt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c \
			ft_putstr.c \
			ft_triputstr.c \
			ft_strlen.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strdup.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_abs.c \
			ft_isalpha.c \
			ft_doublelen.c \
			ft_isdigit.c \
			ft_isnumber.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_atoi.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrijoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_spacestrsplit.c \
			ft_itoa.c \
			ft_isspace.c \
			ft_count_words.c \
			ft_swap.c \
			ft_dtoa.c \
			ft_intlen.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd.c \
			ft_lstmap.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstdel.c \
			get_next_line.c \
			ft_strlower.c \
			ft_strupper.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strndup.c \
			ft_hidenp.c \
			ft_freetab.c
SRCO = $(SRC:.c=.o)
INCLUDE = ./
NAME = libft.a

all: $(NAME)

$(NAME):
	@echo "####     Compile tout les fichiers en .o      ####"
	@gcc -c $(SRC) -I$(INCLUDE)
	@echo "####         Cree la library libft.a         ####"
	@ar rc $(NAME) $(SRCO)
	@echo "####         Cree un index de libft.a        ####"
	@ranlib $(NAME)

run:
	@echo "#####     Compile le main, cree un exe      #####"
	gcc main.c -L. -lft -Iincludes -o exe

clean:
	@echo "####      	Supprime tout les .o 	        ####"
	@rm -f $(SRCO)

fclean: clean
	@echo "####      	Supprime tout la libft.a 	        ####"
	@rm -f libft.a

re:	fclean all
