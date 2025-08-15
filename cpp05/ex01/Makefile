CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	Bureaucrat.hpp \
		Form.hpp

NAME =	FormUpMaggots

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
