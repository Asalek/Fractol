#include "fractol.h"

int	zoom_in_out(int keycode, int x, int y ,info *s)
{
	double	ax;
	double	ay;

	printf("%d-->\t(%d,%d)\n",keycode, x, y);
	ax = (s->xmax - s->xmin) / X_axis;
	ay = (s->ymax - s->ymin) / Y_axis;
	if (keycode == 5)
	{
		s->xmin = (s->xmin + ((ax * x) * 0.2));
		s->xmax = (s->xmax - ((ax * (X_axis - x)) * 0.2));
		s->ymax = (s->ymax - ((ay * y) * 0.2));
		s->ymin = (s->ymin + ((ay * (Y_axis - y)) * 0.2));
	}
	if (keycode == 4)
	{
		s->xmin = (s->xmin - 0.2);
		s->xmax = (s->xmax +  0.2);
		s->ymax = (s->ymax + 0.2);
		s->ymin = (s->ymin - 0.2);
	}
	if(s->julia_or_mandelbrot == 1)
		mandelbrot(s);
	else
		julia(s);
	return (0);
}
