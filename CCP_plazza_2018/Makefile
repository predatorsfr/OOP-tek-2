##
## EPITECH PROJECT, 2019
## plazza
## File description:
## Makefile maxime.roux@epitech.eu
##

RM	=	rm -f

SRC	=	main.cpp	\
		init.cpp	\
		check_name.cpp	\
		check_size.cpp	\
		check_nbr.cpp	\
		class.cpp	\
		loop.cpp	\
		fork.cpp	\


INC	=	include

CXX 	=	g++ -lpthread

CXXFLAGS=	-W -Wextra -Wall -I $(INC)

NAME	=	plazza

OBJ	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *~

re: fclean all

.PHONY: all clean fclean re
