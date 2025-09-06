/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:52:16 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 08:13:50 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

int	max(int i, int m)
{
	if (m < i)
		return (m);
	return (i);
}

int	min(int m, int i)
{
	if (m > i)
		return (m);
	return (i);
}

int	clamp(int i, int mi, int ma)
{
	return (min(mi, max(i, ma)));
}
