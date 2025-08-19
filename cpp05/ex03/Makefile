CC =	c++

RM =	rm -f

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Bureaucrat.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \
		AForm.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	Bureaucrat.hpp \
		PresidentialPardonForm.hpp \
		RobotomyRequestForm.hpp \
		ShrubberyCreationForm.hpp \
		Intern.hpp \
		AForm.hpp

NAME =	NotCoffeeMaking

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
