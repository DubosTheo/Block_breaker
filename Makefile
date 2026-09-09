##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC := g++

SRC += src/Blockbreaker/Blockbreaker.cpp
SRC += src/Blockbreaker/Game/Game.cpp
SRC += src/Blockbreaker/Game/Racket.cpp
SRC += src/Blockbreaker/SceneManager.cpp

SRC_MAIN = src/main.cpp

SRC_TEST =

OBJDIR = obj

OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJ_MAIN = $(SRC_MAIN:%.cpp=$(OBJDIR)/%.o)

NAME = Blockbreaker

INCLUDE = -Isrc

CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++20

CFLAGS_DEBUGS = -fanalyzer -g

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ_MAIN) $(OBJ) $(INCLUDE) $(SFML_FLAGS) $(CXXFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gc*

re: fclean all

debug:
	make re CXXFLAGS+="$(CFLAGS_DEBUGS)"

tests_run: fclean
	$(CC) -o unit_tests $(SRC_TEST) $(SRC) --coverage -lcriterion $(INCLUDE) $(SFML_FLAGS) $(CXXFLAGS)
	./unit_tests
