CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		BitcoinExchange.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	BitcoinExchange.hpp

NAME =	btc

DATA = data.csv

all: $(DATA) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp $(HPPS)
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
