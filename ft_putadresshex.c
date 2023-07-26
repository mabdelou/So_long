/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresshex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:39:58 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/29 15:42:29 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadresshex(unsigned long int base)
{
	char	*hex;
	int		a;

	a = ft_read_hex(base);
	hex = "0123456789abcdef";
	if (base >= 16)
		ft_putadresshex(base / 16);
	ft_putchar(hex[base % 16]);
	return (a);
}
