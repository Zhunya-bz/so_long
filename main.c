#include "mlx/mlx.h"
#include "so_long.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

//static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}


/*
 * button = 1 - left
 * button = 2 - right
 * button = 3 - circle
 * x, y - position relative window
 */
//static int mouse_hook(int button, int x, int y, void *param)
//{
//	(void)param;
//	(void)button;
//	//(void)y;
//	printf("%d %d\n", x, y);
//	return (0);
//static int my_loop(t_vars *var)
//{
//	t_data	img;
//
//	img.img = mlx_new_image(var->mlx, 1000, 1000);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
//								  &img.line_length,
//								 &img.endian);
//	var->x = 0;
//	var->y = 0;
//	var->color--;
//	while (var->y < 1000)
//	{
//		var->x = 0;
//		while (var->x < 1000)
//		{
//			my_mlx_pixel_put(&img, var->x, var->y, var->color);
//			var->x++;
//		}
//		var->y++;
//	}
//	mlx_put_image_to_window(var->mlx, var->win, img.img, 0, 0);
//	usleep(1000);
//	return (0);
//{

static void free_func(char **arr, int j)
{
	while (j >= 0)
	{
		//printf("%d\n", j);
		free(arr[j]);
		j--;
	}
	free(arr);
	arr = NULL;
}

static int	close_win(int keycode, t_vars *var)
{
	(void)keycode;
	mlx_destroy_window(var->mlx, var->win);
	free_func(var->arr, var->arr_h - 1);
	return (0);
}

static void print_move(t_vars *var)
{
	var->count++;
	ft_putstr_fd("move: ", 1);
	ft_putnbr_fd(var->count, 1);
	ft_putstr_fd("\n", 1);
}

static void go_up(int keycode, t_vars *var)
{
	if (var->arr[var->y - 1][var->x] == 'E' && var->coll == var->c)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
								var->img_h,(var->y + 1) * var->img_w);
		close_win(keycode, var);
		print_move(var);
		exit(0);
	}
	if (var->y > 1 && var->arr[var->y - 1][var->x] != '1' && var->arr[var->y
	- 1][var->x] != 'E')
	{
		if (var->arr[var->y - 1][var->x] == 'C')
		{
			var->coll++;
			var->arr[var->y - 1][var->x] = '0';
		}
		var->y--;
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
			var->img_h,var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat,
								var->x * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
																  var->img_h,(var->y + 1) * var->img_w);
		//закрашиваем котика с прошлого места
		print_move(var);
	}
}

static void go_down(int keycode, t_vars *var)
{
	if (var->arr[var->y + 1][var->x] == 'E' && var->coll == var->c)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
								var->img_h,(var->y - 1) * var->img_w);
		close_win(keycode, var);
		print_move(var);
		exit(0);
	}
	if (var->y + 1 < var->arr_h - 1 && var->arr[var->y + 1][var->x] != '1' &&
	var->arr[var->y + 1][var->x] != 'E')
	{
		if (var->arr[var->y + 1][var->x] == 'C')
		{
			var->coll++;
			var->arr[var->y + 1][var->x] = '0';
		}
		var->y++;
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
																  var->img_h,
								var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat,
								var->x * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
				var->img_h,(var->y - 1) * var->img_w);
		//закрашиваем котика с прошлого места
		print_move(var);
	}
}
static void go_right(int keycode, t_vars *var)
{
	if (var->arr[var->y][var->x + 1] == 'E' && var->coll == var->c)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x - 1) *
																  var->img_h,var->y * var->img_w);
		close_win(keycode, var);
		print_move(var);
		exit(0);
	}
	if (var->x < var->arr_w - 2 && var->arr[var->y][var->x + 1] != '1' &&
	var->arr[var->y][var->x + 1] != 'E')
	{
		if (var->arr[var->y][var->x + 1] == 'C')
		{
			var->coll++;
			var->arr[var->y][var->x + 1] = '0';
		}
		var->x++;
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
																  var->img_h,
								var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat,
								var->x * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x - 1) *
																  var->img_h,var->y * var->img_w);
		//закрашиваем котика с прошлого места
		print_move(var);
	}
}
static void go_left(int keycode, t_vars *var)
{
	if (var->arr[var->y][var->x - 1] == 'E' && var->coll == var->c)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x + 1) *
																  var->img_h,var->y * var->img_w);
		close_win(keycode, var);
		print_move(var);
		exit(0);
	}
	if (var->x > 1 && var->arr[var->y][var->x - 1] != '1' &&
	var->arr[var->y][var->x - 1] != 'E')
	{
		if (var->arr[var->y][var->x - 1] == 'C')
		{
			var->coll++;
			var->arr[var->y][var->x - 1] = '0';
		}
		var->x--;
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, var->x *
																  var->img_h,
								var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_cat,
								var->x * var->img_h, var->y * var->img_w);
		mlx_put_image_to_window(var->mlx, var->win, var->img_fon, (var->x + 1) *
																  var->img_h,var->y * var->img_w);
		//закрашиваем котика с прошлого места
		print_move(var);
	}
}

static int key_hook(int keycode, t_vars *var)
{
	if (keycode == 53)
	{
		close_win(keycode, var);
		exit(0);
	}
	if (keycode == 1)
		go_down(keycode, var);
	if (keycode == 13)
		go_up(keycode, var);
	if (keycode == 2)
		go_right(keycode, var);
	if (keycode == 0)
		go_left(keycode, var);
	return (0);
}

static int ft_get_height(char **argv)
{
	char *line;
	int count;
	int fd;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		count++;
		free(line);
	}
	if (ft_strncmp(line, "", ft_strlen(line)))
		count++;
	free(line);
	close(fd);
	return (count);
}

static int ft_get_width(char **argv)
{
	char buf = '\0';
	int count;
	int fd;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
		exit(1);
	}
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			break ;
		count++;
	}
	close(fd);
	return (count);
}

static void fill_matrix(char **argv, t_vars *var)
{
	int fd;
	char buf = '\0';
	int i;
	int	j;

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
		exit(1);
	}
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			j = 0;
			i++;
			continue ;
		}
		var->arr[i][j] = buf;
		j++;
	}
	var->arr[i][j] = '\0';
	close(fd);
}

//static void print_mat(char **arr, int height, t_vars *var)
//{
//	int i = 0;
//	int j = 0;
//
//	while (i < height)
//	{
//		j = 0;
//		while (j < var->arr_w)
//		{
//			printf("%c", arr[i][j]);
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
//}

static void check_charac(t_vars *var, int i, int j, int flag)
{
	while (i < var->arr_h && j < var->arr_w)
	{
		if (var->arr[i][j] != '1')
		{
			//printf("i:%d j: %d", i, j);
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

static void errors(int e, int p, int c)
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

static void check_pos(t_vars *var, int i, int j)
{
	int e;
	int p;

	e = 0;
	var->c = 0;
	p = 0;
	while (i < var->arr_h)
	{
		j = 0;
		while (j < var->arr_w)
		{
			if (var->arr[i][j] == 'E')
				e++;
			if (var->arr[i][j] == 'C')
				var->c++;
			if (var->arr[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	errors(e, p, var->c);
}

static void check_map(t_vars *var)
{
	int i;
	int j;

	i = 0;
	j = 0;
	check_charac(var, 0, j, 1);
	check_charac(var, i, 0, 0);
	check_charac(var, var->arr_h - 1, j, 1);
	check_charac(var, i, var->arr_w - 1, 0);
	check_pos(var, i, j);
}

static void read_map(char **argv, t_vars *var)
{
	int i;

	i = 0;
	var->arr_h = ft_get_height(argv);
	var->arr_w = ft_get_width(argv);
	//printf("%d %d", var->arr_h, var->arr_w);
	var->arr = (char **)malloc(sizeof(char *) * (var->arr_h + 1));
	while (i <= var->arr_h)
		var->arr[i++] = (char *)malloc(sizeof(char) * (var->arr_w + 1));
	fill_matrix(argv, var);
	//print_mat(var->arr, var->arr_h, var);
	var->width = var->arr_w * 64;
	var->height = var->arr_h * 64;
	check_map(var);
}

static void picture(t_vars *var)
{
	int size;

	var->img_h = 64;
	var->img_w = 64;
	var->path_fon = "./fon-64.xpm";
	var->path_cat = "./cat.xpm";
	var->path_sos = "./sausage.xpm";
	var->path_gras = "./grass.xpm";
	var->path_house = "./home.xpm";
	var->win = mlx_new_window(var->mlx, var->width, var->height, "2D Game!");
	var->img_fon = mlx_xpm_file_to_image(var->mlx, var->path_fon, &size, &size);
	var->img_cat = mlx_xpm_file_to_image(var->mlx, var->path_cat, &size,&size);
	var->img_sos = mlx_xpm_file_to_image(var->mlx, var->path_sos, &size,&size);
	var->img_gras = mlx_xpm_file_to_image(var->mlx, var->path_gras, &size,&size);
	var->img_house = mlx_xpm_file_to_image(var->mlx, var->path_house, &size,&size);
}

int main(int argc, char **argv)
{
	t_vars var;
	int i;
	int j;

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
			while (j < var.arr_w)
			{
				mlx_put_image_to_window(var.mlx, var.win, var.img_fon, j *
				var.img_h,i * var.img_w);
				if (var.arr[i][j] == '1')
					mlx_put_image_to_window(var.mlx, var.win, var.img_gras,
											j * var.img_h, i * var.img_w);
				if (var.arr[i][j] == 'P')
				{
					mlx_put_image_to_window(var.mlx, var.win, var.img_cat,
											j * var.img_h, i * var.img_w);
					var.x = j;
					var.y = i;
				}
				if (var.arr[i][j] == 'E')
					mlx_put_image_to_window(var.mlx, var.win, var.img_house,
											j * var.img_h, i * var.img_w);
				if (var.arr[i][j] == 'C')
					mlx_put_image_to_window(var.mlx, var.win, var.img_sos,
											j * var.img_h, i * var.img_w);
				j++;
			}
			i++;
		}
		if (!mlx_hook(var.win, 17, 0, close_win, &var))
			exit(0);
		mlx_key_hook(var.win, key_hook, &var);
		mlx_loop(var.mlx);
	}
	else
		ft_putstr_fd("Error\nArgument is invalid\n", 1);

//	var.width = 1024;
//	var.height = 1024;
//	var.relative_path = "./test.xpm";
//	var.y = 0;
//	var.mlx = mlx_init();
//	var.win = mlx_new_window(var.mlx, var.width, var.height, "Hello world!");
//	var.img = mlx_xpm_file_to_image(var.mlx, var.relative_path, &var.width,
//									&var.height);
//
//	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
//	mlx_key_hook(var.win, key_hook, &var);
//	mlx_loop(var.mlx);
	return (0);
}
