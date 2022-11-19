.PHONY	:	all clean fclean re libft

NAME	=	so_long
LIBFT	= 	libft/libft.a
LIBMLX	=	mlx/libmlx.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS	=	srcs/enemy.c		srcs/errors.c	srcs/map_validation.c\
			srcs/moves.c		srcs/parsing.c	srcs/put_images.c\
			srcs/render.c	srcs/start.c		srcs/so_long.c	

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SL 		= 	-framework OpenGL -framework AppKit
RM		= rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		COLORS
#//////////////////////////////////////////////////////////////////////////////

BLUE	=	\033[1;34m
TURQUOISE =	\033[36;1m
END		=	\033[0m

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all		:	$(NAME)

${LIBMLX}:
	@echo "$(BLUE)Compilation of mlx$(END)"
	@make -C mlx/
	@echo "$(TURQUOISE)\n[ Completed mlx ]\n$(END)"

$(NAME)	:	$(OBJS) $(HEADER) ${SRCS} ${HEAD} ${LIBFT} ${LIBMLX}
	@echo "$(BLUE)Compilation of $(NAME)$(END)"
	@$(CC) $(CFLAGS) $(SL) $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)
	@echo "$(TURQUOISE)\n[ Completed $(NAME) ]\n$(END)"

%.o		:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(RM) $(OBJ)
			@make -s -C mlx/ clean
			@rm -f $(OBJS)
			@echo "$(BLUE)\nCleaning done\n$(END)"

fclean	:	clean
			@echo Deleting $(NAME)
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\nDeleting done!\n$(END)"

re:			fclean all
			@echo "$(BLUE)Remake done\n$(END)"