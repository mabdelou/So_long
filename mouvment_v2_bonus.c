/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvment_v2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:53:42 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/17 12:53:44 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solongbonus.h"

void	ft_top_v2(t_list *s)
{
	if (s->buffer[s->num_buf - (s->num_line + 1)] == 'E' && s->cakes == 0)
	{
		write(1, "YOU WIN\n", 8);
		free(s->buffer);
		free(s->enemmy_arrays);
		mlx_destroy_window(s->ptr, s->win);
		exit(0);
	}
	if (s->buffer[s->num_buf - (s->num_line + 1)] == 'Y')
	{
		write(1, "you lose\n", 9);
		free(s->buffer);
		free(s->enemmy_arrays);
		mlx_destroy_window(s->ptr, s->win);
		exit(0);
	}
}

void	ft_down_v2(t_list *s)
{
	if (s->buffer[s->num_buf + (s->num_line + 1)] == 'E' && s->cakes == 0)
	{
		write(1, "YOU WIN\n", 8);
		free(s->buffer);
		free(s->enemmy_arrays);
		mlx_destroy_window(s->ptr, s->win);
		exit(0);
	}
	if (s->buffer[s->num_buf + (s->num_line + 1)] == 'Y')
	{
		write(1, "you lose\n", 9);
		free(s->buffer);
		free(s->enemmy_arrays);
		mlx_destroy_window(s->ptr, s->win);
		exit(0);
	}
}
