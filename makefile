NAME = exe

CXX_SRC =\
	main.cpp \
	Randomizer.cpp \
	version.cpp

C_SRC =

CXX = g++
LL = g++
CC = gcc
CXX_FLAGS = -std=c++17 -Wall -Wextra -MMD -MF $(patsubst %.o,%.d,$@)
CXX_FLAGS += -DPROGRAM_VERSION="$(shell git describe)"
CC_FLAGS = -Wall -Wextra
LD_FLAGS =
DBG_FLAGS = -ggdb -DDEBUG=8
INCLUDE =
LIBS =
SRC_DIR = src
OBJ_DIR = obj

_OBJ := $(CXX_SRC:%.cpp=%.o)
_OBJ += $(C_SRC:%.c=%.o)
OBJ = $(_OBJ:%=$(OBJ_DIR)/%)

DEPS := $(OBJ:%.o=%.d)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@echo "LL $@"
	@$(LL) -o $@ $(OBJ) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp makefile
	@echo "CXX $< -> $@"
	@$(CXX) $(INCLUDE) $(DBG_FLAGS) $(CXX_FLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c makefile
	@echo "CC $< -> $@"
	@$(CC) $(INCLUDE) $(DBG_FLAGS) $(CC_FLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	@rm -vrf $(OBJ_DIR)
	@rm -vf $(NAME)

.PHONY: ctags
ctags:
	ctags --fields=* --extras=* --extras-c++=* -R $(SRC_DIR)/*

-include $(DEPS)

# RELEASE ----------------------------------------------------------------------
release:
	@echo "Release is not configured yet."
