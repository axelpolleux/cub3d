NAME		:= cub3D

OUTPUT_DIR	:= build
SRC_DIR		:= src
OUT_DIRS	:= $(OUTPUT_DIR)/$(SRC_DIR)
MLX_DIR		:= lib/MacroLibX

SRC			:= $(SRC_DIR)/main.c

LDFLAGS		:=

INCLUDES	:= includes -I$(MLX_DIR)/includes

include		src/renderer/renderer.make
include		src/init/initialise.make
include		src/action.make
