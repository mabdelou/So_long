/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:35:35 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/29 17:06:49 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

int	ft_printf_v2(va_list lst, char c, int a)
{
	if (c == 'c')
		a += ft_putchar(va_arg(lst, int));
	else if (c == 's')
		a += ft_putstr(va_arg(lst, char *));
	else if (c == 'i' || c == 'd')
		a += ft_putnbr(va_arg(lst, int));
	else if (c == 'u')
		a += ft_unsigned_putnbr(va_arg(lst, unsigned int));
	else if (c == '%')
		a += ft_putchar(37);
	else if (c == 'X')
		a += ft_putuphex(va_arg(lst, unsigned int));
	else if (c == 'x')
		a += ft_putdownhex(va_arg(lst, unsigned int));
	else if (c == 'p')
	{
		a += ft_putstr("0x");
		a += ft_putadresshex(va_arg(lst, unsigned long int));
	}
	return (a);
}

int	ft_printf(const char *str, ...)
{
	int		b;
	int		a;
	va_list	lst;

	va_start(lst, str);
	b = 0;
	a = 0;
	while (str[b] != '\0')
	{
		if (str[b] == '%')
		{
			if (!str[b])
				return (a);
			a = ft_printf_v2(lst, str[b + 1], a);
			b++;
		}
		else
			a += ft_putchar(str[b]);
		b++;
	}
	va_end(lst);
	return (a);
}
