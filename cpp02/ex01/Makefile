NAME = thisIsSomthingNow

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) Fixed.hpp
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re