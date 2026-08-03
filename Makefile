NAME = cub3D

OUTPUT_DIR = build

SRC_DIR = src

OUT_DIRS := $(OUTPUT_DIR)/$(SRC_DIR)

SRC = $(SRC_DIR)/main.c

LDFLAGS =

INCLUDES = includes

include src/action.make
