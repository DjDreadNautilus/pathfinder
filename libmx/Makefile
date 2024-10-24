CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic

LIBMX := libmx.a

SRC := $(wildcard ./src/*.c)
OBJ := $(patsubst ./src/%.c, ./obj/%.o, $(SRC))

all: $(LIBMX)

$(LIBMX): $(OBJ)
	ar -rcs $(LIBMX) $(OBJ)

./obj/%.o: ./src/%.c
	mkdir -p ./obj
	$(CC) $(CFLAGS) -I./inc -c $< -o $@

clean:
	rm -rf $(LIBMX)
	rm -rf ./obj
	
uninstall: clean

reinstall: uninstall all