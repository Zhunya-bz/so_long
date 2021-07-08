SRCS = main.c

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
			${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}
			#make -C ${LIB_DIR}
			#${CC} ${CFLAGS} libft/libft.a ${OBJS} -o ${NAME}

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