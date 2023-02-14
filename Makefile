#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

SRC_DIR	= code
OBJ_DIR	= obj
BIN_DIR	= bin
BIN			=	Cub3D 
NAME		= $(BIN_DIR)/$(BIN)
LIBFT		= libft/libft.a
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror 
LMLX		=	-L /usr/X11/lib -lmlx -framework OpenGL -framework  AppKit
# LMLX		= -lmlx -framework OpenGL -framework  AppKit
RM			= rm -rf
PRINTF 	= printf
HEADERS	=	-I ./libft -I ./FT_headers/  -I /usr/X11/include 

SRC =	main.c map2D.c display.c\

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : creat_dir do_libc $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(HEADERS) $(LMLX) -o $(NAME)
		@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."

bonus : all

do_libc : 
	@make all -C libft/

creat_dir :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)


clean :
	@make clean -C libft
	@$(PRINTF) "$(PINK)Cleaning $(NAME) ... $(DEFAULT)\n"
	@$(RM) -r $(OBJ_DIR)
	@$(PRINTF) "$(RED) Objects_files removed successfully. $(DEFAULT)\n"

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(RM) $(LIBFT)
	@$(PRINTF) "$(RED) $(LIBFT) removed successfully. $(DEFAULT)\n";
	@$(PRINTF) "$(RED) $(NAME) removed successfully. $(DEFAULT)\n"
	
re : fclean 
	@make all
