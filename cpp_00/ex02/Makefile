NAME=Dreamjob
CC=g++
CFLAGS=-Wall -Wextra -Werror
SRC=tests.cpp Account.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $@ -I .

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

.PHONY: all re clean fclean