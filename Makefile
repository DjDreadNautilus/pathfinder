CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
INCLUDE := -I./inc

LIBMX := libmx/libmx.a
PATHFINDER := pathfinder

SRC_DIR := ./src
OBJ_DIR := ./obj

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(LIBMX) $(PATHFINDER)

$(PATHFINDER): $(OBJ) $(LIBMX)
	$(CC) $(CFLAGS) -o $(PATHFINDER) $(OBJ) -L./libmx -lmx

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./inc/pathfinder.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBMX):
	$(MAKE) -C libmx

clean:
	rm -rf $(OBJ_DIR)/*.o $(PATHFINDER)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libmx clean

cleanall: clean
	$(MAKE) -C libmx clean
	rm -rf $(LIBMX) $(PATHFINDER)

uninstall: clean

reinstall: uninstall all