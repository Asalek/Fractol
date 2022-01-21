#ifndef FRACTOL_H
#define FRACTOL_H

//#include "minilibx_mms_20200219/mlx.h"
//#include "minilibx_opengl_20191021/mlx.h"

#define min_X -2
#define min_Y -2
#define max_X 2
#define max_Y 2
#define X_axis 800
#define Y_axis 800
#define	Iteration 130 //details in fractals

#include <stdio.h>
#include <math.h> //M_PI
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

typedef struct infos
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	xmin;
	double 	xmax;
	double	ymin;
	double	ymax;
	double	jx;
	double 	jy;
	int		x;
	int		y;
	int		color;
	int		julia_or_mandelbrot;
}	info;

int		zoom_in_out(int keycode, int x, int y ,info *s);
void	mandelbrot_draw(double a, double b, info *s);
void	mandelbrot(info *s);
int		start_mandelbrot(void);
int		move_esc(int keycode, info *info);
int		ft_strcmp(const char *s1, const char *s2);
int		start_julia(void);
void	julia(info *s);
void	check_type(info *info);
void	julia_shape(info *info, int keycode);

#endif