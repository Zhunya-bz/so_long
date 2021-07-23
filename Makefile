SRCS_NAME = main.c get_next_line.c \
			map.c matrix_arr.c graphic.c moved.c so_long_utils.c

SRCS_BON_NAME = main.c get_next_line.c \
                map_bonus.c matrix_arr.c graphic_bonus.c moved_bonus.c so_long_utils.c

SRCS_DIR = ./src

SRCS = ${addprefix $(SRCS_DIR)/,$(SRCS_NAME)}

SRCS_BONUS = ${addprefix $(SRCS_DIR)/,$(SRCS_BON_NAME)}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER_NAME = so_long.h get_next_line.h

HEADER_DIR = ./include

HEADER = ${addprefix $(HEADER_DIR)/,$(HEADER_NAME)}

LIB_DIR = ./libft

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJS} ${HEADER}
			make -C ${LIB_DIR}
			${CC} ${CFLAGS} libft/libft.a ${MLX} libmlx.dylib ${OBJS} -o ${NAME}


all:    ${NAME}

bonus:	${OBJS_BONUS} ${HEADER}
		make -C ${LIB_DIR}
		${CC} ${CFLAGS} libft/libft.a ${MLX} libmlx.dylib ${OBJS_BONUS} -o ${NAME}

clean:
		${RM} ${OBJS} ${OBJS_BONUS}
		make clean -C ${LIB_DIR}

fclean: clean
		${RM} ${NAME}
		make fclean -C ${LIB_DIR}

re:     fclean all

.PHONY: fclean clean all re bonus