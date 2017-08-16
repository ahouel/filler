# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahouel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 08:37:55 by ahouel            #+#    #+#              #
#    Updated: 2017/05/29 14:10:36 by ahouel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = visu
F_PATH = ./srcs/
HDIR = ./includes
LDIR = ../libft/
FCTS = main parser visual drawer \
	   init_grid final_draw free_all \
	   set_players mlx_launcher
SRCS = $(addsuffix .c, $(FCTS))
SRC = $(addprefix $(F_PATH), $(SRCS))
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[34m\033[1mCompilation de la mlx...\033[0m"
	@make -C minilibx_macos/ clean && make -C minilibx_macos
	@printf "\033[A\033[K"
	@printf "\033[A\033[K"
	@printf "\033[A\033[K"
	@printf "\033[A\033[K"
	@printf "\033[A\033[K"
	@printf "\033[A\033[K"
	@printf "\033[A\033[K"
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mCompilation du visualiseur...\033[0m"
	@clang $(CFLAGS) -L$(LDIR) -lft -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)
	@mv $(NAME) ../
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mBonus done !\033[0m"

%.o : $(F_PATH)%.c
	@echo "\033[34m\033[1mCompilation de $(notdir $<)...\033[0m\r"
	@clang $(CFLAGS) -I$(HDIR) -I./minilibx_macos -I$(LDIR)/includes -c $<
	@printf "\033[A\033[K"

clean :
	@rm -f $(OBJ)
	@make -C minilibx_macos/ clean

fclean : clean
	@rm -f ../$(NAME)

re : fclean all

.PHONY: all clean fclean re
