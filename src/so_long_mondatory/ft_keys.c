/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:02:00 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/12 02:02:04 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/solong.h"
#include "../../lib/ft_printf.h"

void	ft_key_one(int keycode, t_list *s)
{
	if (keycode == 2 || keycode == 124)
	{
		if (s->buffer[s->num_buf + 1] != '1'
			&& s->buffer[s->num_buf + 1] != 'E')
		{
			++s->mv;
			ft_printf("%d\n", s->mv);
		}
		ft_right(s);
	}
}

void	ft_key_tow(int keycode, t_list *s)
{
	if (keycode == 0 || keycode == 123)
	{
		if (s->buffer[s->num_buf - 1] != '1'
			&& s->buffer[s->num_buf - 1] != 'E')
		{
			++s->mv;
			ft_printf("%d\n", s->mv);
		}
		ft_left(s);
	}
}

void	ft_key_three(int keycode, t_list *s)
{
	if (keycode == 13 || keycode == 126)
	{
		if (s->buffer[s->num_buf - (s->num_line + 1)] != '1'
			&& s->buffer[s->num_buf - (s->num_line + 1)] != 'E')
		{
			++s->mv;
			ft_printf("%d\n", s->mv);
		}
		ft_top(s);
	}
}

void	ft_key_four(int keycode, t_list *s)
{
	if (keycode == 1 || keycode == 125)
	{
		if (s->buffer[s->num_buf + (s->num_line + 1)] != '1'
			&& s->buffer[s->num_buf + (s->num_line + 1)] != 'E')
		{
			++s->mv;
			ft_printf("%d\n", s->mv);
		}
		ft_down(s);
	}
	if (keycode == 53)
		exit(0);
}
