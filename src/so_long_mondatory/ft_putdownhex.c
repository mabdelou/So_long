/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdownhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:43:47 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/29 15:45:22 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

int	ft_putdownhex(unsigned int base)
{
	char	*hex;
	int		a;

	a = ft_read_hex(base);
	hex = "0123456789abcdef";
	if (base >= 16)
		ft_putdownhex(base / 16);
	ft_putchar(hex[base % 16]);
	return (a);
}
