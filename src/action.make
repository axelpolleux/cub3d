CC := cc

ifdef SANIT
	DEBUG=1
endif
ifdef DEBUG
	CFLAGS += -g -Wall -Wextra -DDEBUG=yes
else
	CFLAGS := -Wall -Wextra -Werror
endif
ifdef SANIT
	CFLAGS += -fsanitize=address -fsanitize=leak -O1 -MMD -MP
endif

OBJ = $(SRC:%.c=$(OUTPUT_DIR)/%.o)

$(NAME): $(OUT_DIRS) $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.so -lSDL2 -o $@
	@echo "COMPILATION"

$(OUTPUT_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo -e "$< to $@\n"

$(OUT_DIRS):
	@mkdir -p $(OUT_DIRS)

all: $(NAME)

macrolibx:
	make -C $(MLX_DIR) -j

macrolibx:
	make -C $(LIBFT_DIR) -j

clean:
	@rm -rf $(OUTPUT_DIR)
	@echo "CLEAN"

fclean: clean
	@rm -f $(NAME)
	@echo "FCLEAN"

re: fclean all

build: macrolibx all

.PHONY: clean macrolibx all re build fclean
