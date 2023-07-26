/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:05:51 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/09 13:25:22 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solongbonus.h"

static	int	calc_size(int n)
{
	int	a;

	a = 0;
	while (n != 0)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

static	char	*switch_nb(char *s_nb, int b)
{
	int		a;
	int		d;
	char	c;

	a = 0;
	while (s_nb[a])
		a++;
	if (b == 1)
	{
		if (a % 2 == 0)
			d = a / 2;
		if (a % 2 == 1)
			d = (a / 2) + 1;
	}
	else
		d = a / 2;
	while (a > d)
	{
		c = s_nb[b];
		s_nb[b++] = s_nb[a - 1];
		s_nb[a - 1] = c;
		a--;
	}
	return (s_nb);
}

static	char	*neg_num(int n)
{
	int				a;
	int				c;
	char			*nbr;
	unsigned int	num;

	a = calc_size(n);
	c = 1;
	num = (unsigned int)n * (-1);
	nbr = (char *)malloc(sizeof(char) * (a + 2));
	if (nbr == NULL)
		return (NULL);
	nbr[0] = '-';
	while (num != 0)
	{
		nbr[c++] = ((num % 10) + 48);
		num = num / 10;
	}
	nbr[c] = '\0';
	switch_nb(nbr, 1);
	return (nbr);
}

static	char	*sero_maloc(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		a;
	int		c;
	char	*nbr;

	if (n == 0)
		return (sero_maloc());
	else if (n > 0)
	{
		a = calc_size(n);
		c = 0;
		nbr = (char *)malloc(sizeof(char) * (a + 2));
		if (nbr == NULL)
			return (NULL);
		while (n != 0)
		{
			nbr[c++] = ((n % 10) + 48);
			n = n / 10;
		}
		nbr[c] = '\0';
		switch_nb(nbr, 0);
		return (nbr);
	}
	return (neg_num(n));
}
