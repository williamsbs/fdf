# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 15:46:28 by wsabates          #+#    #+#              #
#    Updated: 2017/12/14 23:37:49 by wsabates         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf

SRC_NAME = main.c parse.c draw.c init_struct.c map.c  mlx_pixel_put_to_image.c \
			init_struct2.c affichage.c

SRC_PATH = src

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

INC = libft/libft.a

CCFLAG = gcc -Wall -Werror -Wextra

LIB_FLAG = libft/libft.a minilibx_macos/libmlx.a

FLAGMLX = -framework OpenGL -framework Appkit

INCLUDE	= fdf.h \
		  libft/libft.h

all : $(NAME)

$(NAME): $(SRC)
		@echo MAKE fdf:"SUCESS"
	 	@(cd libft; make re; make clean; cd ..)
		@(cd minilibx_macos; make re; cd ..)
		@$(CCFLAG) $(LIB_FLAG) -o $@ $^ $(FLAGMLX)

./&.o: %.c
	@$(CCFLAG) -c $< -o $@

clean:
	@echo CLEAN:"SUCCESS"
		@(cd minilibx_macos; make clean; cd ..)

fclean: clean
	@echo FCLEAN:"SUCCESS"
	@(cd libft; make fclean; cd ..; rm -fv $(NAME))

re : fclean all

.PHONY: clean fclean re all
