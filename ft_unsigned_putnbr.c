/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:52:14 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/29 15:53:55 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(char c)
{
	write(1, &c, 1);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	a;

	a = ft_print_nb(nb);
	if (nb < 10)
	{
		print_num(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		print_num(nb % 10 + '0');
	}
	return (a);
}
