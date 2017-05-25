# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhervy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/19 16:17:56 by dhervy            #+#    #+#              #
#    Updated: 2016/10/21 21:45:23 by dhervy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang
CFLAG = -Wall -Werror -Wextra

CPATH = src/
CFILES = \
	fractol.c mandelbrot.c julia.c hook.c hook2.c  more.c menu.c

OPATH = obj/
OFILES = $(CFILES:.c=.o)
OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling \"$(NAME)\"..."
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -o$(NAME) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework appkit
	@echo "Successful compilation!\n---"

$(OPATH)%.o: $(CPATH)%.c
	@mkdir -p $(OPATH)
	$(CC) $(CFLAGS) -I inc -c -o $@ $<

clean:
	@echo "Deleting the directory /obj..."
	make -C libft clean
	@rm -f $(OBJ)
	@echo "Deletion complete !"

fclean: clean
	@echo "Deleting binary "$(NAME)"..."
	make -C libft fclean
	@rm -f $(NAME)
	@echo "Deletion complete !"/

re: fclean all
