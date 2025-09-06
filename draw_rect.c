/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:02:34 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 08:12:44 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	draw_solid_rect(t_contxt *contxt, t_rectangle *rect)
{
	int	i;
	int	j;

	i = 0;
	while (i < rect->height && i + rect->y < HEIGHT)
	{
		j = 0;
		while (j < rect->width && j + rect->x < WIDTH)
		{
			set_pixel_color(contxt, rect->x + i, rect->y + j, rect->color);
			j++;
		}
		i++;
	}
}

void	draw_hollow_rect(t_contxt *contxt, t_rectangle *rect)
{
	int	i;
	int	j;

	i = rect->x;
	j = rect->y;
	while (i <= rect->x + rect->width && i < WIDTH)
	{
		if (rect->y + rect->height < HEIGHT)
			set_pixel_color(contxt, i, rect->y + rect->height, rect->color);
		i++;
	}
	while (j < rect->y + rect->height && j < HEIGHT)
	{
		if (rect->x + rect->width < WIDTH)
			set_pixel_color(contxt, rect->x + rect->width, j, rect->color);
		j++;
	}
}
