# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 12:14:56 by dgarizad          #+#    #+#              #
#    Updated: 2023/02/07 16:30:41 by dgarizad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = pipex.c 

OBJS = $(SRC:.c=.o)
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
  
all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@ #place flags!

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME) #REMEMBER TO PLACE FLAGS

$(LIBFT):
	make -C ./libft
clean :
	rm  -f *.o
fclean: clean
		rm -f $(NAME)
		make fclean -C ./libft
re: fclean all
.PHONY : all clean fclean re 

