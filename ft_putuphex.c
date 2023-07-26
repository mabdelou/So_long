/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:47:45 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/29 15:49:56 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphex(unsigned int base)
{
	char	*hex;
	int		a;

	a = ft_read_hex(base);
	hex = "0123456789ABCDEF";
	if (base >= 16)
		ft_putuphex(base / 16);
	ft_putchar(hex[base % 16]);
	return (a);
}
