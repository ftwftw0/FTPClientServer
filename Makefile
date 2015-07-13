#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 17:59:57 by flagoutt          #+#    #+#              #
#    Updated: 2015/07/13 08:29:28 by flagoutt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# **************************************************************************** #
# 		PROGRAM																   #
# **************************************************************************** #

NAME		=	serveur
NAME2		=	client

# **************************************************************************** #
#		SOURCES
# **************************************************************************** #

DIRSRC		=	srcs

SRCS = 	$(DIRSRC)/server.c \
		$(DIRSRC)/launchprograms.c \
		$(DIRSRC)/readsocket.c \
		$(DIRSRC)/copystringtab.c \
		$(DIRSRC)/ft_cd.c \
		$(DIRSRC)/ft_pwd.c \
		$(DIRSRC)/ft_env.c \
		$(DIRSRC)/ft_getenv.c \
		$(DIRSRC)/ft_setenv.c \
		$(DIRSRC)/ft_unsetenv.c \
		$(DIRSRC)/ft_exec.c \
		$(DIRSRC)/ft_deinit.c \
		$(DIRSRC)/builtins.c \
		$(DIRSRC)/ft_put.c \
		$(DIRSRC)/ft_putrecv.c \
		$(DIRSRC)/show.c
SRCS2 = $(DIRSRC)/client.c \
		$(DIRSRC)/copystringtab.c \
		$(DIRSRC)/launchprograms.c \
		$(DIRSRC)/writesocket.c \
		$(DIRSRC)/ft_cd.c \
		$(DIRSRC)/ft_lls.c \
		$(DIRSRC)/ft_pwd.c \
		$(DIRSRC)/ft_env.c \
		$(DIRSRC)/ft_getenv.c \
		$(DIRSRC)/ft_setenv.c \
		$(DIRSRC)/ft_unsetenv.c \
		$(DIRSRC)/ft_deinit.c \
		$(DIRSRC)/ft_exec.c \
		$(DIRSRC)/builtins.c \
		$(DIRSRC)/ft_put.c \
		$(DIRSRC)/ft_putrecv.c \
		$(DIRSRC)/show.c

# **************************************************************************** #
#		DIRECTORIES
# **************************************************************************** #

DIRBIN		=	bin
BIN			=	$(addprefix $(DIRBIN)/, $(SRCS:.c=.o))
BIN2		=	$(addprefix $(DIRBIN)/, $(SRCS2:.c=.o))
DIRLIST		=	srcs
DIRINC		=	./includes/
DIRINC_FT	=	./libft/

# **************************************************************************** #
#		COMPILE
# **************************************************************************** #

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INCS		=	-I$(DIRINC) -I$(DIRINC_FT)
LIBS		=   -Llibft/ -lft

# **************************************************************************** #
#		RULES																   #
# **************************************************************************** #

all: libft $(NAME) $(NAME2)

libft:
	@$(MAKE) -C libft

$(NAME): libft $(DIRBIN) $(BIN)
	@printf " ------------------------------------------------------------ \n"
	@$(CC) $(CFLAG) $(BIN) $(LIBS) -o $(NAME)
	@printf "\n\t\tMAKING PROJECT\t\t\t"
	@printf "\t\e[32m[DONE]\e[0m\n\n"
	@printf " ------------------------------------------------------------ \n"

$(NAME2): libft $(DIRBIN) $(BIN2)
	@printf " ------------------------------------------------------------ \n"
	@$(CC) $(CFLAG) $(BIN2) $(LIBS) -o $(NAME2)
	@printf "\n\t\tMAKING PROJECT\t\t\t"
	@printf "\t\e[32m[DONE]\e[0m\n\n"
	@printf " ------------------------------------------------------------ \n"

$(addprefix $(DIRBIN)/, %.o) : %.c $(DIRINC) $(DIRINC_FT)
	@mkdir -p $(@D)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(CFLAG) $(INCS) -o $@ -c $<
	@printf "\t\e[32m[DONE]\e[0m\n"

$(DIRBIN) :
	@/bin/mkdir $(DIRBIN); \
		for DIR in $(DIRLIST); \
		do \
		/bin/mkdir $(DIRBIN)/$$DIR; \
		done

clean:
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning binaries...\t\t\t\t\t"
	@/bin/rm -rf $(DIRBIN);
	@printf "\e[32m[DONE]\e[0m\n"

fclean: clean
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning project...\t\t\t\t\t"
	@/bin/rm -rf $(NAME);
	@/bin/rm -rf $(NAME2);
	@printf "\e[32m[DONE]\e[0m\n"
	@printf " ------------------------------------------------------------ \n"

re: fclean all

.PHONY: clean fclean re libft
