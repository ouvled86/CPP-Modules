CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \
		ScavTrap.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	ClapTrap.hpp \
		FragTrap.hpp \
		DiamondTrap.hpp \
		ScavTrap.hpp

NAME =	DiamondTrap

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
