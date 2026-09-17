##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CXX := g++

SRC += src/Blockbreaker/Blockbreaker.cpp
SRC += src/Blockbreaker/SceneManager.cpp
SRC += src/Blockbreaker/Game/Aobject.cpp
SRC += src/Blockbreaker/Game/Game.cpp
SRC += src/Blockbreaker/Game/Ball.cpp
SRC += src/Blockbreaker/Game/Racket.cpp
SRC += src/Blockbreaker/Game/Brick.cpp

SRC_MAIN = src/main.cpp

SRC_TEST =

OBJDIR = obj

OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJ_MAIN = $(SRC_MAIN:%.cpp=$(OBJDIR)/%.o)

NAME = blockbreaker

INCLUDE = -Isrc -I/usr/local/include

CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++20

CFLAGS_DEBUGS = -fanalyzer -g

SFML_FLAGS = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_MAIN) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^ $(SFML_FLAGS)

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
	$(CXX) -o unit_tests $(SRC_TEST) $(SRC) --coverage -lcriterion $(INCLUDE) $(CXXFLAGS) $(SFML_FLAGS)
	./unit_tests
