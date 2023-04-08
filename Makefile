# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 01:10:39 by sel-kham          #+#    #+#              #
#    Updated: 2023/04/08 01:38:58 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
RED		:= \033[0;31m
WHITE	:= \033[0;37m
GREEN	:= \033[0;32m
BLUE	:= \033[0;34m

# Helpers Variables
REMOVE	:= rm -rf
_BONUS	:= _bonus

# Flags
CFLAGS		:= -Wall -Wextra -Werror -g
MATH_FLAGS	:= -lm
MLX_EFLAGS	:= -lmlx -framework OpenGL -framework AppKit
MLX_OFLAGS	:= -Imlx

# directories
MANDATORY_DIR	:= mandatory
# MANDATORY_DIR subdirectories
INC_DIR			:= $(MANDATORY_DIR)/includes
APP_DIR			:= $(MANDATORY_DIR)/app
INI_DIR			:= $(MANDATORY_DIR)/ini
HELPERS_DIR		:= $(MANDATORY_DIR)/helpers
PUBLIC_DIR		:= $(MANDATORY_DIR)/public

BONUS_DIR		:= bonus
BUILD_DIR		:= build
# Libs sub directories
LIBS_DIR		:= libs
LIBFT_DIR		:= $(LIBS_DIR)/libft
GNL_DIR			:= $(LIBS_DIR)/get_next_line
## Libs files
LIBFT			:= $(LIBFT_DIR)/libft.a
GNL_HEADER		:= $(GNL_DIR)/get_next_line.h
GNL				:= get_next_line get_next_line_utils
GNL				:= $(addprefix $(GNL_DIR)/, $(addsuffix .c, $(GNL)))
GNL_BUILD 		:= $(addprefix $(BUILD_DIR)/, $(notdir $(GNL:.c=.o)))

# Mandatory files
HEADERS			:= Cub3D datatypes macros
HEADERS			:= $(addprefix $(INC_DIR)/, $(addsuffix .h, $(HEADERS)))
APP				:= entry_point
APP				:= $(addprefix $(APP_DIR)/, $(addsuffix .c, $(APP)))
INI				:= constructors setters init_graphics
INI				:= $(addprefix $(INI_DIR)/, $(addsuffix .c, $(INI)))
HELPERS			:= error_handler string_handler matrix_helpers mlx_helpers
HELPERS			:= $(addprefix $(HELPERS_DIR)/, $(addsuffix .c, $(HELPERS)))
PUBLIC			:= parsing texture_parser map_parser
PUBLIC			:= $(addprefix $(PUBLIC_DIR)/, $(addsuffix .c, $(PUBLIC)))

SRC				:= $(APP) $(INI) $(HELPERS) $(PUBLIC)
BUILD			:= $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))

# MAIN FILES
MAIN			:= $(MANDATORY_DIR)/main.c

NAME 			:= Cub3D

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(MAIN) $(HEADERS) $(LIBFT) $(BUILD) $(GNL_BUILD)
	$(CC) $(CFLAGS) $(MLX_EFLAGS) $(MAIN) $(BUILD) $(GNL_BUILD) $(LIBFT) -o $(NAME)

$(BUILD_DIR)/%.o: $(MANDATORY_DIR)/*/%.c $(GNL_BUILD) $(HEADERS)
	@mkdir -p $(dir $<)
	$(CC) $(CFLAGS) $(MLX_OFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(GNL_DIR)/%.c $(GNL_HEADER)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	$(REMOVE) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR)/ clean

fclean: clean
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_DIR)/ fclean

re: fclean all