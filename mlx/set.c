int	Mandelbrot_set (t_complex c)
{
	t_complex	z;
	long double	tmpx;
	int			i;

	z.a = c.x;
	z.b = c.y;
	i = 0;

	while (i <= 200 && ((z.a * z.a) + (z.b * z.b)) < 4)
	{
		tmpx = (z.a * z.a) - (z.b * z.b);
		z.b = (2 * z.a * z.b) + c.y;
		z.a = tmpx + c.x;
		i++;
	}
	return (((z.a * z.a) + (z.b * z.b)));
}

int	Julia_set (t_complex c)
{
	t_complex	z;
	long double	tmpx;
	int			i;

	z.a = c.x;
	z.b = c.y;
	i = 0;
	while (i <= 200 && ((z.a * z.a) + (z.b * z.b)) < 4)
	{
		tmpx = (z.a * z.a) - (z.b * z.b);
		z.b = (2 * z.a * z.b) + c.b;
		z.a = tmpx + c.a;
		i++;
	}
	return (((z.a * z.a) + (z.b * z.b)));
}
