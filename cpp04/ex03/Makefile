CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		AAnimal.cpp \
		Brain.cpp \
		WrongAnimal.cpp \
		Cat.cpp \
		WrongCat.cpp \
		Dog.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	AAnimal.hpp \
		Brain.hpp \
		WrongAnimal.hpp \
		Cat.hpp \
		WrongCat.hpp \
		Dog.hpp

NAME = AClass

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
