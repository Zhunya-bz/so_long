#include "so_long.h"

void	picture(t_vars *var)
{
	int	size;

	var->img_h = 64;
	var->img_w = 64;
	var->path_fon = "./fon-64.xpm";
	var->path_cat = "./cat.xpm";
	var->path_sos = "./sausage.xpm";
	var->path_gras = "./grass.xpm";
	var->path_house = "./home.xpm";
	var->win = mlx_new_window(var->mlx, var->width, var->height, "2D Game!");
	var->img_fon = mlx_xpm_file_to_image(var->mlx, var->path_fon, &size, &size);
	var->img_cat = mlx_xpm_file_to_image(var->mlx, var->path_cat, &size, &size);
	var->img_sos = mlx_xpm_file_to_image(var->mlx, var->path_sos, &size, &size);
	var->img_gras = mlx_xpm_file_to_image(var->mlx, var->path_gras, &size,
			&size);
	var->img_house = mlx_xpm_file_to_image(var->mlx, var->path_house, &size,
			&size);
}

void	cycle(int i, int j, t_vars *var)
{
	while (j < var->arr_w)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, j
			* var->img_h, i * var->img_w);
		if (var->arr[i][j] == '1')
			mlx_put_image_to_window(var->mlx, var->win, var->img_gras, j
				* var->img_h, i * var->img_w);
		if (var->arr[i][j] == 'P')
		{
			mlx_put_image_to_window(var->mlx, var->win, var->img_cat, j
				* var->img_h, i * var->img_w);
			var->x = j;
			var->y = i;
		}
		if (var->arr[i][j] == 'E')
			mlx_put_image_to_window(var->mlx, var->win, var->img_house, j
				* var->img_h, i * var->img_w);
		if (var->arr[i][j] == 'C')
			mlx_put_image_to_window(var->mlx, var->win, var->img_sos, j
				* var->img_h, i * var->img_w);
		j++;
	}
}

static void	free_func(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	arr = NULL;
}

int	close_win(t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free_func(var->arr, var->arr_h - 1);
	exit(0);
	return (0);
}
