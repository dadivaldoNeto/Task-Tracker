
# Dadivaldo 01-04-2026

NAME= build/exec/task-cli
SRC = $(wildcard source/*.cpp)
OBJS= $(patsubst source/%.o, build/obj/%.o, $(patsubst %.cpp, %.o, $(SRC) ) )
HEADERS= $(wildcard header/*.hpp)

CXX=g++
CXXFLAGS= -std=c++11 -g -Wall -Wextra -Werror -I header


all: $(NAME) | folder

$(NAME): $(OBJS) | folder
	$(CXX) $(CXXFLAGS) $^ -o $@


folder:
	@mkdir -p build/exec build/obj && mkdir -p db

build/obj/%.o: source/%.cpp | folder
	$(CXX) $(CXXFLAGS) -c $< -o $@ 


$(OBJS): $(HEADERS)


clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

