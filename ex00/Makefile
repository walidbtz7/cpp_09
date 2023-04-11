NAME    		=   btc

SRCS    		= 	BitcoinExchange.cpp main.cpp 

CPPFLAGS 		=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

OBJS			=   $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):  $(OBJS)
	c++ $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f ${OBJS}

fclean:    clean
	@rm -f ${NAME}

re: fclean all

.PHONY:		all clean fclean re