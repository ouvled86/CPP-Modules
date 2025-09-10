CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		RPN.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	RPN.hpp

NAME =	RPN

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp $(HPPS)
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
