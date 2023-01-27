/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:15:41 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 10:43:15 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./mlx/mlx.h"

# define UP						126
# define DOWN					125
# define RIGHT					124
# define LEFT					123
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_MOVEMENT	6

typedef struct s_fractol {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*fractols;
	char	fractol;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		j;
	double	x_ab;
	double	y_ab;
	double	zoom_x;
	double	zoom_y;
	double	x_c;
	double	y_c;
	double	j_a;
	double	j_b;
}	t_fractol;

typedef struct s_complex {
	double	a;
	double	b;
}	t_complex;

int		init_j(t_fractol *params);
int		init_m(t_fractol *params);
int		init_b(t_fractol *params);
int		img_init(t_fractol *params);
int		params_init(char c, t_fractol *params);
void	prt_jul(t_fractol *params);
void	prt_mand(t_fractol *params);
void	prt_burn(t_fractol *params);
void	prt_n(t_fractol *params);
int		draw(t_fractol *params);
int		creat_trgb(double trgb, int i);
int		mouse_press(int button, int x, int y, t_fractol *params);
int		key_press(int keycode, t_fractol *params);
void	setting_all(t_fractol *params);
int		mouse_move(int x, int y, t_fractol *params);
int		key_hook(int keycode, t_fractol *params);
void	my_mlx_pixel_put(t_fractol *params, int x, int y, int color);
double	mandelbrot_set(t_complex c, t_fractol *params);
double	julia_set(t_complex c, t_fractol *params);
double	burningship_set(t_complex c, t_fractol *params);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);

#endif