
# Dadivaldo 01-04-2026

__dummy = $(shell mkdir -p build/exec build/obj)
NAME= build/exec/task-cli
SRC = $(wildcard source/*.cpp)
OBJS= $(patsubst source/%.o, build/obj/%.o, $(patsubst %.cpp, %.o, $(SRC) ) )
HEADERS= header/task_cli.hpp

CXX=g++
CXXFLAGS= -std=c++11 -g -Wall -Wextra -Werror -I header


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 


build/obj/%.o: source/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 


$(OBJS): $(HEADERS)


clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

