/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:03:12 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/12 02:03:14 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check_first_line(t_list *s)
{
	if (s->buffer[0] == '\n')
	{
		write(1, "Error\nyour map isent corecct\n", 28);
		free(s->buffer);
		free(s->enemmy_arrays);
		exit(0);
	}
}

void	ft_get_map_buff(t_list *s, char *file, int fd)
{
	int	a;
	int	buff;

	buff = 0;
	while (s->buffer != NULL)
	{
		s->buffer = get_next_line(fd);
		a = -1;
		if (s->buffer == NULL)
			break ;
		while (s->buffer[++a] != '\0')
		{
			if (s->buffer[a] == 'Y')
				s->num_of_enemmy++;
		}
		buff += a;
		free(s->buffer);
	}
	close(fd);
	fd = open(file, O_RDWR);
	s->buffer = malloc(sizeof(char) * buff);
	s->words = read(fd, s->buffer, buff);
	ft_check_first_line(s);
}
