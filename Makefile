.PHONY : all clean fclean re

#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

SRC_DIR		= code
OBJ_DIR		= obj
BIN_DIR		= bin
BIN			= so_long
NAME		= $(BIN_DIR)/$(BIN)
LIBFT		= libft/libft.a
FT_PRINTF	= printf_dir/ft_printf.a
GNL_DIR		= get_next_line
OBJ_GNL_DIR	= obj_gnl
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
LMLX		= -lmlx -framework OpenGL -framework AppKit
RM			= rm -rf
PRINTF 		= printf


SRC =	main.c check.c mapping.c players_utils.c utils_game.c \
		tileset.c render.c free_file.c window.c  \
		move.c

SRC_GNL = get_next_line.c get_next_line_utils.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_GNL = $(addprefix $(OBJ_GNL_DIR)/, $(SRC_GNL:.c=.o))

all : $(NAME)

$(NAME) : creat_dir do_libc $(OBJ_GNL) $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ_GNL) $(OBJ) $(LIBFT) $(FT_PRINTF) $(LMLX) -o $(NAME)
		@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."

$(OBJ_GNL_DIR)/%.o : $(GNL_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."

bonus : all

do_libc : 
	@make all -C libft/
	@make all -C printf_dir/

creat_dir :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_GNL_DIR)
	@mkdir -p $(BIN_DIR)


clean :
	@make clean -C libft
	@make clean -C printf_dir
	@$(PRINTF) "$(PINK)Cleaning $(NAME) ... $(DEFAULT)\n"
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJ_GNL_DIR)
	@$(PRINTF) "$(RED) Objects_files removed successfully. $(DEFAULT)\n"

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(RM) $(LIBFT)
	@$(RM) $(FT_PRINTF)
	@$(PRINTF) "$(RED) $(FT_PRINTF) removed successfully. $(DEFAULT)\n";
	@$(PRINTF) "$(RED) $(LIBFT) removed successfully. $(DEFAULT)\n";
	@$(PRINTF) "$(RED) $(NAME) removed successfully. $(DEFAULT)\n"
	
re : fclean 
	@make all
