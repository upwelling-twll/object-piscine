SRCS	=	main.cpp \
			$(wildcard src/*cpp) 


NAME	=	Railway

OBJ	=	$(SRCS:.cpp=.o)

CXX	=	c++

CXXFLAGS	=	-DDEBUG_INFO -DDEBUG_ACTION -DDEBUG_WARNING #-DDEBUG_DBUG #-DDEBUG_CTOR -DDEBUG_DTOR #-g3 -fsanitize=address # -Wall -Werror -Wextra 

all	:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -v $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re