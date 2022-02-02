/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:06:39 by asalek            #+#    #+#             */
/*   Updated: 2022/02/02 19:34:31 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	available_fractols(void)
{
	printf(":: This is the available fractals :\n");
	printf("\t- Mandelbrot Set\n");
	printf("\t- Julia Set\n\n");
}

void	tutorial(void)
{
	printf("::		available key to use		  ::\n");
	printf(":: You can use arrows to move : ↑ ↓ → ← 	  ::\n");
	printf(":: Mouse Wheel can zoom in and out		  ::\n");
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

int	main(int ac, char *av[])
{
	available_fractols();
	if (ac != 2)
	{
		how_to_use();
		exit(0);
	}
	tutorial();
	if (check_fractal_type(av[1]) == 0)
		how_to_use();
	if (check_fractal_type(av[1]) == 1)
		start_mandelbrot();
	if (check_fractal_type(av[1]) == 2)
		start_julia();
	if (check_fractal_type(av[1]) == 3)
		start_burningship();
}
