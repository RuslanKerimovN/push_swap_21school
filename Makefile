# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: botilia <botilia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 10:40:51 by botilia           #+#    #+#              #
#    Updated: 2022/02/13 10:50:07 by botilia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PS =	command.c \
		find_steps.c \
		ft_split.c \
		score.c \
		sort_int_mass.c \
		tools_2.c \
		chekers.c \
		command_go.c \
		ft_lists.c \
		main.c \
		pushing.c \
		sort_final.c \
		tools.c \

PS_H = push_swap.h \

OBJ = $(patsubst %.c,%.o,$(PS))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(PS_H)
	cc $(FLAGS) $(PS) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus