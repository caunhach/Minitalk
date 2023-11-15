# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caunhach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 15:52:42 by caunhach          #+#    #+#              #
#    Updated: 2023/07/16 15:52:45 by caunhach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAMEB_C = client_bonus
NAME_S = server
NAMEB_S = server_bonus
SRC_C = src/client.c
SRCB_C = src/client_bonus.c
SRC_S = src/server.c
SRCB_S = src/server_bonus.c
OBJ_C = $(SRC_C:.c=.o)
OBJB_C = $(SRCB_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJB_S = $(SRCB_S:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT = lib/libft/libft.a
INCLUDE = -I include

all : $(NAME_C) $(NAME_S)	

$(NAME_C) : $(OBJ_C)
	@make -C lib/libft/ all
	$(CC) $(FLAGS) $(OBJ_C) $(INCLUDE) $(LIBFT) -o $(NAME_C)

$(NAME_S) : $(OBJ_S)
	@make -C lib/libft/ all
	$(CC) $(FLAGS) $(OBJ_S) $(INCLUDE) $(LIBFT) -o $(NAME_S)

bonus : $(NAMEB_C) $(NAMEB_S)	

$(NAMEB_C) : $(OBJB_C)
	@make -C lib/libft/ all
	$(CC) $(FLAGS) $(OBJB_C) $(INCLUDE) $(LIBFT) -o $(NAMEB_C)

$(NAMEB_S) : $(OBJB_S)
	@make -C lib/libft/ all
	$(CC) $(FLAGS) $(OBJB_S) $(INCLUDE) $(LIBFT) -o $(NAMEB_S)

clean :
	@make -C lib/libft/ clean
	rm -f $(OBJ_C) $(OBJ_S) $(OBJB_C) $(OBJB_S)

fclean : clean
	@make -C lib/libft/ fclean
	rm -f $(NAME_C) $(NAME_S) $(NAMEB_C) $(NAMEB_S)

re : fclean all

.PHONY: all clean fclean re bonus

