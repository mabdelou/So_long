/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_correct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:10:09 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/10 18:10:12 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_path_of_map(char *path, int argc)
{
	int		a;
	bool	error_path;

	if (argc == 1 || argc >= 3)
	{
		write(2, "Error\nenter correct name of map wana play!\n", 39);
		exit(0);
	}
	a = 0;
	error_path = false;
	while (path[a] != '\0')
		a++;
	if (a >= 4)
	{
		if (path[a - 1] != 'r' || path[a - 2] != 'e'
			|| path[a - 3] != 'b' || path[a - 4] != '.')
			error_path = true;
	}
	else
		error_path = true;
	if (error_path == true)
	{
		write(2, "Error\nenter correct name of map wana play!\n", 39);
		exit(0);
	}
}

int	ft_check_mapv7(t_list *s)
{
	int		words_of_map;
	bool	other_char;
	int		a;

	a = -1;
	words_of_map = (s->num_line + 1) * ((s->words + 1) / (s->num_line + 1));
	other_char = false;
	while (s->buffer[++a] != '\0')
	{
		if (s->buffer[a] != 'E' && s->buffer[a] != '0' && s->buffer[a] != 'P'
			&& s->buffer[a] != '1' && s->buffer[a] != 'C'
			&& s->buffer[a] != '\n' && s->buffer[a] != '\0')
			other_char = true;
	}
	if (words_of_map == (s->words + 1) && other_char == false)
		return (0);
	return (1);
}

int	ft_check_mapv6(t_list *s)
{
	int	player;
	int	cake;
	int	port;
	int	a;

	a = -1;
	player = 0;
	cake = 0;
	port = 0;
	while (s->buffer[++a] != '\0')
	{
		if (s->buffer[a] == 'C')
			cake++;
		else if (s->buffer[a] == 'P')
			player++;
		else if (s->buffer[a] == 'E')
			port++;
	}
	if (cake > 0 && player == 1 && port >= 1)
		return (0);
	return (1);
}
