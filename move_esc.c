#include "fractol.h"

int	move_esc(int keycode, info *info)
{
	double	ax;
	double	ay;

	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		julia_shape(info, keycode);
	ax = (info->xmax - info->xmin) / X_axis;
	ay = (info->ymax - info->ymin) / Y_axis;
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			ax *= -1;
		info->xmin += ax / 0.2;
		info->xmax += ax / 0.2;
	}
	if (keycode == 125 || keycode == 126)
	{
		if (keycode == 125)
			ay *= -1;
		info->ymin += ay / 0.2;
		info->ymax += ay / 0.2;
	}
	check_type(info);
	return (0);
}