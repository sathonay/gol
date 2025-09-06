/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:03:13 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 10:33:32 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

static void	handle_keys(int key, t_contxt *contxt)
{
	(void) key;
	(void) contxt;
}

void	key_down_hooker(int button, t_contxt *contxt)
{
	if (button == LEFTARROW)
		contxt->arrow_keys[2] = 0;
	if (button == RIGHTARROW)
		contxt->arrow_keys[0] = 0;
	if (button == UPARROW)
		contxt->arrow_keys[3] = 0;
	if (button == DOWNARROW)
		contxt->arrow_keys[1] = 0;
	if (LEFTARROW <= button && button <= DOWNARROW)
		contxt->arrow_keys[button - LEFTARROW] = 1;
	handle_keys(button, contxt);
}

int	loop_hooker(t_contxt *contxt)
{
	render(contxt);
	return (1);
}
	//else
		//mlx_put_image_to_window(contxt->mlx, contxt->win, contxt->img, 0, 0);

int	mouse_hooker(int button, int x, int y, t_contxt *contxt)
{
	long double	prev_z;
	long double	dx;
	long double	dy;

	prev_z = contxt->zoom;
	dx = (x - contxt->xoffset * contxt->zoom) / prev_z;
	dy = (y - contxt->yoffset * contxt->zoom) / prev_z;
	if (button == 4)
		contxt->zoom += (12 * (contxt->zoom * 0.01));
	if (button == 5)
		contxt->zoom -= (12 * (contxt->zoom * 0.01));
	if (button != 4 || button != 5)
	{
		contxt->xoffset = (x - dx * contxt->zoom) / contxt->zoom;
		contxt->yoffset = (y - dy * contxt->zoom) / contxt->zoom;
	}
	return (0);
}

int	key_hooker(int button, t_contxt *contxt)
{
	if (contxt && button == ESC)
		mlx_loop_end(contxt->mlx);
	if (LEFTARROW <= button && button <= DOWNARROW)
	{
		if (contxt->arrow_keys[0] == 1)
			contxt->xoffset -= 10 / contxt->zoom;
		if (contxt->arrow_keys[1] == 1)
			contxt->yoffset -= 10 / contxt->zoom;
		if (contxt->arrow_keys[2] == 1)
			contxt->xoffset += 10 / contxt->zoom;
		if (contxt->arrow_keys[3] == 1)
			contxt->yoffset += 10 / contxt->zoom;
		contxt->arrow_keys[button - LEFTARROW] = 0;
	}
	return (1);
}
