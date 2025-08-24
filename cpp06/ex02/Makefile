CC =	c++

RM =	rm -f

FLAGS =	#-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Base.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	Base.hpp \
		A.hpp \
		B.hpp \
		C.hpp

NAME =	Identity

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
