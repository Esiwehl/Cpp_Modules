NAME = harl
HEADER_FILES = Harl.hpp
SRC_FILES = main.cpp Harl.cpp
OBJ_FILES = $(SRC_FILES:%.cpp=obj/%.o)
HEADERS = $(HEADER_FILES:%=%)
OBJ_DIR = obj
RM = rm -Rf

CC = c++
INCLUDES = -I .
CFLAGS = -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(INCLUDES) $(CFLAGS) -o $@ $(OBJ_FILES)
	@echo "${GREEN}Created program: $@${END}"

obj/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "${RED}Deleting ${OBJ_DIR}${END}"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "${RED}Deleting ${NAME} ${END}"
	@$(RM) $(NAME)

debug:
	@$(MAKE) DEBUG=1 all

re: all clean fclean debug

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
PURPLE=\033[1;35m
CYAN=\033[1;36m
END=\033[0m
