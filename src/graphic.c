#include "../include/so_long.h"

void	picture(t_vars *var)
{
	int	size;

	var->img_h = 64;
	var->img_w = 64;
	var->path_fon = "./img/fon-64.xpm";
	var->path_cat = "./img/cat.xpm";
	var->path_sos = "./img/1.xpm";
	var->path_gras = "./img/grass.xpm";
	var->path_house = "./img/home.xpm";
	var->path_sos2 = "./img/1-2.xpm";
	var->path_sos3 = "./img/1-3.xpm";
	var->path_sos4 = "./img/1-4.xpm";
	var->path_dog = "./img/dog-2.xpm";
	var->win = mlx_new_window(var->mlx, var->width, var->height + 25, "2D "
																  "Game!");
	var->img_fon = mlx_xpm_file_to_image(var->mlx, var->path_fon, &size, &size);
	var->img_cat = mlx_xpm_file_to_image(var->mlx, var->path_cat, &size, &size);
	var->img_sos = mlx_xpm_file_to_image(var->mlx, var->path_sos, &size, &size);
	var->img_sos2 = mlx_xpm_file_to_image(var->mlx, var->path_sos2, &size,
										  &size);
	var->img_sos3 = mlx_xpm_file_to_image(var->mlx, var->path_sos3, &size,
										  &size);
	var->img_sos4 = mlx_xpm_file_to_image(var->mlx, var->path_sos4, &size,
										  &size);
	var->img_gras = mlx_xpm_file_to_image(var->mlx, var->path_gras, &size,
			&size);
	var->img_house = mlx_xpm_file_to_image(var->mlx, var->path_house, &size,
			&size);
	var->img_dog = mlx_xpm_file_to_image(var->mlx, var->path_dog, &size, &size);
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
		{
			if ((var->flag % 4) == 0)
				mlx_put_image_to_window(var->mlx, var->win, var->img_sos, j
																		  *
																		  var->img_h,
										i * var->img_w);
			else if ((var->flag % 4) == 1)
				mlx_put_image_to_window(var->mlx, var->win, var->img_sos2, j
																		   *
																		   var->img_h,
										i * var->img_w);
			else if ((var->flag % 4) == 3)
				mlx_put_image_to_window(var->mlx, var->win, var->img_sos3, j
																		   *
																		   var->img_h,
										i * var->img_w);
			else
				mlx_put_image_to_window(var->mlx, var->win, var->img_sos4, j
																		   *
																		   var->img_h,
										i * var->img_w);
		}
		if (var->arr[i][j] == 'A')
		{
			mlx_put_image_to_window(var->mlx, var->win, var->img_dog, j *
					var->img_h, i * var->img_w);
		}
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
