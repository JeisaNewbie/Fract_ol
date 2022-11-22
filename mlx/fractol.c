void init_J (t_ptr *params)
{
	params->mlx = mlx_init ();
	params->width = BASIC_LENGTH * 3;
	params->height = BASIC_LENGTH * 3;
	params->t_fractol = "Julia";
	params->win = mlx_new_window (params->mlx, params->width, params->height, params->t_fractol);
}

void init_P (t_ptr *params)
{

	params->mlx = mlx_init ();
	params->width = BASIC_LENGTH * 3;
	params->height = BASIC_LENGTH * 2;
	params->t_fractol = "Mandelbrot";
	params->win = mlx_new_window (params->mlx, params->width, params->height, params->t_fractol);
}

void init_N (t_ptr *params);

void img_init (t_ptr *params)
{
	params->img.img = mlx_new_image (params->mlx, params->width,
	params->height, params->t_fractol);
	params->img.addr = mlx_get_data_addr (params->img.img,
	&params->img.bits_per_pixxel, &params->img.line_length, &params->img.endian);
}

void params_init (char c, t_ptr *params)
{
	if (c == "J")
	{
		init_J (params);
	}
	else if (c == "M")
	{
		init_M (params);
	}
	else
		return ;
}
