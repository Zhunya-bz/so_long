#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	*path_fon;
	char	*path_cat;
	char	*path_sos;
	char	*path_sos2;
	char	*path_sos3;
	char	*path_sos4;
	char	*path_gras;
	char	*path_house;
	char	*path_dog;
	int		width;
	int		height;
	int		img_w;
	int		img_h;
	int		arr_h;
	int		arr_w;
	void	*img_fon;
	void	*img_cat;
	void	*img_sos;
	void	*img_sos2;
	void	*img_sos3;
	void	*img_sos4;
	void	*img_gras;
	void	*img_house;
	void	*img_dog;
	char	**arr;
	int		x;
	int		y;
	int		count;
	int		coll;
	int		c;
	int 	e;
	int 	p;
	char	buf;
	int		flag;
	char	*str;
}				t_vars;

void	read_map(char **argv, t_vars *var);
void	fill_matrix(char **argv, t_vars *var);
int		ft_get_width(char **argv);
int		ft_get_height(char **argv);
void	picture(t_vars *var);
void	cycle(int i, int j, t_vars *var);
int		close_win(t_vars *var);
int		key_hook(int keycode, t_vars *var);
void	print_move(t_vars *var);
void	free_func(char **arr, int j);
void	clear_move(t_vars *var);
int		my_hook(t_vars *var);

#endif
