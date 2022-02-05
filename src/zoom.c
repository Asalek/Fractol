/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:38:32 by asalek            #+#    #+#             */
/*   Updated: 2022/02/05 16:18:05 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	zoom_in_out(int keycode, int x, int y, t_info *s)
{
	double	ax;
	double	ay;

	printf("%d-->\t(%d,%d)\n", keycode, x, y);
	ax = (s->xmax - s->xmin) / X_AXIS;
	ay = (s->ymax - s->ymin) / Y_AXIS;
	if (keycode == 5)
	{
		s->xmin = (s->xmin + ((ax * x) * 0.2));
		s->xmax = (s->xmax - ((ax * (X_AXIS - x)) * 0.2));
		s->ymax = (s->ymax - ((ay * y) * 0.2));
		s->ymin = (s->ymin + ((ay * (Y_AXIS - y)) * 0.2));
	}
	if (keycode == 4)
	{
		s->xmin = (s->xmin - 0.2);
		s->xmax = (s->xmax + 0.2);
		s->ymax = (s->ymax + 0.2);
		s->ymin = (s->ymin - 0.2);
	}
	check_type(s);
	return (0);
}
