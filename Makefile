##
## EPITECH PROJECT, 2024
## minishell-v1 [WSL: Ubuntu]
## File description:
## Makefile
##

SRC = ./src/external.c \
	./src/shell.c \
	./src/command.c \
	./src/error.c \
	./src/env.c \
	./src/handlers.c \
	./src/Builtins/exit.c \
	./src/Builtins/cd.c \
	./src/Builtins/setenv.c \
	./src/Builtins/showenv.c \
	./src/Builtins/unsetenv.c
SRC_TEST = ./tests/test_external.c
MAIN = ./src/main.c

CFLAGS = -Wall -Wextra -I. -I./src/ -L . -lmy
LIB_PATH = ./lib/my

NAME_TEST = unit_tests
NAME = mysh

all: $(NAME)

build_lib:
	make -C $(LIB_PATH)

clean_lib:
	make clean -C $(LIB_PATH)

fclean_lib:
	make fclean -C $(LIB_PATH)

$(NAME): build_lib
	$(CC) $(MAIN) $(SRC) $(CFLAGS) -o $(NAME)

clean: clean_lib
	rm -f $(NAME)

fclean: clean fclean_lib tests_clean

re: fclean all

tests_run: build_lib
	$(CC) $(SRC) $(SRC_TEST) $(CFLAGS) -o $(NAME_TEST) --coverage -lcriterion
	./$(NAME_TEST)

tests_clean:
	rm -f $(NAME_TEST)
	rm -f *.gcno
	rm -f *.gcda

.PHONY: all build_lib clean_lib fclean_lib clean fclean re tests_run \
	tests_clean
