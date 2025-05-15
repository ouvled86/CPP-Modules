CC =	c++

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	tests.cpp \
		Account.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	Account.hpp

NAME =	Logs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp $(HPPS)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all