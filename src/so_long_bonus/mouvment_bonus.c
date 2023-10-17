/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:17:55 by mabdelou          #+#    #+#             */
/*   Updated: 2021/12/23 21:18:00 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/solongbonus.h"

void	ft_player(t_list *s, int a)
{
	if (a == 1)
	{
		s->buffer[s->num_buf - 1] = '0';
		s->buffer[s->num_buf] = 'P';
	}
	if (a == 2)
	{
		s->buffer[s->num_buf + 1] = '0';
		s->buffer[s->num_buf] = 'P';
	}
	if (a == 3)
	{
		s->buffer[s->num_buf + (s->num_line + 1)] = '0';
		s->buffer[s->num_buf] = 'P';
	}
	if (a == 4)
	{
		s->buffer[s->num_buf - (s->num_line + 1)] = '0';
		s->buffer[s->num_buf] = 'P';
	}
}

void	ft_right(t_list *s)
{
	if (s->buffer[s->num_buf + 1] != '1')
	{
		if (s->buffer[s->num_buf + 1] == 'C')
		{
			s->cakes--;
			s->points += 10;
			s->buffer[s->num_buf + 1] = '0';
		}
		if (s->buffer[s->num_buf + 1] == 'E' && s->cakes == 0)
		{
			write(1, "YOU WIN\n", 8);
			free(s->buffer);
			free(s->enemmy_arrays);
			mlx_destroy_window(s->ptr, s->win);
			exit(0);
		}
		if (s->buffer[s->num_buf + 1] != 'E')
		{
			mlx_put_image_to_window(s->ptr, s->win, s->img_grass, s->xp, s->yp);
			s->xp += 30;
			s->num_buf += 1;
			mlx_put_image_to_window(s->ptr, s->win, s->img_plyer, s->xp, s->yp);
		}
		ft_player(s, 1);
	}
}

void	ft_left(t_list *s)
{
	if (s->buffer[s->num_buf - 1] != '1')
	{
		if (s->buffer[s->num_buf - 1] == 'C')
		{
			s->cakes--;
			s->points += 10;
			s->buffer[s->num_buf -1] = '0';
		}
		if (s->buffer[s->num_buf - 1] == 'E' && s->cakes == 0)
		{
			write(1, "YOU WIN\n", 8);
			free(s->buffer);
			free(s->enemmy_arrays);
			mlx_destroy_window(s->ptr, s->win);
			exit(0);
		}
		if (s->buffer[s->num_buf - 1] != 'E')
		{
			mlx_put_image_to_window(s->ptr, s->win, s->img_grass, s->xp, s->yp);
			s->xp -= 30;
			s->num_buf -= 1;
			mlx_put_image_to_window(s->ptr, s->win, s->img_plyer, s->xp, s->yp);
		}
		ft_player(s, 2);
	}
}

void	ft_top(t_list *s)
{
	if (s->buffer[s->num_buf - (s->num_line + 1)] != '1')
	{
		if (s->buffer[s->num_buf - (s->num_line + 1)] == 'C')
		{
			s->cakes--;
			s->points += 10;
			s->buffer[s->num_buf - (s->num_line + 1)] = '0';
		}
		ft_top_v2(s);
		if (s->buffer[s->num_buf - (s->num_line + 1)] != 'E')
		{
			mlx_put_image_to_window(s->ptr, s->win, s->img_grass, s->xp, s->yp);
			s->yp -= 30;
			s->num_buf -= s->num_line + 1;
			mlx_put_image_to_window(s->ptr, s->win, s->img_plyer, s->xp, s->yp);
		}
		ft_player(s, 3);
	}
}

void	ft_down(t_list *s)
{
	if (s->buffer[s->num_buf + (s->num_line + 1)] != '1')
	{
		if (s->buffer[s->num_buf + (s->num_line + 1)] == 'C')
		{
			s->cakes--;
			s->points += 10;
			s->buffer[s->num_buf + (s->num_line + 1)] = '0';
		}
		ft_down_v2(s);
		if (s->buffer[s->num_buf + (s->num_line + 1)] != 'E')
		{
			mlx_put_image_to_window(s->ptr, s->win, s->img_grass, s->xp, s->yp);
			s->yp += 30;
			s->num_buf += s->num_line + 1;
			mlx_put_image_to_window(s->ptr, s->win, s->img_plyer, s->xp, s->yp);
		}
		ft_player(s, 4);
	}
}
