# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 16:04:07 by mabdelou          #+#    #+#              #
#    Updated: 2021/11/15 23:53:38 by mabdelou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Werror -Wextra
GFLAGS = -lmlx -framework OpenGl -framework Appkit
RM = rm -f
NAME = so_long
FILES = so_long_mondatory/main.c \
        so_long_mondatory/mouvment.c \
        so_long_mondatory/check_map.c \
		so_long_mondatory/check_if_map_correct.c \
		so_long_mondatory/ft_get_map_buff.c \
		so_long_mondatory/get_next_line.c \
		so_long_mondatory/fail_on_map.c \
		so_long_mondatory/get_next_line_utils.c \
		so_long_mondatory/ft_itoa.c \
		so_long_mondatory/ft_keys.c \
		so_long_mondatory/ft_print_nb.c \
		so_long_mondatory/ft_printf.c \
		so_long_mondatory/ft_putadresshex.c \
		so_long_mondatory/ft_putchar.c \
		so_long_mondatory/ft_putdownhex.c \
		so_long_mondatory/ft_putnbr.c \
		so_long_mondatory/ft_putstr.c \
		so_long_mondatory/ft_putuphex.c \
		so_long_mondatory/ft_read_hex.c \
		so_long_mondatory/ft_unsigned_putnbr.c
B_FILES = so_long_bonus/main_bonus.c \
        so_long_bonus/mouvment_bonus.c \
        so_long_bonus/check_map_bonus.c \
		so_long_bonus/animation_bonus.c \
		so_long_bonus/check_if_map_correct_bonus.c \
		so_long_bonus/ft_get_map_buff_bonus.c \
		so_long_bonus/get_next_line_bonus.c \
		so_long_bonus/fail_on_map_bonus.c \
		so_long_bonus/get_next_line_utils_bonus.c \
		so_long_bonus/ft_itoa_bonus.c \
		so_long_bonus/ft_keys_bonus.c \
		so_long_bonus/mouvment_v2_bonus.c

all:  $(NAME)

$(NAME): $(FILES)
	$(CC) $(FILES) -lmlx -framework OpenGl -framework Appkit -o $(NAME)
	
bonus: $(B_FILES)
	$(CC) $(B_FILES) -lmlx -framework OpenGl -framework Appkit -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
