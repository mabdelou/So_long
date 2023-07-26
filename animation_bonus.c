/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:06:00 by mabdelou          #+#    #+#             */
/*   Updated: 2022/01/03 10:06:03 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solongbonus.h"

int	condition(t_list *s, int x, int y)
{
	int	a;
	int	b;
	int	no_move;

	a = ((s->words + 1) / ((s->words + 1) / s->num_line)) - 1;
	b = ((x + 30) / 30) + ((y / 30) * (a + 1));
	if (s->buffer[b - 2] == 'P' || s->buffer[b] == 'P')
	{
		write(1, "you lose\n", 9);
		free(s->buffer);
		free(s->enemmy_arrays);
		exit(0);
	}
	if (s->buffer[b - (s->num_line + 2)] == 'P'
		|| s->buffer[b + s->num_line] == 'P')
	{
		write(1, "you lose\n", 9);
		free(s->buffer);
		free(s->enemmy_arrays);
		exit(0);
	}
	return (0);
}

void	ft_enemy(t_list *s)
{
	static int	a = 0;

	if (s->times % 10 == 0)
	{
		if (condition(s, s->enemmy_arrays[a], s->enemmy_arrays[a + 1]))
		{
			mlx_put_image_to_window(s->ptr, s->win, s->img_grass,
				s->enemmy_arrays[a], s->enemmy_arrays[a + 1]);
			s->enemmy_arrays[a] += 30;
			mlx_put_image_to_window(s->ptr, s->win, s->img_enemy,
				s->enemmy_arrays[a], s->enemmy_arrays[a + 1]);
		}
		a += 2;
		if (a == (s->num_of_enemmy * 2))
			a = 0;
	}
}

int	animation(t_list *s)
{
	if (s->times == 4000)
	{
		s->img_plyer = mlx_xpm_file_to_image(s->ptr, "p1.xpm", &s->a, &s->b);
		mlx_put_image_to_window(s->ptr, s->win, s->img_plyer, s->xp, s->yp);
	}
	ft_enemy(s);
	if (s->times == 8000)
	{
		s->img_plyer = mlx_xpm_file_to_image(s->ptr, "p2.xpm", &s->a, &s->b);
		mlx_put_image_to_window(s->ptr, s->win, s->img_plyer, s->xp, s->yp);
		s->times = 0;
	}
	s->times++;
	return (0);
}
