/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:13:24 by mabdelou          #+#    #+#             */
/*   Updated: 2021/12/23 21:13:43 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	mlx_ft(int keycode, t_list *s)
{
	ft_key_one(keycode, s);
	ft_key_tow(keycode, s);
	ft_key_three(keycode, s);
	ft_key_four(keycode, s);
	return (0);
}

int	ft_test(t_list *src)
{
	write(1, "Error\nprograme exited sucsfull\n", 30);
	free(src->buffer);
	free(src->enemmy_arrays);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	src;
	int		fd;

	ft_check_path_of_map(argv[1], argc);
	src.mv = 0;
	src.times = 0;
	src.num_of_enemmy = 0;
	src.pos = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		write(1, "Error\nwrong on map file\n", 23);
		close(fd);
		exit(0);
	}
	src.ptr = mlx_init();
	check_map(&src, argv[1], fd);
	mlx_key_hook(src.win, mlx_ft, &src);
	mlx_hook(src.win, 17, 0L, ft_test, &src);
	mlx_loop(src.ptr);
	return (0);
}
