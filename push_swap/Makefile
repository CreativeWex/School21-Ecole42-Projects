NAME	=	push_swap

NAME_B	=	checker

SRCS	=	srcs/push_swap.c				srcs/data_initialisation.c 		srcs/parsing_and_validation.c\
			srcs/stack_base_operations.c 	srcs/median_operations.c 		cmd/cmd_pa_pb.c\
			cmd/cmd_ra_rb_rr.c				cmd/cmd_rra_rrb_rrr.c			srcs/small_group_sorting.c\
			cmd/cmd_sa_sb_ss.c				srcs/big_group_sorting.c		srcs/big_group_second_sorting.c

SRCS_B	=	srcs/checker.c					srcs/parsing_and_validation.c	srcs/data_initialisation.c\
			srcs/stack_base_operations.c	cmd/cmd_pa_pb.c					cmd/cmd_sa_sb_ss.c\
			cmd/cmd_ra_rb_rr.c				cmd/cmd_rra_rrb_rrr.c			srcs/median_operations.c\
			srcs/small_group_sorting.c		srcs/big_group_sorting.c		srcs/big_group_second_sorting.c\
			srcs/checker_utils.c


OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

BLUE	=	\033[1;34m
TURQUOISE =	\033[36;1m
END		=	\033[0m

.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

libft:
			@make -s -C libft/

$(NAME):	$(OBJ)
			@echo "$(BLUE)Compilation of $(NAME)$(END)"
			@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n[ Completed $(NAME) ] \n$(END)"

%.o:		%.c
			@$(CC) $(FLAGS)  -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
			@echo "$(BLUE)\nBonus done!\n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -s -C libft/ clean
			@echo "$(BLUE)\nCleaning done\n$(END)"

fclean:		clean
			@$(MAKE) -s -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\nDeleting done!\n$(END)"

re:			fclean all
			@echo "$(BLUE)Remake done\n$(END)"


