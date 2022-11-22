#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

#define X_EVENT_MOUSE_PRESS		4
#define X_EVENT_MOUSE_MOVEMENT	6

typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}	t_data;

typedef struct	s_ptr {
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
	double	zoom;
	void	*img;
}	t_ptr;

typedef struct	s_complex {
	double	a;
	double	b;
}	t_complex;

/*int	check_fract_ol (char *fractol)
{
	int	i;

	i = ft_strlen (fractol);
	if (!ft_strncmp ("Mandelbrot", fractol, i))
		prt_mand ();
	else if (!ft_strncmp ("Julia", fractol, i))
		prt_jul ();
	else
		printf ("Wrong fractol!");
	return (0);
}*/
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

int	key_hook (int keycode, t_ptr *params)
{
	if (keycode == 53)
	{
		mlx_destroy_window (params->mlx_ptr, params->win_ptr);
		exit (0);
	}
	return (0);
}

int mouse_press (int button, int x, int y, t_ptr *params)
{
	if (button == 1)
	{
		printf("MOUSE_LEFT_BUTTON\n");
		printf ("x: %d \n", x);
		printf ("y: %d \n", y);
		params->x = x;
		params->y = y;
	}
	else if (button == 4)
	{
		params->zoom = params->zoom * 2.0;
		printf ("mouse_scroll_up\n");
	}
	else if (button == 5)
	{
		printf ("mouse_scroll_down\n");
		params->zoom = params->zoom * 0.5;
	}
	return (0);
}

double	Mandelbrot_set (t_complex c)
{
	t_complex	z;
	double	tmpx;
	int			i;

	z.a = c.a;
	z.b = c.b;
	i = 0;

	while (i <= 200 && ((z.a * z.a) + (z.b * z.b)) < 4)
	{
		tmpx = (z.a * z.a) - (z.b * z.b);
		z.b = (2 * z.a * z.b) + c.b;
		z.a = tmpx + c.a;
		i++;
	}
	return (((z.a * z.a) + (z.b * z.b)));
}

 double	Julia_set (t_complex c, t_complex C)
{
	t_complex	z;
	double	tmpx;
	int			i;

	z.a = c.a;
	z.b = c.b;
	i = 0;
	while (i <= 200 && ((z.a * z.a) + (z.b * z.b)) < 4)
	{
		tmpx = (z.a * z.a) - (z.b * z.b);
		z.b = (2 * z.a * z.b) + C.b;
		z.a = tmpx + C.a;
		i++;
	}
	return (((z.a * z.a) + (z.b * z.b)));
}
int	creat_trgb (double trgb)
{
	unsigned int	tmp;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	tmp = (unsigned int)(trgb * 1000000);
	r = tmp / 1000000;
	tmp = tmp % 1000000;
	g = (tmp / 1000) / 4;
	b = (tmp % 1000) / 4;
	if (r < 4) 
		return (0 << 24 | 0 << 16 | 0 << 8 | 0);
	else if (r >= 5)
		return (0 << 24 | 255 << 16 | 255 << 8 | 255);
	else
		return (0 << 24 | r << 16 | g << 8 | b);
}
int draw (t_ptr *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img, 0, 0);//params->width, params->height);
	return (0);
}
void prt_mand (t_ptr *params, t_data *img)
{
	t_complex	c;
	int			i;
	int			j;
	int			color;

	i = 0;
	j = 0;
	
	//color = creat_trgb (0, 255, 255, 255);
	while (i < 750)
	{
		while (j < 500)
		{
			c.a = (i - (500 + (500 - params->x))) * params->zoom;
			c.b = (j - (250 + (250 - params->y))) * params->zoom;
			color = creat_trgb (Mandelbrot_set (c));
			my_mlx_pixel_put (img, i, j, color);
			j++;
		}
		i++;
		j = 0;
	}
	params->img = img->img;
}

void prt_jul (t_ptr *params, t_data *img)
{
	t_complex	c;
	t_complex	C;
	int			i;
	int			j;
	int			color;

	i = 0;
	j = 0;
	C.a = 0.2;
	C.b = 0;
	while (i < params->width)
	{
		while (j < params->height)
		{
			c.a = (i - 500) * 0.004;
			c.b = (j - 250) * 0.004;
			color = creat_trgb (Julia_set (c, C));
			my_mlx_pixel_put (img, i, j, color);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window (params->mlx_ptr, params->win_ptr, img->img, 0, 0);
}
int main (int argc, char *argv[])
{
	t_ptr	params;
	t_data	img;
	int		color;

	params.width = 500;
	params.height = 250;
	params.x = 500;
	params.y = 250;
	params.zoom = 0.004;
	params.mlx_ptr = mlx_init ();
	params.win_ptr = mlx_new_window (params.mlx_ptr, 750, 500, "mand");
	img.img = mlx_new_image (params.mlx_ptr, 750, 500);
	img.addr = mlx_get_data_addr (img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	prt_mand (&params, &img);



	//prt_jul (&params, &img);
	//mlx_put_image_to_window (params.mlx_ptr, params.win_ptr, img.img, 0, 0);


	mlx_key_hook (params.win_ptr, key_hook, &params);
	mlx_hook (params.win_ptr, 4, 0, &mouse_press, &params);
	mlx_loop_hook (params.mlx_ptr, &draw, &params);
	mlx_loop (params.mlx_ptr);
}
