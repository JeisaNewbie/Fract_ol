/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:16:13 by jhwang2           #+#    #+#             */
/*   Updated: 2022/12/04 13:29:42 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot_set(t_complex c, t_fractol *params)
{
	t_complex	z;
	double		tmpx;

	z.a = c.a;
	z.b = c.b;
	params->i = 0;
	while (params->i <= 200 && ((z.a * z.a) + (z.b * z.b)) < 4)
	{
		tmpx = (z.a * z.a) - (z.b * z.b);
		z.b = (2 * z.a * z.b) + c.b;
		z.a = tmpx + c.a;
		params->i++;
	}
	return (((z.a * z.a) + (z.b * z.b)));
}

double	julia_set(t_complex c, t_fractol *params)
{
	t_complex	z;
	double		tmpx;

	z.a = c.a;
	z.b = c.b;
	params->i = 0;
	while (params->i <= 80 && ((z.a * z.a) + (z.b * z.b)) < 4)
	{
		tmpx = (z.a * z.a) - (z.b * z.b);
		z.b = (2 * z.a * z.b) + params->C_b;
		z.a = tmpx + params->C_a;
		params->i++;
	}
	return (((z.a * z.a) + (z.b * z.b)));
}

double burningship_set(t_complex c, t_fractol *params)
{
	t_complex 	z;
	double 		tmpx;

	z.a = c.a;
	z.b = c.b;
	params->i = 0;
	while (params->i < 80 && (z.a * z.a) + (z.b * z.b) < 4)
        {
            tmpx = (z.a * z.b);
            z.a = (z.a * z.a) - (z.b * z.b) + c.a;
            z.b = 2.0 * fabs(tmpx) + c.b;
            params->i++;
	}
	return (((z.a * z.a) + (z.b * z.b)));
}