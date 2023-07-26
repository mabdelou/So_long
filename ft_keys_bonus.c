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

#include "solongbonus.h"

void	ft_key_one(int keycode, t_list *s)
{
	char	*movment;

	if (keycode == 2 || keycode == 124)
	{
		if (s->buffer[s->num_buf + 1] != '1'
			&& s->buffer[s->num_buf + 1] != 'E')
		{
			movment = ft_itoa(++s->mv);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 0, 0);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 30, 0);
			mlx_string_put(s->ptr, s->win, 0, 0, 0x00FFFFFF, movment);
			free(movment);
		}
		ft_right(s);
	}
}

void	ft_key_tow(int keycode, t_list *s)
{
	char	*movment;

	if (keycode == 0 || keycode == 123)
	{
		if (s->buffer[s->num_buf - 1] != '1'
			&& s->buffer[s->num_buf - 1] != 'E')
		{
			movment = ft_itoa(++s->mv);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 0, 0);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 30, 0);
			mlx_string_put(s->ptr, s->win, 0, 0, 0x00FFFFFF, movment);
			free(movment);
		}
		ft_left(s);
	}
}

void	ft_key_three(int keycode, t_list *s)
{
	char	*movment;

	if (keycode == 13 || keycode == 126)
	{
		if (s->buffer[s->num_buf - (s->num_line + 1)] != '1'
			&& s->buffer[s->num_buf - (s->num_line + 1)] != 'E')
		{
			movment = ft_itoa(++s->mv);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 0, 0);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 30, 0);
			mlx_string_put(s->ptr, s->win, 0, 0, 0x00FFFFFF, movment);
			free(movment);
		}
		ft_top(s);
	}
}

void	ft_key_four(int keycode, t_list *s)
{
	char	*movment;

	if (keycode == 1 || keycode == 125)
	{
		if (s->buffer[s->num_buf + (s->num_line + 1)] != '1'
			&& s->buffer[s->num_buf + (s->num_line + 1)] != 'E')
		{
			movment = ft_itoa(++s->mv);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 0, 0);
			mlx_put_image_to_window(s->ptr, s->win, s->img_wall, 30, 0);
			mlx_string_put(s->ptr, s->win, 0, 0, 0x00FFFFFF, movment);
			free(movment);
		}
		ft_down(s);
	}
	if (keycode == 53)
		exit(0);
}
