# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aomman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 21:53:24 by aomman            #+#    #+#              #
#    Updated: 2023/02/25 15:15:20 by aomman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parsing
SRC = main.c 

all : ${NAME}

${NAME} : ${SRC}
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 -lmlx -framework OpenGL -framework AppKit ${SRC} -o ${NAME}

clean :
	rm -f ${NAME}

fclean : clean

re : fclean all
