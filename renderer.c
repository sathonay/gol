/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:33:41 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 11:01:19 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	render(t_contxt *contxt)
{
	char	*str;
	t_rectangle rect;
	rect.x = 0;
	rect.y = 0;
	rect.width = 100;
	rect.height = 100;
	rect.color = 0;
	draw_solid_rect(contxt, &rect);
	mlx_put_image_to_window(contxt->mlx, contxt->win, contxt->img, 0, 0);
	asprintf(&str, "x: %Lf\ny: %Lf", contxt->xoffset, contxt->yoffset);
	mlx_string_put(contxt->mlx, contxt->win, 10, 10, 0xFFFFFFFF, str);
	free(str);
}
