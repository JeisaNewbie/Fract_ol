/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:16:01 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 11:19:05 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	key_press(int keycode, t_fractol *params)
{
	if (keycode == 38)
		params->j = !params->j;
	if (keycode == UP)
	{
		params->x_c = params->x_c + 1;
		draw (params);
	}
	mlx_hook (params->win, X_EVENT_MOUSE_MOVEMENT, 0, &mouse_move, params);
	return (0);
}

int	mouse_move(int x, int y, t_fractol *params)
{
	if (params->j)
	{
		params->j_a = x * params->zoom_x + (params->x_c - params->x_ab / 2);
		params->j_b = y * params->zoom_y + (params->y_c - params->y_ab / 2);
		draw (params);
		return (0);
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
