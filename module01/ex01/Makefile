CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombiehorde

SRCS = main.cpp \
		Zombie.cpp \
		ZombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean re all