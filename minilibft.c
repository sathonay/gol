/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:43:03 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 08:14:04 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char) *s1 && (unsigned char) *s2
		&& (unsigned char) *s1 == (unsigned char) *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

double	ft_atod(char *str)
{
	double	s;
	double	i;
	double	d2;
	int		ep;

	s = 1;
	i = 0;
	d2 = 0;
	ep = 10;
	if (*str == '-' && str++)
		s = -1;
	while (ft_isdigit(*str))
		i = i * 10 + (*(str++) - '0');
	if (*str == '.' && str++)
	{
		while (ft_isdigit(*str))
		{
			d2 += ((double)(*(str++) - '0') / ep);
			ep *= 10;
		}
	}
	return (((double)s * (i + d2)));
}

int	random32(void)
{
	int	fd;
	int	val;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, &val, sizeof(val));
	close(fd);
	return (val);
}

int	hex_to_int(char *str)
{
	unsigned int	v;
	int				i;
	char			*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	while (*str)
	{
		i = 0;
		while (hex[i] && hex[i] != *str)
			i++;
		if (!hex[i])
			break ;
		v = v * 16 + i;
		str++;
	}
	return ((int)v);
}
