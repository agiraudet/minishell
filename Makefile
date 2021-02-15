# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 15:43:27 by agiraude          #+#    #+#              #
#    Updated: 2021/02/15 18:43:31 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME			=	minishell

INC_DIR			=	-I includes/ -I libft/includes/

LIBFT_DIR		=	libft/

LIBFT_FILE		=	libft.a

LIBFT			=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

DEP				=	-L $(LIBFT_DIR) -lft

SRCS_FILE		=	main.c \
					parse.c \
					debug.c \
					builtins/cat.c \
					builtins/builtin.c \
					builtins/pwd.c \
					builtins/exit.c \
					builtins/env.c

SRCS_DIR		=	srcs/

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILE))

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -g -Wextra $(INC_DIR)

CC				=	gcc

%.o:			%.s
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) $(DEP) -o $(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR)

all:			$(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				make -C $(LIBFT_DIR) fclean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean flcean re
