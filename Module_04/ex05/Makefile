SRCS	=	main.cpp \
			$(wildcard rooms/*cpp) \
			$(wildcard people/*cpp) \
			$(wildcard courses/*cpp) \
			$(wildcard forms/*cpp) \
			$(wildcard bell/*cpp) \
			$(wildcard school/*cpp)


NAME	=	Hogwarts

OBJ	=	$(SRCS:.cpp=.o)

CXX	=	c++

CXXFLAGS	=	-DDEBUG_INFO -DDEBUG_ACTION -DDEBUG_WARNING #-DDEBUG_DBUG #-DDEBUG_CTOR -DDEBUG_DTOR #-g3 -fsanitize=address # -Wall -Werror -Wextra  #-std=c++98 -fsanitize=address

all	:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -v $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re