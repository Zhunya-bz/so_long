#include "../include/so_long.h"

static void	check_charac(t_vars *var, int i, int j, int flag)
{
	while (i < var->arr_h && j < var->arr_w)
	{
		if (var->arr[i][j] != '1')
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Map is invalid\n", 1);
			exit(1);
		}
		if (flag == 1)
			j++;
		else
			i++;
	}
}

static void	errors(int e, int p, int c)
{
	if (e != 1 || p != 1 || c < 1)
	{
		ft_putstr_fd("Error\n", 1);
		if (e != 1)
			ft_putstr_fd("Wrong number of characters (E) in map\n", 1);
		if (p != 1)
			ft_putstr_fd("Wrong number of characters (P) in map\n", 1);
		if (c < 1)
			ft_putstr_fd("Wrong number of characters (C) in map\n", 1);
		exit(1);
	}
}

static void	check_pos(t_vars *var, int i, int j)
{
//	int	e;
//	int	p;

	var->e = 0;
	var->c = 0;
	var->p = 0;
	while (i < var->arr_h)
	{
		j = 0;
		while (j < var->arr_w)
		{
			if (var->arr[i][j] == 'E')
				var->e++;
			else if (var->arr[i][j] == 'C')
				var->c++;
			else if (var->arr[i][j] == 'P')
				var->p++;
			else if (var->arr[i][j] != '1' && var->arr[i][j] != '0' &&
				var->arr[i][j] != 'A')
			{
				ft_putstr_fd("Error\nInvalid map!\n", 1);
				exit(1);
			}
			j++;
		}
		i++;
	}
	errors(var->e, var->p, var->c);
}

static void	check_map(t_vars *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_charac(var, 0, j, 1);
	check_charac(var, i, 0, 0);
	check_charac(var, var->arr_h - 1, j, 1);
	check_charac(var, i, var->arr_w - 1, 0);
	check_pos(var, i, j);
}

void	read_map(char **argv, t_vars *var)
{
	int	i;

	i = 0;
	var->arr_h = ft_get_height(argv);
	var->arr_w = ft_get_width(argv);
	var->arr = (char **)malloc(sizeof(char *) * (var->arr_h + 1));
	while (i <= var->arr_h)
		var->arr[i++] = (char *)malloc(sizeof(char) * (var->arr_w + 1));
	fill_matrix(argv, var);
	var->width = var->arr_w * 64;
	var->height = var->arr_h * 64;
	check_map(var);
}
