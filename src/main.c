#include "../include/so_long.h"

void	print_move(t_vars *var)
{
	var->count++;
	ft_putstr_fd("move: ", 1);
	ft_putnbr_fd(var->count, 1);
	ft_putstr_fd("\n", 1);
}

int my_hook(t_vars *var)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	while (1)
//	{
	i = 0;
	var->flag++;
	ft_putnbr_fd(var->flag, 1);
//			exit(1);
	while (i < var->arr_h)
	{
		j = 0;
		cycle(var->x, var->y, var);
		i++;
	}
	usleep(100000);
//	mlx_key_hook(var->win, key_hook, &var);
//	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	var;
	int		i;
	int 	j;

	i = 0;
	if (argc == 2)
	{
		var.mlx = mlx_init();
		var.count = 0;
		var.coll = 0;
		var.flag = -1;
		read_map(argv, &var);
		picture(&var);
//		while (1)
//		{
			i = 0;
			var.flag++;
			ft_putnbr_fd(var.flag, 1);
//			exit(1);
			while (i < var.arr_h)
			{
				j = 0;
				cycle(i, j, &var);
				i++;
			}
			sleep(1);
//			ft_putnbr_fd(var.flag, 1);
			mlx_key_hook(var.win, key_hook, &var);
//			ft_putnbr_fd(var.flag, 1);
			mlx_hook(var.win, 17, 0, close_win, &var);
//			ft_putnbr_fd(var.flag, 1);
		mlx_loop_hook(var.mlx, my_hook, &var);
			mlx_loop(var.mlx);
//			ft_putnbr_fd(var.flag, 1);
//		}
		//mlx_loop(var.mlx);
	}
	else
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
	return (0);
}
