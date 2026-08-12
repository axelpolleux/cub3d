PARSER_PATH	=	src/parser

SRC			+=	$(PARSER_PATH)/color.c		\
				$(PARSER_PATH)/file.c		\
				$(PARSER_PATH)/game.c		\
				$(PARSER_PATH)/map.c		\
				$(PARSER_PATH)/parser.c		\
				$(PARSER_PATH)/player.c		\
				$(PARSER_PATH)/texture.c	\
				$(PARSER_PATH)/player.c

OUT_DIRS	+=	$(OUTPUT_DIR)/$(PARSER_PATH)
