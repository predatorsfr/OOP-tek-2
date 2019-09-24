##                                                                                                      
## EPITECH PROJECT, 2019                                                                                
## Makefile                                                                                             
## File description:                                                                                    
## rush3                                                                                                
##                                                                                                      

CXX	=	g++ -g

RM	=	rm -f

SRC	=	main.cpp			\

NAME	=	nanotekspice

CXXFLAGS	= -I./include -Wall -Wextra -Werror

OBJS	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
