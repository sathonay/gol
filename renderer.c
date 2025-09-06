/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:33:41 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 10:38:15 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	render(t_contxt *contxt)
{
	(void) contxt;
	mlx_string_put(contxt->mlx, contxt->win, 10, 10, 0xFFFFFFFF, "salut");
}
