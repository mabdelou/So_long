/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:11:31 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/12 02:11:33 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/solongbonus.h"

void	ft_fail_on_map(t_list *s, int fail)
{
	if (fail == 1 || ft_check_mapv6(s) || ft_check_mapv7(s))
	{
		write(1, "Error\nyour map isent corecct\n", 28);
		free(s->buffer);
		free(s->enemmy_arrays);
		exit(0);
	}
}
