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
	@$(CC) $(OBJ) $(CFLAGS) -I$(INCLUDES) $(LFLAGS)  $(MLX_DIR)/libmlx.so $(LIBFT_DIR)/libft.a  -lSDL2 -o $@
	@echo "COMPILATION"

$(OUTPUT_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(LFLAGS) -c $< -o $@
	@echo -e "$< to $@\n"

$(OUT_DIRS):
	@mkdir -p $(OUT_DIRS)

all: $(NAME)

macrolibx:
	make -C $(MLX_DIR) -j

libft:
	make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OUTPUT_DIR)
	@echo "CLEAN"

fclean: clean
	@rm -f $(NAME)
	@echo "FCLEAN"

re: fclean all

build: macrolibx libft all

.PHONY: clean macrolibx libft all re build fclean
