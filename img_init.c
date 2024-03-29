/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:15:56 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 10:13:58 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_j(t_fractol *params)
{
	params->mlx = mlx_init ();
	params->width = 800;
	params->height = 800;
	params->fractol = 'J';
	params->x_ab = 3.0;
	params->y_ab = 3.0;
	params->x_c = 0;
	params->y_c = 0;
	params->zoom_x = params->x_ab / params->width;
	params->zoom_y = params->y_ab / params->height;
	params->j_a = 0.0;
	params->j_b = 0.0;
	params->j = 0;
	params->win = mlx_new_window (params->mlx, params->width,
			params->height, "Julia");
	if (!params->win)
		return (0);
	return (1);
}

int	init_m(t_fractol *params)
{
	params->mlx = mlx_init ();
	params->width = 750;
	params->height = 500;
	params->x_ab = 3.0;
	params->y_ab = 2.0;
	params->x_c = -0.5;
	params->y_c = 0;
	params->zoom_x = params->x_ab / params->width;
	params->zoom_y = params->y_ab / params->height;
	params->fractol = 'M';
	params->win = mlx_new_window (params->mlx, params->width,
			params->height, "Mandelbrot");
	if (!params->win)
		return (0);
	return (1);
}

int	img_init(t_fractol *params)
{
	params->img = mlx_new_image (params->mlx, params->width, params->height);
	if (!params->img)
		return (0);
	params->addr = mlx_get_data_addr (params->img, &params->bits_per_pixel,
			&params->line_length, &params->endian);
	if (!params->addr)
		return (0);
	return (1);
}

int	params_init(char c, t_fractol *params)
{
	int	i;

	if (c == 'J')
		i = init_j (params);
	else if (c == 'M')
		i = init_m (params);
	else
		return (0);
	if (!i)
		return (i);
	return (i);
}
