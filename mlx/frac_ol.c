#include "fractol_types.h"

int	check_fractol (char *fractol, t_fractol *params)
{
	int	i;

	i = ft_strlen (fractol);
	if (!ft_strncmp ("Mandelbrot", fractol, i))
		params_init ("M", params);
	else if (if ft_strncmp ("Julia", fractol, i))
		params_init ("J", params);
	else
		i++;
	return (0);
}

int main (int argc, char *argv[])
{
	t_fractol	params;
	
	if (check_fractol (argv[0], &params))
	{
		img_init (&params);
		printf_img (&params);
		mlx_loop (params->mlx);
	}
	else
		printf ("Wrong Fract_ol!!!");
}
