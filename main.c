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

//static int key_hook(int keycode, t_vars *var)
//{
//	//printf("%d\n", keycode);
//	if (keycode == 53)
//		mlx_destroy_window(var->mlx, var->win);
//	return (0);
//}

static int ft_get_height(char **argv)
{
	char *line;
	int count;
	int fd;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		count++;
		free(line);
	}
	close(fd);
	return (++count);
}

static int ft_get_width(char **argv)
{
	char buf = '\0';
	int count;
	int fd;

	count = 0;
	fd = open(argv[1], O_RDONLY);
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
	char *line;
	char buf = '\0';
//	char str[10000];
	int i;
	int	j;

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
//	read(fd, str, 9999);
//	var->arr = ft_split(str, '\n');

//	while (get_next_line(fd, &line))
//	{
//		var->arr[i] = line;
//		printf("%s\n", var->arr[i]);
//		free(line);
//		i++;
//	}
//	var->arr[i] = line;
//	var->arr[++i] = NULL;
//
//	printf("%s\n", var->arr[--i]);
//	free(line);
//
//	printf("3,1: %c\n", var->arr[3][1]);
//	i = 0;
//	while (i < var->arr_h)
//	{
//		j = 0;
//		while (j < var->arr_w)
//		{
//			printf("j: %d a: %c ", j, var->arr[i][j]);
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			j = 0;
			i++;
			continue ;
		}
		//printf("i: %d j: %d\n", i, j);
		var->arr[i][j] = buf;
		j++;
	}
	var->arr[i][j] = '\0';
	close(fd);
}

//}

static void print_mat(char **arr, int height, t_vars *var)
{
	int i = 0;
	int j = 0;

	while (i < height)
	{
		j = 0;
		while (j < var->arr_w)
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

//static void check_charac(char **arr, int i, int j, int flag)
//{
//	while (arr[i][j])
//	{
//		if (arr[i][j] != '1')
//		{
//			ft_putstr_fd("Error map!\n", 1);
//			exit(1);
//		}
//		if (flag == 1)
//			j++;
//		else
//			i++;
//	}
//}

//static void check_map(char **arr, t_vars *var)
//{
//	int i;
//	int j;
//
//	i = 0;
//	j = 0;
//	check_charac(arr, 0, j, 1);
//	check_charac(arr, i, 0, 0);
//	check_charac(arr, var->arr_h - 1, 0, 0);
//	check_charac(arr, 0, var->arr_w - 1, 1);
//}

static void read_map(char **argv, t_vars *var)
{
	int i;

	i = 0;
	var->arr_h = ft_get_height(argv);
	var->arr_w = ft_get_width(argv);
	var->arr = (char **)malloc(sizeof(char *) * (var->arr_h + 1));
	while (i <= var->arr_h)
		var->arr[i++] = (char *)malloc(sizeof(char) * (var->arr_w + 1));
	fill_matrix(argv, var);
	//print_mat(var->arr, var->arr_h, var);
	var->width = var->arr_w * 100;
	var->height = var->arr_h * 100;
	//check_map(arr, var);
}

int main(int argc, char **argv)
{
	t_vars var;
	int count;
	int size;

	count = 0;
	(void)argv;
	var.mlx = mlx_init();
	if (argc == 2)
	{
		read_map(argv, &var);
		var.img_h = 100;
		var.img_w = 100;
		var.relative_path = "./circle.xpm";
		var.win = mlx_new_window(var.mlx, var.width, var.height, "2D Game!");
		var.img = mlx_xpm_file_to_image(var.mlx, var.relative_path, &size,
										&size);
		mlx_put_image_to_window(var.mlx, var.win, var.img, count, count);
//		while(count < var.width - 100)
//		{
//			count += var.img_w;
//			mlx_put_image_to_window(var.mlx, var.win, var.img, count, 0);
//		}
		//mlx_key_hook(var.win, key_hook, &var);
		mlx_loop(var.mlx);
	}

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
