/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:16:01 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 10:55:04 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setting_all(t_fractol *params)
{
	params->zoom_x = params->x_ab / params->width;
	params->zoom_y = params->y_ab / params->height;
}

int	key_hook(int keycode, t_fractol *params)
{
	if (keycode == 53)
	{
		mlx_destroy_window (params->mlx, params->win);
		exit (0);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractol *params)
{
	if (button == 1)
	{
		params->x_c = x * params->zoom_x + (params->x_c - params->x_ab / 2);
		params->y_c = y * params->zoom_y + (params->y_c - params->y_ab / 2);
	}
	else if (button == 4)
	{
		params->x_ab = params->x_ab / 1.2;
		params->y_ab = params->y_ab / 1.2;
		setting_all (params);
	}
	else if (button == 5)
	{
		params->x_ab = params->x_ab * 1.2;
		params->y_ab = params->y_ab * 1.2;
		setting_all (params);
	}
	draw (params);
	return (0);
}
