NAME=megaphone
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=megaphone.cpp
OBJ=${SRC:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all