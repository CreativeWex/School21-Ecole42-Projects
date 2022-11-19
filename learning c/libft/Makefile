
NAME	=	libft.a

SRCS	=	ft_isalpha.c	ft_memcpy.c	ft_tolower.c	ft_bzero.c\
		ft_isascii.c	ft_memmove.c	ft_strncmp.c	ft_toupper.c\
		ft_isdigit.c	ft_memset.c	ft_isalnum.c	ft_isprint.c\
		ft_strlen.c	ft_strlcpy.c	ft_strrchr.c	ft_strchr.c\
		ft_memchr.c	ft_putstr_fd.c	ft_putchar_fd.c	ft_putendl_fd.c\
		ft_strdup.c	ft_strmapi.c	ft_calloc.c	ft_memcmp.c\
		ft_atoi.c	ft_strlcat.c	ft_strnstr.c	ft_putnbr_fd.c\
		ft_substr.c	ft_striteri.c	ft_strjoin.c	ft_strtrim.c\
		ft_itoa.c	ft_split.c	
		


SRCS_B	=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstadd_back.c\
		ft_lstadd_back.c	ft_lstlast.c		ft_lstdelone.c	ft_lstiter.c\
		ft_lstmap.c		ft_lstclear.c
				

HEADER  =	libft.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))
 
OBJ_B	=	$(SRCS_B:%.c=%.o)
 
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)
 
.PHONY	:	all clean fclean re bonus
 
all		:	$(NAME)
 
$(NAME)	:	$(OBJ) $(HEADER)
		ar rcs $(NAME) $?
 
 
%.o		:	%.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@
#??
 
bonus	:
		make OBJ="$(OBJ_B)" all
 
clean	:
		rm -f $(OBJ) $(OBJ_B)
 
fclean	:	clean
		$(RM) $(NAME)
 
re		:	fclean all
 