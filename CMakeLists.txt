cmake_minimum_required(VERSION 3.19)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long main.c libft/ft_split.c get_next_line.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_substr.c libft/ft_calloc.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_bzero.c
        mlx/font.c mlx/mlx_png.c mlx/mlx_string_put.c mlx/mlx_xpm.c mlx/man/man3/mlx.3)