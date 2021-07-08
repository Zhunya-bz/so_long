#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

int main()
{
	t_data	img;
	t_vars var;
	int x;
	int y;
	int color;

	x = 100;
	y = 100;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(var.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	while (y < 900)
	{
		x = 100;
		color = 0x00FF0000;
		while (x < 900)
		{
			my_mlx_pixel_put(&img, x, y, color++);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	//mlx_mouse_hook(var.win, mouse_hook, &var);
	//mlx_mouse_hook(var.win, loop_hook, &var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}
