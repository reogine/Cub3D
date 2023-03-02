#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

SRC_DIR	= code
SRCS_DIR	= code/parsing
OBJ_DIR	= obj
NAME		=	Cub3D 
LIBFT		= libft/libft.a
LIBMLX	= libmlx/libmlx.a
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror 
# LMLX		=	-L ./libmlx -L /usr/X11/lib -lmlx -framework OpenGL -framework  AppKit
LMLX		= -L $(PWD)/libmlx -lmlx -framework OpenGL -framework  AppKit
RM			= rm -rf
PRINTF 	= printf
HEADERS	=	-I ./libft -I ./FT_headers  -I ./libmlx  -I /usr/X11/include 

SRC =	main.c map2D.c display.c display_utils.c player.c raycasting.c calc_rays.c \
		
SRCS = 	checking_utils.c check_map.c get_next_line.c ft_split.c checking_utils2.c \
		check_textures.c errors.c check_colors.c adjust_colors.c check_keys.c \
		check_map_component.c ft_player_position.c checking_utils3.c draw_walls.c \

OBJ = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJ) $(OBJS) $(LIBFT) $(LIBMLX) 
		@$(CC) $(CFLAGS) -g -fsanitize=address $(OBJ) $(OBJS) $(LIBFT) $(LIBMLX) $(HEADERS) $(LMLX) -o $(NAME)
		@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"

bonus : all

$(LIBFT) : 
	@make all -C libft/

$(LIBMLX) :
	@make all -C libmlx/ &> /dev/null

creat_dir :
	@mkdir -p $(OBJ_DIR)


clean :
	@make clean -C libft
	@make clean -C	libmlx 
	@$(PRINTF) "$(PINK)Cleaning $(LIBFT) ... $(DEFAULT)\n"
	@$(PRINTF) "$(PINK)Cleaning $(LIBMLX) ... $(DEFAULT)\n"
	@$(PRINTF) "$(RED) Objects_files removed successfully. $(DEFAULT)\n"

fclean: clean
	@$(RM) -r $(NAME) 
	@$(RM) $(LIBFT)
	@$(RM) $(LIBMLX)
	@$(PRINTF) "$(RED) $(LIBFT) removed successfully. $(DEFAULT)\n";
	@$(PRINTF) "$(RED) $(NAME) removed successfully. $(DEFAULT)\n"
	
re : fclean 
	@make all
