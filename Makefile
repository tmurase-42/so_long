# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 13:46:33 by tmurase           #+#    #+#              #
#    Updated: 2021/10/05 11:34:56 by tmurase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


UNAME    := $(shell uname)
NAME 			= so_long
SDIR			= srcs/
FILES			= main.c \
							utils/error.c utils/init.c utils/get_next_line.c
SRCS		= $(addprefix $(SDIR), $(FILES))
OBJS		= $(SRCS:.c=.o)
CC				= gcc
INCLUDES	= -I./includes
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDES)
RM				= rm -f
ifeq ($(UNAME), Linux)
MLXFLAGS	= -lXext -lX11
else
MLXFLAGS	= libmlx.dylib -framework OpenGL -framework AppKit
endif

ifeq ($(UNAME), Linux)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
	cp ./minilibx-linux/libmlx_Linux.a .
	$(CC) $(OBJS) $(CFLAGS) -L. -L.minilibx-linux -lmlx_Linux $(MLXFLAGS) -lm ./libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./minilibx-linux clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./minilibx-linux clean
	$(RM) $(NAME) libmlx_Linux.a .minilibx-linux/libmlx_Linux.a

re: fclean all
else

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	cp ./mlx/libmlx.dylib libmlx.dylib
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -lm ./libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./mlx clean
	${RM} ${NAME} libmlx.dylib ./mlx/libmlx.dylib

re: fclean all

endif

.PHONY: all fclean clean re

# 以下、テスト用のコマンド
test:
	$(CC) -Wall -Wextra -Werror $(SRCS)
	./a.out test.cub
d:
	$(CC) -Wall -Wextra -Werror $(SRCS) -g
	lldb a.out test.cub
gdb:
	$(CC) -Wall -Wextra -Werror $(SRCS) -g3
	gdb a.out test.cub
m:
	$(CC) -Wall -Wextra -Werror $(SRCS) -g -fsanitize=address
	./a.out test.cub
v:
	$(CC) -Wall -Wextra -Werror $(SRCS) -g
	valgrind ./a.out test.cub
