SRCS = main.c get_next_line.c get_next_line_utils.c \
		map.c matrix_arr.c graphic.c moved.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = so_long.h

LIB_DIR = ./libft

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJS} ${HEADER}
			make -C ${LIB_DIR}
			${CC} ${CFLAGS} libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}


all:    ${NAME}

clean:
		${RM} ${OBJS}
		make clean -C ${LIB_DIR}

fclean: clean
		${RM} ${NAME}
		make fclean -C ${LIB_DIR}

re:     fclean all

bonus:  ${OBJS_CHECK} ${HEADER}
		${CC} ${CFLAGS} libft/libft.a ${OBJS_CHECK} -o ${NAME_CHECK}

.PHONY: fclean clean all re