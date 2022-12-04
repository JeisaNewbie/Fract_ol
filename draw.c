/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:16:20 by jhwang2           #+#    #+#             */
/*   Updated: 2022/11/30 12:20:15 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    redraw(t_fractol *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->width)
	{
		j = 0;
		while (j < params->height)
		{
			my_mlx_pixel_put (params, i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window (params->mlx, params->win, params->img, 0, 0);
}

int draw(t_fractol *params)
{
	redraw (params);
    if (params->fractol == 'M')
        prt_mand (params);
    else if (params->fractol == 'J')
    	prt_jul (params);
	else if (params->fractol == 'B')
		prt_burn (params);
    else
        return (1);
	return (0);
}