# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 01:10:39 by sel-kham          #+#    #+#              #
#    Updated: 2023/03/30 01:13:09 by sel-kham         ###   ########.fr        #
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
CFLAGS		:= -Wall -Wextra -Werror -g -fsanitize=address
MATH_FLAGS	:= -lm
MLX_EFLAGS	:= -lmlx -framework OpenGL -framework AppKit
MLX_OFLAGS	:= -Imlx

# Parent directories
MANDATORY_DIR	:= mandatory
BONUS_DIR		:= bonus
BUILD_DIR		:= build
LIBS_DIR		:= libs