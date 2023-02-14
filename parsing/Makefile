# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aomman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 21:53:24 by aomman            #+#    #+#              #
#    Updated: 2023/02/04 21:53:25 by aomman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = main.c checking_utils.c check_map.c get_next_line.c ft_split.c checking_utils2.c\
		check_textures.c errors.c check_colors.c adjust_colors.c check_keys.c

all : ${NAME}

${NAME} : ${SRC}
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 -lmlx -framework OpenGL -framework AppKit ${SRC} -o ${NAME}

clean :
	rm -f ${NAME}

fclean : clean

re : fclean all
