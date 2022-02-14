NAME = so_long
HEADER = so_long.h
SRCS = create_map.c create_world.c get_next_line_utils.c get_next_line.c main.c map_checker.c move_ifs.c moves.c render.c utils.c
OBJS = ${SRCS:.c=.o}
MLX = mlx_linux
RM = rm -rf

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS =    -L -lft

$(NAME):	$(OBJS)
			$(CC) -o so_long $(CFLAGS) $(OBJS) minilibx-linux/libmlx_Linux.a -L /usr/include/X11/extensions/ -lXext -lX11 -lm

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	clean all
