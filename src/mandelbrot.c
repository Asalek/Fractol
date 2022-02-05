/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:13:20 by asalek            #+#    #+#             */
/*   Updated: 2022/02/05 16:11:41 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot_draw(double a, double b, t_info *s)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (i++ < ITERATION)
	{
		tmp = x;
		x = x * x - y * y + a;
		y = (2 * tmp * y) - b;
		if ((x * x) + (y * y) > 4)
			break ;
	}
	if (i == ITERATION + 1)
		mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->x, s->y, 0xFFFFFF);
	else
	{
		mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->x, s->y,
			s->color + (0xe3e3e3 * i));
	}
}

void	mandelbrot(t_info *s)
{
	double	a;
	double	b;

	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	s->y = 0;
	while (s->y <= Y_AXIS)
	{
		s->x = 0;
		while (s->x <= X_AXIS)
		{
			a = s->xmin + (s->x * (s->xmax - s->xmin)/800);
			b = s->ymax - (s->y * (s->xmax - s->xmin)/800);
			mandelbrot_draw(a, b, s);
			s->x++;
		}
		s->y++;
	}
	mlx_string_put(s->mlx_ptr, s->win_ptr, 699, 9, 0xFFFFFF, "By_ASALEK");
	mlx_string_put(s->mlx_ptr, s->win_ptr, 700, 10, 0x000000, "By_ASALEK");
}

int	start_mandelbrot(void)
{	
	t_info	s;

	s.julia_or_mandelbrot = 1;
	s.xmin = MIN_X;
	s.xmax = MAX_X;
	s.ymin = MIN_Y;
	s.ymax = MAX_Y;
	s.color = 0;
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window (s.mlx_ptr, X_AXIS, Y_AXIS, "Mandelbrot_Set");
	mandelbrot(&s);
	mlx_key_hook(s.win_ptr, move_esc, &s);
	mlx_mouse_hook(s.win_ptr, zoom_in_out, &s);
	mlx_loop(s.mlx_ptr);
	return (0);
}
