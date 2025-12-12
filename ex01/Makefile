CPP = c++ -std=c++98
FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
NAME = PhoneBook
HEADER = Contact.hpp PhoneBook.hpp Book.hpp
SRC = main.cpp Contact.cpp PhoneBook.cpp Utils.cpp ValidateContact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $^ -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: clean