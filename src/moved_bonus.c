#include "../include/so_long.h"

static void	go_up(t_vars *var)
{
	if ((var->arr[var->y - 1][var->x] == 'E' && var->coll == var->c) ||
		(var->arr[var->y - 1][var->x] == 'A'))
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, (var->y + 1) * var->img_w);
		clear_move(var);
		ft_putstr_fd("Game over!\n", 1), close_win(var);
	}
	if (var->y > 1 && var->arr[var->y - 1][var->x] != '1' && var->arr[var->y
																	  - 1][var->x] != 'E')
	{
		if (var->arr[var->y - 1][var->x] == 'C')
		{
			var->coll++, var->arr[var->y - 1][var->x] = '0';
		}
		var->arr[var->y][var->x] = '0';
		var->y--, var->arr[var->y][var->x] = 'P';
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, (var->y + 1) * var->img_w);
		clear_move(var);
	}
}

static void	go_down(t_vars *var)
{
	if ((var->arr[var->y + 1][var->x] == 'E' && var->coll == var->c) ||
		(var->arr[var->y + 1][var->x] == 'A'))
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, (var->y - 1) * var->img_w);
		clear_move(var);
		ft_putstr_fd("Game over!\n", 1), close_win(var);
	}
	if (var->y + 1 < var->arr_h - 1 && var->arr[var->y + 1][var->x] != '1' &&
		var->arr[var->y + 1][var->x] != 'E')
	{
		if (var->arr[var->y + 1][var->x] == 'C')
		{
			var->coll++, var->arr[var->y + 1][var->x] = '0';
		}
		var->arr[var->y][var->x] = '0';
		var->y++, var->arr[var->y][var->x] = 'P';
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, (var->y - 1) * var->img_w);
		clear_move(var);
	}
}

static void	go_right(t_vars *var)
{
	if ((var->arr[var->y][var->x + 1] == 'E' && var->coll == var->c) ||
		(var->arr[var->y][var->x + 1] == 'A'))
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x - 1)
																  * var->img_h, var->y * var->img_w);
		clear_move(var);
		ft_putstr_fd("Game over!\n", 1), close_win(var);
	}
	if (var->x < var->arr_w - 2 && var->arr[var->y][var->x + 1] != '1' &&
		var->arr[var->y][var->x + 1] != 'E')
	{
		if (var->arr[var->y][var->x + 1] == 'C')
		{
			var->coll++, var->arr[var->y][var->x + 1] = '0';
		}
		var->arr[var->y][var->x] = '0';
		var->x++, var->arr[var->y][var->x] = 'P';
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x - 1)
																  * var->img_h, var->y * var->img_w);
		clear_move(var);
	}
}

static void	go_left(t_vars *var)
{
	if ((var->arr[var->y][var->x - 1] == 'E' && var->coll == var->c) ||
		(var->arr[var->y][var->x - 1] == 'A'))
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x + 1)
																  * var->img_h, var->y * var->img_w);
		clear_move(var);
		ft_putstr_fd("Game over!\n", 1), close_win(var);
	}
	if (var->x > 1 && var->arr[var->y][var->x - 1] != '1' &&
		var->arr[var->y][var->x - 1] != 'E')
	{
		if (var->arr[var->y][var->x - 1] == 'C')
		{
			var->coll++, var->arr[var->y][var->x - 1] = '0';
		}
		var->arr[var->y][var->x] = '0';
		var->x--, var->arr[var->y][var->x] = 'P';
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat, var->x
																  * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x + 1)
																  * var->img_h, var->y * var->img_w);
		clear_move(var);
	}
}

int	key_hook(int keycode, t_vars *var)
{
	if (keycode == 53)
	{
		ft_putstr_fd("You're exit!\n", 1);
		close_win(var);
		exit(0);
	}
	if (keycode == 1)
		go_down(var);
	if (keycode == 13)
		go_up(var);
	if (keycode == 2)
		go_right(var);
	if (keycode == 0)
		go_left(var);
	return (0);
}
