RENDERER_PATH = src/renderer

SRC +=	$(RENDERER_PATH)/launch_ray.c		\
		$(RENDERER_PATH)/launch_one_ray.c	\
		$(RENDERER_PATH)/draw_column.c

OUT_DIRS += $(OUTPUT_DIR)/$(RENDERER_PATH)
