# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahouel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 08:37:55 by ahouel            #+#    #+#              #
#    Updated: 2017/05/29 14:17:47 by ahouel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ahouel.filler
VPATH = ./srcs/
HDIR = ./includes
LDIR = ./libft
FCTS = main \
	   filler_init \
	   grab_map \
	   grab_piece \
	   filler \
	   check_point \
	   check_dist
SRCS = $(addsuffix .c, $(FCTS))
SRC = $(addprefix $(VPATH), $(SRCS))
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[34m\033[1mCompilation de la lib...\033[0m"
	@make -C $(LDIR) re
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mCompilation de filler...\033[0m"
	@clang $(CFLAGS) -L$(LDIR) -lft $(OBJ) -o $(NAME)
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mFiller done !\033[0m"

%.o : $(VPATH)%.c
	@echo "\033[34m\033[1mCompilation de $(notdir $<)...\033[0m\r"
	@clang -c $(CFLAGS) -I $(HDIR) -I $(LDIR)/includes $<
	@printf "\033[A\033[K"

./visu : $(NAME)
	@make -C visual/ re

bonus : ./visu

clean :
	@rm -f $(OBJ)
	@make -C $(LDIR) clean
	@make -C visual clean

fclean : clean
	@rm -f $(NAME)
	@make -C $(LDIR) fclean
	@make -C visual fclean

re : fclean all

.PHONY : all bonus clean fclean re
