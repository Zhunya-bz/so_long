#include "../include/so_long.h"

void	print_move(t_vars *var)
{
	var->count++;
	ft_putstr_fd("move: ", 1);
	ft_putnbr_fd(var->count, 1);
	ft_putstr_fd("\n", 1);
}

void	clear_move(t_vars *var)
{
	print_move(var);
	mlx_string_put(var->mlx, var->win, var->width / 2, var->height + 1,
		   0x00ceffbc, var->str);
	free(var->str);
	var->str = ft_itoa(var->count);
	mlx_string_put(var->mlx, var->win, var->width / 2, var->height + 1,
		   0x00310043, var->str);
}

int	close_win(t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free_func(var->arr, var->arr_h - 1);
	exit(0);
	return (0);
}

int	my_hook(t_vars *var)
{
	int	i;
	int	j;

	i = 0;
	var->flag++;
	while (i < var->arr_h)
	{
		j = 0;
		cycle(i, j, var);
		i++;
	}
	usleep(100000);
	return (0);
}
