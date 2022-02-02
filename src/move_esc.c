/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_esc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:36:45 by asalek            #+#    #+#             */
/*   Updated: 2022/02/02 20:07:31 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	move_esc(int keycode, t_info *info)
{
	double	ax;
	double	ay;

	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		julia_shape(info, keycode);
	ax = (info->xmax - info->xmin) / X_AXIS;
	ay = (info->ymax - info->ymin) / Y_AXIS;
	if (keycode == 53 || keycode == 8)
		color_esc(info, keycode);
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			ax *= -1;
		info->xmin += ax / 0.1;
		info->xmax += ax / 0.1;
	}
	if (keycode == 125 || keycode == 126)
	{
		if (keycode == 125)
			ay *= -1;
		info->ymin += ay / 0.1;
		info->ymax += ay / 0.1;
	}
	check_type(info);
	return (0);
}

void	color_esc(t_info *info, int keycode)
{
	if (keycode == 8)
	{
		info->color += 0x00231321;
		check_type(info);
	}
	else
		exit(0);
}
