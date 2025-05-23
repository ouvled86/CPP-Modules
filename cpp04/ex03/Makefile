CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	AMateria.hpp \
		Character.hpp \
		Cure.hpp \
		Ice.hpp \
		ICharacter.hpp \
		IMateriaSource.hpp \
		MateriaSource.hpp

NAME = Interfaces

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
