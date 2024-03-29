# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 20:33:25 by jhwang2           #+#    #+#              #
#    Updated: 2023/01/27 11:22:55 by jhwang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CFLAGS	=	-Wall -Werror -Wextra -g3 -fsanitize=address
LDFLAGS	=	-I ./fractol.h -L./mlx/ -lmlx -framework OpenGL -framework AppKit
SRCS	=	draw.c fractol.c img_init.c libft.c mlx_hook.c print_img.c set.c
OBJS	=	$(SRCS:.c=.o)
BONUS_SRCS	=	draw_bonus.c fractol_bonus.c img_init_bonus.c libft.c mlx_hook_bonus.c \
				print_img_bonus.c set_bonus.c
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)
CC		=	CC
RM		=	rm -f
MLX_DIR	=	./mlx/

ifdef WITH_BONUS
	OBJECTS = $(BONUS_OBJS)
else
	OBJECTS = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
clean:
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus :
	@make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re