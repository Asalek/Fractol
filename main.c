/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:06:39 by asalek            #+#    #+#             */
/*   Updated: 2022/02/05 16:13:34 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	tutorial(void)
{
	printf("\n::		available key to use		  ::\n");
	printf(":: You can use arrows to move : ↑ ↓ → ← 	  ::\n");
	printf(":: Mouse Wheel can zoom in and out		  ::\n");
	printf(":: C Key Will Change the color in all fractals    ::\n");
	printf(":: For Julia (A,W,S,D) to change the shape 	  ::\n");
}

void	how_to_use(void)
{
	printf(":: To get into the fractal world type one of bellow :\n");
	printf("\n\t./fractol mandelbrot");
	printf("\n\t./fractol julia");
	printf("\n\t./fractol burningship\n\n");
}

int	check_fractal_type(char *str1)
{
	if (ft_strcmp(str1, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(str1, "julia") == 0)
		return (2);
	if (ft_strcmp(str1, "burningship") == 0)
		return (3);
	else
		return (0);
}

int	choose(int keycode, t_img *t)
{
	if (keycode == 53)
	{
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	if (keycode == 18 || keycode == 83)
		start_mandelbrot();
	if (keycode == 19 || keycode == 84)
		start_julia();
	if (keycode == 20 || keycode == 85)
		start_burningship();
	return (0);
}

int	main(void)
{
	t_img	t;

	tutorial();
	t.path = "./IMG/fract.xpm";
	t.mlx = mlx_init();
	t.image = mlx_xpm_file_to_image(t.mlx, t.path, &t.width, &t.height);
	t.win = mlx_new_window(t.mlx, 600, 600, "Fractal's Home");
	mlx_put_image_to_window(t.mlx, t.win, t.image, 0, 0);
	mlx_key_hook(t.win, choose, &t);
	mlx_loop(t.mlx);
	return (0);
}
