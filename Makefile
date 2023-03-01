#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

SRC_DIR	= code
OBJ_DIR	= obj
NAME		=	Cub3D 
LIBFT		= libft/libft.a
LIBMLX	= libmlx/libmlx.dylib
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror 
LMLX		=	-L ./libmlx -L /usr/X11/lib -lmlx -framework OpenGL -framework  AppKit
# LMLX		= -L $(PWD)/libmlx -lmlx -framework OpenGL -framework  AppKit
RM			= rm -rf
PRINTF 	= printf
HEADERS	=	-I ./libft -I ./FT_headers  -I ./libmlx  -I /usr/X11/include 

SRC =	main.c map2D.c display.c\

OBJ = $(addprefix $(SRC_DIR)/, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(LIBMLX) 
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(HEADERS) $(LMLX) -o $(NAME)
		@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"

bonus : all

$(LIBFT) : 
	@make all -C libft/

$(LIBMLX) :
	@make all -C libmlx/

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
