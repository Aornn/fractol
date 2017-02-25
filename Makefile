# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:45:24 by rqueverd          #+#    #+#              #
#    Updated: 2017/02/24 13:58:12 by rqueverd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
HEADER = fract.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
FLAGSFDF = -lmlx -framework OpenGL -framework AppKit
OBJECTS = main.o ft_event.o draw.o julia.o mandelbrot.o tricorn.c
SRCS = main.c ft_event.c draw.c julia.c mandelbrot.c tricorn.c

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/
	@echo "\033[32;40mCompilation des sources de Fract'ol..."
	@$(CC) $(CFLAGS)  -I libft/ -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJECTS) -lm -L libft/ -lft $(FLAGSFDF)
	@echo "Termine !"
clean:
	@echo "\033[32;40mSuppresion des objets du Fract'ol."
	@make -C libft/ clean
	@rm -rf $(OBJECTS)
	@echo "Termine ! Fract'ol"
fclean: clean
	@echo "Nettoyage complet Fract'ol"
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Termine ! Fract'ol"
re: fclean all
.PHONY: clean fclean re all