#include "../include/so_long.h"

void	print_move(t_vars *var)
{
	var->count++;
	ft_putstr_fd("move: ", 1);
	ft_putnbr_fd(var->count, 1);
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	t_vars	var;
	int		i;
	int		j;

	i = 0;
	if (argc == 2)
	{
		var.mlx = mlx_init();
		var.count = 0;
		var.coll = 0;
		read_map(argv, &var);
		picture(&var);
		while (i < var.arr_h)
		{
			j = 0;
			cycle(i, j, &var);
			i++;
		}
		mlx_key_hook(var.win, key_hook, &var);
		mlx_hook(var.win, 17, 0, close_win, &var);
		mlx_loop(var.mlx);
	}
	else
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
	return (0);
}
