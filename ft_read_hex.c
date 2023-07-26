/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:51:02 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/29 15:51:56 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_hex(unsigned long int nb)
{
	int	nbr_len;

	nbr_len = 1;
	if (nb < 0)
	{
		nb *= -1;
		nbr_len++;
	}
	while (nb >= 16)
	{
		nb = nb / 16;
		nbr_len++;
	}
	return (nbr_len);
}
