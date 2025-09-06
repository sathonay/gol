/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinyprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:54:01 by alrey             #+#    #+#             */
/*   Updated: 2025/09/06 08:14:40 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h" 
#include <stdarg.h>

static int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	tprintf(char *format, ...)
{
	int			count;
	va_list		va;

	va_start(va, format);
	while (*format)
	{
		if (*format == '%' && format[1] == 's')
		{
			count += print_str(va_arg(va, char *));
			format += 2;
		}
		count += write(1, format++, 1);
	}
	va_end(va);
	return (count);
}
