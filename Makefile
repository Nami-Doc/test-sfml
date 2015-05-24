CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -std=c++1z

LIBS	= -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = test-sfml

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LIBS) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: clean fclean test
