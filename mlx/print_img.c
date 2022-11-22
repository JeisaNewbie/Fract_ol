void print_img (t_fractol *params)
{
	if (params->fractol == "M")
		prt_mand (params);
	else if (params->fractol == "J")
		prt_jul (params);
	else
		return ;
}

int	creat_trgb (long double trgb)
{
	int	tmp;
	int	r;
	int	g;
	int	b;

	tmp = (int)(trgb * 1000000);
	r = tmp / 1000000;
	tmp = tmp % 1000000;
	g = (tmp / 1000) / 4;
	b = (tmp % 1000) / 4;
	if (r < 4)
		return (0 << 24 | 0 << 16 | 0 << 8 | 0);
	else
		return (0 << 24 | r << 16 | g << 8 | b);
}

void prt_mand (t_ptr *param)
{
	t_complex	c;
	int			i;
	int			j;
	int			color;

	i = 0;
	j = 0;
	c.zoom = 1.0;
	while (i < params->width)
	{
		while (j < params->height)
		{
			c.x = (i - 720) * (1 / 320) * (c.zoom);
			c.y = (j - 360) * (1 / 320) * (c.zoom);
			color = create_trgb (Mandelbrot_set (c));
			my_mlx_pixel_put (img, i, j, color);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window (params->mlx, params->win, params->img.img, 0, 0);
}

void prt_jul (t_ptr *param)
{
	t_complex	c;
	int			i;
	int			j;
	int			color;

	i = 0;
	j = 0;
	c.a;
	c.b;
	c.zoom = 1.0;
	while (i < params->width)
	{
		while (j < params->height)
		{
			c.x = (i - 540) * (1 / 540) * (c.zoom);
			c.y = (j - 540) * (1 / 540) * (c.zoom);
			color = create_trgb (Julia_set (c));
			my_mlx_pixel_put (img, i, j, color);
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window (params->mlx, params->win, params->img.img, 0, 0);
}
