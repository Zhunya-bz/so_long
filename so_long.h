#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	*relative_path;
	int		width;
	int		height;
	int 	img_w;
	int 	img_h;
	int 	arr_h;
	int 	arr_w;
	void	*img;
	char	**arr;
	int 	x;
	int 	y;
	int 	color;
}				t_vars;


#endif
