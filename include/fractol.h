/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:41:24 by asalek            #+#    #+#             */
/*   Updated: 2022/02/02 20:45:51 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//#include "minilibx_mms_20200219/mlx.h"
//#include "minilibx_opengl_20191021/mlx.h"

# define MIN_X -2
# define MIN_Y -2
# define MAX_X 2
# define MAX_Y 2
# define X_AXIS 800
# define Y_AXIS 800
# define ITERATION 130 //details in fractals
# define C_A 0.111//-0.8
# define C_B 0.296//0

# include<stdio.h>
# include<math.h> //M_PI
# include<stdlib.h>
# include<unistd.h>
# include<mlx.h>

typedef struct infos
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	jx;
	double	jy;
	int		x;
	int		y;
	int		color;
	int		julia_or_mandelbrot;
}	t_info;

int		zoom_in_out(int keycode, int x, int y, t_info *s);
void	mandelbrot_draw(double a, double b, t_info *s);
void	mandelbrot(t_info *s);
int		start_mandelbrot(void);
int		move_esc(int keycode, t_info *info);
int		ft_strcmp(const char *s1, const char *s2);
int		start_julia(void);
void	julia(t_info *s);
void	check_type(t_info *info);
void	julia_shape(t_info *info, int keycode);
int		start_burningship(void);
void	burningship(t_info *s);
void	burningship_draw(double a, double b, t_info *s);
void	color_esc(t_info *info, int keycode);

#endif