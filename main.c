/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:57:17 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 10:31:25 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

static void	init_render_contxt(t_contxt *contxt)
{
	contxt->mousex = 0;
	contxt->mousey = 0;
	contxt->zoom = 100;
	contxt->xoffset = WIDTH / 2 / contxt->zoom;
	contxt->yoffset = HEIGHT / 2 / contxt->zoom;
	contxt->img = mlx_new_image(contxt->mlx, WIDTH, HEIGHT);
	contxt->buffer = mlx_get_data_addr(contxt->img,
			&contxt->pixel_bits, &contxt->line_bytes, &contxt->endian);
	contxt->rectangle.width = WIDTH / DIRTY_FRAME_TICKS;
	contxt->rectangle.height = HEIGHT / DIRTY_FRAME_TICKS;
}

int	main(int argc, char **argv)
{
	t_contxt	contxt;

	if (!parse(argc, argv, &contxt))
		return (0);
	contxt.mlx = mlx_init();
	if (contxt.mlx)
	{
		contxt.win = mlx_new_window(contxt.mlx, WIDTH, HEIGHT, "Fracture");
		if (contxt.win)
		{
			init_render_contxt(&contxt);
			mlx_hook(contxt.win, 2, 1, (int (*)()) & key_down_hooker, &contxt);
			mlx_key_hook(contxt.win, &key_hooker, &contxt);
			mlx_mouse_hook(contxt.win, &mouse_hooker, &contxt);
			render(&contxt);
			mlx_hook(contxt.win, 17, 0, mlx_loop_end, contxt.mlx);
			mlx_loop_hook(contxt.mlx, &loop_hooker, &contxt);
			mlx_loop(contxt.mlx);
			mlx_destroy_image(contxt.mlx, contxt.img);
			mlx_destroy_window(contxt.mlx, contxt.win);
			mlx_destroy_display(contxt.mlx);
			free(contxt.mlx);
		}
	}
	return (0);
}
