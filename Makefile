# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 13:46:33 by tmurase           #+#    #+#              #
#    Updated: 2021/10/06 15:35:48 by tmurase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


UNAME    := $(shell uname)
NAME 			= so_long
SDIR			= srcs/
FILES			= main.c \
					leaks.c \
					utils/error.c utils/init.c utils/get_next_line.c utils/tmp.c \
					utils/utils.c utils/map_error.c
SRCS		= $(addprefix $(SDIR), $(FILES))
OBJS		= $(SRCS:.c=.o)
CC				= gcc
INCLUDES	= -I./includes
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDES)
RM				= rm -f
NAME_LEAKS	:= leaks_so_long
SRCS_LEAKS	:= leaks.c

ifdef LEAKS
NAME	:= $(NAME_LEAKS)
endif

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
leaks	:
	$(MAKE) CFLAGS="$(CFLAGS) -D LEAKS=1" SRCS="$(SRCS) $(SRCS_LEAKS)" LEAKS=TRUE
else

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	cp ./mlx/libmlx.dylib libmlx.dylib
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -lm ./libft/libft.a -o $(NAME)
	#$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -lm ./libft/libft.a -o $(NAME) -g -fsanitize=address

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./mlx clean
	${RM} ${NAME} libmlx.dylib ./mlx/libmlx.dylib

re: fclean all

leaks	:
	$(MAKE) CFLAGS="$(CFLAGS) -D LEAKS=1" SRCS="$(SRCS) $(SRCS_LEAKS)" LEAKS=TRUE
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
v:
	$(CC) -Wall -Wextra -Werror $(SRCS) -g
	valgrind ./a.out test.cub
