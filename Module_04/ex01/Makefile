SRCS	=	main.cpp \
			$(wildcard rooms/*cpp) \
			$(wildcard people/*cpp) \
			$(wildcard courses/*cpp) 

NAME	=	Hogwarts

OBJ	=	$(SRCS:.cpp=.o)

CXX	=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -DDEBUG_INFO -fsanitize=address

all	:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -v $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re