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
FILES = main.c \
        mouvment.c \
        check_map.c \
		check_if_map_correct.c \
		ft_get_map_buff.c \
		get_next_line.c \
		fail_on_map.c \
		get_next_line_utils.c \
		ft_itoa.c \
		ft_keys.c \
		ft_print_nb.c \
		ft_printf.c \
		ft_putadresshex.c \
		ft_putchar.c \
		ft_putdownhex.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putuphex.c \
		ft_read_hex.c \
		ft_unsigned_putnbr.c
B_FILES = main_bonus.c \
        mouvment_bonus.c \
        check_map_bonus.c \
		animation_bonus.c \
		check_if_map_correct_bonus.c \
		ft_get_map_buff_bonus.c \
		get_next_line_bonus.c \
		fail_on_map_bonus.c \
		get_next_line_utils_bonus.c \
		ft_itoa_bonus.c \
		ft_keys_bonus.c \
		mouvment_v2_bonus.c

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
