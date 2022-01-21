/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:13:20 by asalek            #+#    #+#             */
/*   Updated: 2022/01/21 19:01:12 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_draw(double a, double b, info *s)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	i = 0;
	x = 0;
	y = 0;
	while (i++ < Iteration)
	{
		tmp = x;
		x = x * x - y * y + a;
		y = (2 * tmp * y) + b;
		if ((x * x) + (y * y) > 4)
			break ;
	}
	if (i == Iteration + 1)//stable numer
		mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->x, s->y, 0xFFFFFF);
	else//unstable number
	{
		s->color = 0xe3e3e3 * i;
		mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->x, s->y, s->color);
	}
}

void	mandelbrot(info *s)
{
	double	a;
	double	b;

	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	s->y = 0;
	while (s->y <= Y_axis)
	{
		s->x = 0;
		while (s->x <= X_axis)
		{
			a = s->xmin + (s->x * ((s->xmax - s->xmin) / X_axis));//-2 ...... 2 
			b = s->ymax - (s->y * ((s->ymax - s->ymin) / Y_axis));//2 ....... -2
			mandelbrot_draw(a, b, s);
			s->x++;
		}
		s->y++;
	}
	mlx_string_put(s->mlx_ptr, s->win_ptr, 699, 9, 0xFFFFFF, "By_ASALEK");
	mlx_string_put(s->mlx_ptr, s->win_ptr, 700, 10, 0x000000, "By_ASALEK");
}
//a = s->xmin + (s->x / (double)200);//ctl+(7jm)_77
//b = s->ymax - (s->y / (double)200);//ctl-_74_rm_78

int	start_mandelbrot(void)
{	
	info	s;

	s.julia_or_mandelbrot = 1;
	s.xmin = min_X;
	s.xmax = max_X;
	s.ymin = min_Y;
	s.ymax = max_Y;
	s.color = 0xe3e3e3;
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window (s.mlx_ptr, X_axis, Y_axis, "Mandelbrot_Set");
	mandelbrot(&s);
	mlx_key_hook(s.win_ptr, move_esc, &s);
	mlx_mouse_hook(s.win_ptr, zoom_in_out, &s);
	mlx_loop(s.mlx_ptr);
	return (0);
}
//gcc mandel_ex.c -O3 -lmlx -framework OpenGL -framework AppKit