/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:37:24 by asalek            #+#    #+#             */
/*   Updated: 2022/02/02 20:07:41 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_type(t_info *info)
{
	if (info->julia_or_mandelbrot == 1)
		mandelbrot(info);
	if (info->julia_or_mandelbrot == 2)
		julia(info);
	if (info->julia_or_mandelbrot == 3)
		burningship(info);
}

void	julia_shape(t_info *info, int keycode)
{
	if (keycode == 0)
		info->jx += 0.1;
	if (keycode == 2)
		info->jx -= 0.1;
	if (keycode == 13)
		info->jy += 0.1;
	if (keycode == 1)
		info->jy -= 0.1;
	julia(info);
}
