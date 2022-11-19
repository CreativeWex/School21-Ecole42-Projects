.PHONY	:	all clean fclean re

NAME			= harlFilter

SRCS			= main.cpp Harl.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= #-Wall -Wextra -Werror -std=c++98

BLUE	=	\033[1;34m
TURQUOISE =	\033[36;1m
END		=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
				@echo "$(TURQUOISE)\n[ Completed $(NAME) ]\n$(END)"

clean:   
				@$(RM) $(OBJS)
				@echo "$(BLUE)\nCleaning done\n$(END)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(BLUE)\n fclean done!\n$(END)"

re:				fclean $(NAME)
				@echo "$(BLUE)Remake done\n$(END)"