/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:59:07 by mabdelou          #+#    #+#             */
/*   Updated: 2021/12/23 20:59:12 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/solongbonus.h"

void	check_mapv2(t_list *s, char *file, int fd)
{
	int	i;

	s->x = 0;
	s->y = 0;
	s->a = 30;
	s->b = 30;
	s->words = 0;
	ft_get_map_buff(s, file, fd);
	if (s->words == -1 || s->words == 0)
		return ;
	s->buffer[s->words] = '\0';
	s->num_line = 0;
	while (s->buffer[s->num_line] != '\n')
		s->num_line++ ;
	i = s->b * ((s->words - 1) / s->num_line);
	s->win = mlx_new_window(s->ptr, s->a * s->num_line, i, "first game^^");
	s->img_wall = mlx_xpm_file_to_image(s->ptr, "../img/bedrock.xpm", &s->a, &s->b);
	s->img_grass = mlx_xpm_file_to_image(s->ptr, "../img/dirt.xpm", &s->a, &s->b);
	s->img_cake = mlx_xpm_file_to_image(s->ptr, "../img/cake.xpm", &s->a, &s->b);
	s->img_portal = mlx_xpm_file_to_image(s->ptr, "../img/portal.xpm", &s->a, &s->b);
	s->img_plyer = mlx_xpm_file_to_image(s->ptr, "../img/player.xpm", &s->a, &s->b);
	s->img_enemy = mlx_xpm_file_to_image(s->ptr, "../img/enemy.xpm", &s->a, &s->b);
}

void	check_mapv3(t_list *s)
{
	if (s->buffer[s->words] == '1')
		mlx_put_image_to_window(s->ptr, s->win, s->img_wall, s->x, s->y);
	else if (s->buffer[s->words] == '0')
		mlx_put_image_to_window(s->ptr, s->win, s->img_grass, s->x, s->y);
	else if (s->buffer[s->words] == 'C')
	{
		mlx_put_image_to_window(s->ptr, s->win, s->img_cake, s->x, s->y);
		s->cakes++;
	}
	else if (s->buffer[s->words] == 'P' )
	{
		s->num_buf = s->words;
		mlx_put_image_to_window(s->ptr, s->win, s->img_plyer, s->x, s->y);
		s->xp = s->x;
		s->yp = s->y;
	}
	else if (s->buffer[s->words] == 'E')
		mlx_put_image_to_window(s->ptr, s->win, s->img_portal, s->x, s->y);
	else if (s->buffer[s->words] == '\n' )
	{
		s->x = -30;
		s->y += 30;
	}
}

void	check_mapv4(t_list *s)
{
	int static	c = -1;
	int			a;

	a = -1;
	if (c == -1)
	{
		s->enemmy_arrays = malloc(sizeof(int) * (2 * s->num_of_enemmy));
		while (++a < (s->num_of_enemmy * 2))
			s->enemmy_arrays[a] = 0;
	}
	if (s->buffer[s->words] == 'Y')
	{
		mlx_put_image_to_window(s->ptr, s->win, s->img_enemy, s->x, s->y);
		s->enemmy_arrays[s->pos++] = s->x;
		s->enemmy_arrays[s->pos++] = s->y;
	}
	c++;
}

void	check_mapv5(t_list *s)
{
	static int	a = -1;
	static int	fail = 0;

	while (s->buffer[++a] != '\n')
		if (s->buffer[a] != '1')
			fail = 1;
	while (s->buffer[a] != '\0')
	{
		if (s->buffer[a] == '\n' && s->buffer[a - 1] != '1')
			fail = 1;
		if (s->buffer[a] == '\n' && a < s->words - s->num_line)
			if (s->buffer[a + 1] != '1')
				fail = 1;
		a++;
	}
	while (s->buffer[--a] != '\n')
		if (s->buffer[a] != '1')
			fail = 1;
	ft_fail_on_map(s, fail);
}

int	check_map(t_list *src, char *file, int fd)
{
	check_mapv2(src, file, fd);
	if (!src->img_wall || !src->img_grass || !src->img_cake
		|| !src->img_portal || !src->img_plyer || !src->img_enemy)
	{
		write(1, "Error\nwrong on pic_file\n", 23);
		free(src->buffer);
		exit(0);
	}
	src->words = 0;
	src->cakes = 0;
	while (src->buffer[src->words] != '\0')
	{
		check_mapv3(src);
		check_mapv4(src);
		src->x += 30;
		src->words++;
	}
	check_mapv5(src);
	src->points = 0;
	return (1);
}
