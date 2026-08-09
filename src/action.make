CC := cc

ifdef SANIT
	DEBUG=1
endif
ifdef DEBUG
	CFLAGS += -g -Wall -Wextra -DDEBUG=yes -O3
else
	CFLAGS := -Wall -Wextra -Werror
endif
ifdef SANIT
	CFLAGS += -fsanitize=address -fsanitize=leak -O1 -MMD -MP
endif

OBJ = $(SRC:%.c=$(OUTPUT_DIR)/%.o)

$(NAME): $(OUT_DIRS) $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(LIBFT_LIB) $(MLX_SHARE) -lSDL2 -o $@
	@echo "COMPILATION"

$(OUTPUT_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo -e "$< to $@\n"

$(OUT_DIRS):
	@mkdir -p $(OUT_DIRS)

$(MLX_SHARE):
	make -C $(MLX_DIR) -j

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

all: $(LIBFT_LIB) $(MLX_SHARE) $(NAME)

clean:
	@rm -rf $(OUTPUT_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	@echo "CLEAN"

fclean: clean
	@rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)
	@echo "FCLEAN"

re: fclean all

.PHONY: clean macrolibx all re build fclean
