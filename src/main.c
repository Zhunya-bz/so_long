#include "../include/so_long.h"

static void	create_map(char **argv, t_vars *var)
{
	int	i;
	int	j;

	i = 0;
	var->mlx = mlx_init();
	var->count = 0;
	var->coll = 0;
	var->flag = -1;
	read_map(argv, var);
	picture(var);
	while (i < var->arr_h)
	{
		j = 0;
		cycle(i, j, var);
		i++;
	}
	j = 0;
	while (j < var->arr_w)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon,
			j * var->img_h, i * var->img_w);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	var;

	if (argc == 2)
	{
		create_map(argv, &var);
		var.str = ft_itoa(var.count);
		mlx_string_put(var.mlx, var.win, var.width / 2, var.height + 1,
			 0x00310043, var.str);
		mlx_key_hook(var.win, key_hook, &var);
		mlx_hook(var.win, 17, 0, close_win, &var);
		mlx_loop_hook(var.mlx, my_hook, &var);
		mlx_loop(var.mlx);
	}
	else
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
	return (0);
}
