NAME		:= cub3D

OUTPUT_DIR	:= build
SRC_DIR		:= src
MLX_DIR		:= lib/MacroLibX
LIBFT_DIR	:= lib/libft
GNL_DIR		:= lib/get_next_line
OUT_DIRS	:= $(OUTPUT_DIR)/$(SRC_DIR)	\
				$(OUTPUT_DIR)/$(GNL_DIR)
MLX_SHARE	:= $(MLX_DIR)/libmlx.so
LIBFT_LIB	:= $(LIBFT_DIR)/libft.a

SRC			:= $(SRC_DIR)/main.c				\
				$(GNL_DIR)/get_next_line.c		\
				$(GNL_DIR)/get_next_line_utils.c

LDFLAGS		:= -lm -lSDL2

INCLUDES	:= -Iincludes -I$(MLX_DIR)/includes	\
						-I$(LIBFT_DIR)			\
						-I$(GNL_DIR)


include		src/parser/parser.make
include		src/renderer/renderer.make
include		src/init/init.make
include		src/key/key.make
include		src/utils/utils.make

include		src/action.make
