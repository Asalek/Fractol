/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:01:38 by asalek            #+#    #+#             */
/*   Updated: 2022/01/21 20:04:09 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(double a, double b, info *s)
{
	int		i;
	double	x;
	double	y;
	double	temp;

	x = a;
	y = b;
	i = 0;
	while (i < Iteration)
	{
		temp = x;
		x = ((x * x) - (y * y)) + 0.111 + s->jx;
		y = (2 * temp * y) + 0.296 + s->jy;
		if ((x * x) + (y * y) > 4)
		{
			s->color = 0xccf1ff * i;
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->x, s->y, s->color);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(s -> mlx_ptr, s -> win_ptr, s->x, s->y, 0xFFFFFF);
	return (0);
}

void	julia(info *s)
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
			julia_set(a, b, s);
			s->x++;
		}
		s->y++;
	}
	mlx_string_put(s->mlx_ptr, s->win_ptr, 699, 9, 0x000000, "By_ASALEK");
	mlx_string_put(s->mlx_ptr, s->win_ptr, 700, 10, 0xFFFFFF, "By_ASALEK");
}
//a = s->xmin + (s->x / (double)200);//ctl+(7jm)_77
//b = s->ymax - (s->y / (double)200);//ctl-_74_rm_78

int	start_julia(void)
{	
	info	s;

	s.julia_or_mandelbrot = 2;
	s.xmin = min_X;
	s.xmax = max_X;
	s.ymin = min_Y;
	s.ymax = max_Y;
	s.jx = 0;
	s.jy = 0;
	s.color = 0;
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window (s.mlx_ptr, X_axis, Y_axis, "Julia_Set");
	julia(&s);
	mlx_key_hook(s.win_ptr, move_esc, &s);
	mlx_mouse_hook(s.win_ptr, zoom_in_out, &s);
	mlx_loop(s.mlx_ptr);
	return (0);
}
//gcc mandel_ex.c -O3 -lmlx -framework OpenGL -framework AppKit