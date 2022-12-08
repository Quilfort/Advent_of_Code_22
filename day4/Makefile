# tool macros
CC := clang
COBJFLAGS := $(CFLAGS) -c

GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

# path macros
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src
HDR_PATH := -I include

# compile macros
TARGET_NAME := day_01
TARGET := $(BIN_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))


# clean files list
DISTCLEAN_LIST := $(OBJ) $(BIN_PATH) $(OBJ_PATH) \
CLEAN_LIST := $(TARGET) \
			  $(DISTCLEAN_LIST)

# default rule
default: makedir all
ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

# non-phony targets
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(HDR_PATH) $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CC) $(COBJFLAGS) -o $@ $< $(HDR_PATH)

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

run: default
	@./$(TARGET) $(RUN_ARGS)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: distclean
fclean:
	@echo CLEAN $(DISTCLEAN_LIST)
	@rm -rf $(DISTCLEAN_LIST)

.PHONY: re
re: fclean default
