CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

HPPS =	HumanA.hpp \
		HumanB.hpp \
		Weapon.hpp

OBJS =	$(SRCS:.cpp=.o)

NAME =	Violence

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
