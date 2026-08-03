# For the Makefile


When you add a new folder in the src folder (for the parser for example) you need to add a Makefile with this content (replace PARSER_PATH by what you need)

```
PARSER_PATH = src/parser

SRC += $(PARSER_PATH)/your_file.c

OUT_DIRS += $(OUTPUT_DIR)/$(PARSER_PATH)
```

Then add the following line to the root Makefile before the line who include src/action.make
```
include src/parser/Makefile
```

/!\ You can name your Makefile parser.make or anithing you want with extension .make /!\
