/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libirary.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:54:48 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/29 15:55:33 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char	*str);
int		ft_unsigned_putnbr(unsigned int nb);
int		ft_putdownhex(unsigned int base);
int		ft_putadresshex(unsigned long int base);
int		ft_putuphex(unsigned int base);
int		ft_read_hex(unsigned long int nb);
int		ft_print_nb(long nb);

#endif
