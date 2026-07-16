# Name of executable
NAME = Weapon

# Compilation flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources
SRCS = HumanA.hpp HumanB.cpp HumanB.hpp main.cpp Makefile Weapon.cpp Weapon.hpp

OBJS = $(SRCS:.cpp=.o)

# Main rule
all: $(NAME)

# Executablee compilation
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re