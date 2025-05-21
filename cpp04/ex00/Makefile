CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Animal.cpp \
		WrongAnimal.cpp \
		Cat.cpp \
		WrongCat.cpp \
		Dog.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	Animal.hpp \
		WrongAnimal.hpp \
		Cat.hpp \
		WrongCat.hpp \
		Dog.hpp

NAME =	Animals

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
