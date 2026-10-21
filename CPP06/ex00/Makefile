NAME = Converter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)  
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test: all
	./$(NAME) 'c'        
	./$(NAME) 'a'        
	./$(NAME) '*'        
	./$(NAME) 0          
	./$(NAME) 42         
	./$(NAME) -42        
	./$(NAME) 2147483647 
	./$(NAME) -2147483648
	./$(NAME) 0.0f       
	./$(NAME) 4.2f       
	./$(NAME) -4.2f      
	./$(NAME) 0.0        
	./$(NAME) 42.0       
	./$(NAME) 42.42      
	./$(NAME) nan
	./$(NAME) nanf
	./$(NAME) +inf
	./$(NAME) -inf
	./$(NAME) +inff
	./$(NAME) -inff
	./$(NAME) 2147483648 
	./$(NAME) hello      
	./$(NAME) 128        
	./$(NAME) 0          

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test