/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:15:48 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 11:20:22 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	check_fractol(char *fractol, t_fractol *params)
{
	if (!ft_strncmp ("Mandelbrot", fractol, -1))
		params_init ('M', params);
	else if (!ft_strncmp ("Julia", fractol, -1))
		params_init ('J', params);
	else if (!ft_strncmp ("Burningship", fractol, -1))
		params_init ('B', params);
	else
		return (0);
	return (1);
}

void	print_img(t_fractol *params)
{
	if (params->fractol == 'M')
		prt_mand (params);
	else if (params->fractol == 'J')
		prt_jul (params);
	else if (params->fractol == 'B')
		prt_burn (params);
	else
		return ;
}

void	mlx_hooks(t_fractol *params)
{
	mlx_key_hook (params->win, &key_hook, params);
	mlx_hook (params->win, X_EVENT_MOUSE_PRESS, 0, &mouse_press, params);
	if (params->fractol == 'J')
		mlx_hook (params->win, X_EVENT_KEY_PRESS, 0, &key_press, params);
}

int	main(int argc, char *argv[])
{
	t_fractol	params;

	params.fractols = "Mandelbrot\nJulia\nBurningship";
	if (argc == 1)
	{
		printf ("Type Fract_ol\n");
		printf ("%s\n", params.fractols);
		return (0);
	}
	if (check_fractol (argv[1], &params))
	{
		img_init (&params);
		print_img (&params);
		mlx_hooks (&params);
		mlx_loop (params.mlx);
	}
	else
	{
		printf ("Wrong Fract_ol\n");
		printf ("%s", params.fractols);
		exit (1);
	}
	return (0);
}
