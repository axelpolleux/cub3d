NAME		:= cub3D

OUTPUT_DIR	:= build
SRC_DIR		:= src
OUT_DIRS	:= $(OUTPUT_DIR)/$(SRC_DIR)
MLX_DIR		:= lib/MacroLibX
LIBFT_DIR	:= lib/libft

MLX_SHARE	:= $(MLX_DIR)/libmlx.so
LIBFT_LIB	:= $(LIBFT_DIR)/libft.a

SRC			:= $(SRC_DIR)/main.c

LDFLAGS		:= -lm

INCLUDES	:= -Iincludes -I$(MLX_DIR)/includes -I$(LIBFT_DIR)

include		src/renderer/renderer.make
include		src/init/initialise.make
include		src/key/key.make

include		src/action.make
