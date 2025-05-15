CC =	c++

FLAGS =	-Wall -Wextra -Werror -std=c++98

SRC =	megaphone.cpp

OBJ =	$(SRC:.cpp=.o)

NAME =	megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $< -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all