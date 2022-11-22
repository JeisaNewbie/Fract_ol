typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_fractol {
	void	*mlx;
	void	*win;
	char	*t_fractol;
	int		width;
	int		height;
	t_data	img;
}	t_fractol;

typedef struct	s_complex {
	long double	x;
	long double y;
	long double	a;
	long double	b;
	double		zoom;
}	t_complex;
