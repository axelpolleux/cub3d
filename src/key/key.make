KEY_PATH = src/key

SRC +=	$(KEY_PATH)/key_hook.c	\
		$(KEY_PATH)/key_move.c	\
		$(KEY_PATH)/key_rot.c	\
		$(KEY_PATH)/key_escape.c

OUT_DIRS += $(OUTPUT_DIR)/$(KEY_PATH)
