# UTILITIES
CC = gcc
LEAKS =# leaks -atExit --
RM = rm -rf

# FILENAMES
SRC_DIR = ./src/
SRC = $(wildcard $(SRC_DIR)*.c)

tmp:
#	gcc structures.c $(SRC_DIR)*.c
	gcc parsing_test.c $(SRC_DIR)*.c
	$(LEAKS) ./a.out
	$(RM) a.out


# SERVICES
style:
	clang-format --style=google -n *.h *.c $(SRC)

gost:
	clang-format --style=google -i *.h *.c $(SRC)

clean:
	$(RM) a.out
