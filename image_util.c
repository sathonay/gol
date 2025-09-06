/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:02:15 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 08:13:36 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	set_pixel_color(t_contxt *contxt, int x, int y, int color)
{
	int	pixel;

	pixel = (y * contxt->line_bytes) + (x * 4);
	if (x < 0 || y < 0)
		return ;
	if (contxt->endian == 1)
	{
		contxt->buffer[pixel + 0] = (color >> 24);
		contxt->buffer[pixel + 1] = (color >> 16) & 0xFF;
		contxt->buffer[pixel + 2] = (color >> 8) & 0xFF;
		contxt->buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (contxt->endian == 0)
	{
		contxt->buffer[pixel + 0] = (color) & 0xFF;
		contxt->buffer[pixel + 1] = (color >> 8) & 0xFF;
		contxt->buffer[pixel + 2] = (color >> 16) & 0xFF;
		contxt->buffer[pixel + 3] = (color >> 24);
	}
}
