/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:33:56 by mabdelou          #+#    #+#             */
/*   Updated: 2021/12/23 21:34:28 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	char	*buffer;
	char	*map;
	void	*ptr;
	void	*win;
	void	*img_wall;
	void	*img_grass;
	void	*img_cake;
	void	*img_plyer;
	void	*img_portal;
	void	*img_enemy;
	int		x;
	int		y;
	int		a;
	int		b;
	int		num_buf;
	int		xp;
	int		yp;
	int		cakes;
	int		points;
	int		num_line;
	int		words;
	int		mv;
	int		times;
	int		*enemmy_arrays;
	int		*enemmy_buf_pos;
	int		num_of_enemmy;
	int		pos;
}t_list;

void	ft_right(t_list *src);
void	ft_left(t_list *src);
void	ft_down(t_list *src);
void	ft_top(t_list *src);
char	*ft_itoa(int n);
int		check_map(t_list *src, char *file, int fd);
int		animation(t_list *s);
int		ft_check_mapv6(t_list *s);
int		ft_check_mapv7(t_list *s);
void	ft_check_path_of_map(char *path, int argc);
void	ft_get_map_buff(t_list *s, char *file, int fd);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		return_trorfo(char *str);
void	ft_fail_on_map(t_list *s, int fail);
char	*ft_strjoin(char *s1, char*s2);
void	ft_key_one(int keycode, t_list *s);
void	ft_key_tow(int keycode, t_list *s);
void	ft_key_three(int keycode, t_list *s);
void	ft_key_four(int keycode, t_list *s);

#endif
