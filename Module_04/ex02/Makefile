SRCS	=	main.cpp \
			$(wildcard rooms/*cpp) \
			$(wildcard people/*cpp) \
			$(wildcard courses/*cpp) \
			$(wildcard forms/*cpp) 

NAME	=	Hogwarts

OBJ	=	$(SRCS:.cpp=.o)

CXX	=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -DDEBUG_INFO -DDEBUG_ACTION -DDEBUG_DBUG -DDEBUG_WARNING #-g3 -fsanitize=address

all	:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -v $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re