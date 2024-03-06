NAME=brainz
CC=c++
CFLAGS=-Wall -Wextra -Werror
SRC=main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ=${SRC:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

.PHONY: all re clean fclean