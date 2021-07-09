#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

//static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

static int key_hook(int keycode, t_vars *var)
{
	(void)var;
	//printf("%d\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(var->mlx, var->win);
	return (0);
}

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
//}

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
//}

int main()
{
	//t_data	img;
	t_vars var;
	//int x;
	//int y;
	//int color;

	//var.x = 100;
	var.width = 1024;
	var.height = 1024;
	var.relative_path = "./test.xpm";
	var.y = 0;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.width, var.height, "Hello world!");
	var.img = mlx_xpm_file_to_image(var.mlx, var.relative_path, &var.width,
									&var.height);

//	img.img = mlx_new_image(var.mlx, var.width, var.height);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								 &img.endian);
//	while (var.y < var.height)
//	{
//		var.x = 0;
//		var.color = 0x0000FF00;
//		while (var.x < var.width)
//		{
//			my_mlx_pixel_put(&img, var.x, var.y, var.color);
//			var.x++;
//		}
//		var.y++;
//	}
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
	//mlx_mouse_hook(var.win, mouse_hook, &var);
	//mlx_mouse_hook(var.win, loop_hook, &var);
	//mlx_loop_hook(var.mlx, my_loop, &var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}
