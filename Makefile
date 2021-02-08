# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 11:43:14 by agiraude          #+#    #+#              #
#    Updated: 2021/02/08 12:27:15 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

LIBFT_A		=	libft.a

LIBFT_DIR	=	libft/

LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_A))

INC			=	-I includes/ -I libft/includes

SRCS_FILE	=	main.c \
				cmd.c

SRCS_DIR	=	srcs/

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILE))

OBJS		=	$(SRCS:.c=.o)

CC			=	clang

CFLAGS		=	-Wall -Wextra 

DEP			=	-lft

%.o:			%.c
				$(CC) $(CLFAGS) $(INC) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -o $(OBJS) -L $(LIBFT_DIR) $(DEP) -o $(NAME)

all:			$(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR)

clean:
				rm -f $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				rm -f $(NAME)
				rm -f $(LIBFT)

re:				fclean all

.PHONY:			all clean fclean re
