NAME		:= cub3D

OUTPUT_DIR	:= build
SRC_DIR		:= src
OUT_DIRS	:= $(OUTPUT_DIR)/$(SRC_DIR)
MLX_DIR		:= lib/MacroLibX
LIBFT_DIR	:= lib/libft

SRC			:= $(SRC_DIR)/main.c

LDFLAGS		:=

INCLUDES	:= includes -I$(MLX_DIR)/includes	\
						-I$(LIBFT_DIR)

include		src/parser/parser.make
include		src/action.make
