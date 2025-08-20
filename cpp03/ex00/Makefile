NAME = clapTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) ClapTrap.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re