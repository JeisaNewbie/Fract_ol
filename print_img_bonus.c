/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:16:08 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 10:44:21 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_fractol *params, int x, int y, int color)
{
	char	*dst;

	dst = params->addr + (y * params->line_length + x
			* (params->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	creat_trgb(double trgb, int i)
{
	unsigned int	tmp;
	unsigned int	r;

	tmp = (unsigned int)(trgb * 1000000);
	r = tmp / 1000000;
	if (r < 4)
		return (0X00000011);
	else if (i <= 1)
		return (0X00000022);
	else if (i <= 2)
		return (0X00000033);
	else if (i <= 3)
		return (0X00000044);
	else if (i <= 4)
		return (0X00000066);
	else if (i <= 5)
		return (0X00000077);
	else if (i <= 20)
		return (0X00000099);
	else if (i <= 50)
		return (0X003333FF);
	else if (i <= 150)
		return (0X0033CCFF);
	else
		return (0X0033FFFF);
}

void	prt_jul(t_fractol *params)
{
	t_complex	c;
	int			i;
	int			j;
	int			color;

	i = 0;
	while (i < params->width)
	{
		j = 0;
		while (j < params->height)
		{
			c.a = (i * params->zoom_x) + (params->x_c - (params->x_ab / 2));
			c.b = (j * params->zoom_y) + (params->y_c - (params->y_ab / 2));
			color = creat_trgb (julia_set (c, params), params->i);
			my_mlx_pixel_put (params, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window (params->mlx, params->win, params->img, 0, 0);
}

void	prt_mand(t_fractol *params)
{
	t_complex	c;
	int			i;
	int			j;
	int			color;

	i = 0;
	while (i < params->width)
	{
		j = 0;
		while (j < params->height)
		{
			c.a = (i * params->zoom_x) + (params->x_c - (params->x_ab / 2));
			c.b = (j * params->zoom_y) + (params->y_c - (params->y_ab / 2));
			color = creat_trgb (mandelbrot_set (c, params), params->i);
			my_mlx_pixel_put (params, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window (params->mlx, params->win, params->img, 0, 0);
}

void	prt_burn(t_fractol *params)
{
	t_complex	c;
	int			i;
	int			j;
	int			color;

	i = 0;
	while (i < params->width)
	{
		j = 0;
		while (j < params->height)
		{
			c.a = (i * params->zoom_x) + (params->x_c - (params->x_ab / 2));
			c.b = (j * params->zoom_y) + (params->y_c - (params->y_ab / 2));
			color = creat_trgb (burningship_set (c, params), params->i);
			my_mlx_pixel_put (params, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window (params->mlx, params->win, params->img, 0, 0);
}
