CC =	c++

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Contact.class.cpp \
		PhoneBook.class.cpp \
		PhoneBook.utils.cpp

OBJS =	$(SRCS:.cpp=.o)

HPPS =	PhoneBook.class.hpp \
		Contact.class.hpp

NAME =	PhoneBook

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