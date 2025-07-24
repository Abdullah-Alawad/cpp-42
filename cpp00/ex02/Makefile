NAME = GlobalBanksters

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) Account.hpp
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re