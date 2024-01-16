NAME = push_swap

BONUS_NAME = checker

LIBFT = Libfth
LIBFTM = Libfth/libft.a
CFLAGS = -Wall -Wextra -Werror
SRCM = push_swap.c
SRC = 	argument_utils.c \
		ft_error.c \
		ft_sort_utils.c \
		ft_sort.c\
		pivot.c \
		rule_a.c \
		rule_b.c \
		rule_ab.c \
		ft_mini_sort.c \
		ft_quick_sort.c \
		argument_check.c
SRCB = ft_get_next_line.c\
		checker.c
SRCMO = $(SRCM:.c=.o)
OBJ = $(SRC:.c=.o)
OBJS = $(SRCB:.c=.o)

all:$(NAME)

$(NAME): $(OBJ) $(SRCMO)
	make -C $(LIBFT)
	cc $(CFLAGS) $(OBJ) $(SRCMO) $(LIBFTM) -o $(NAME)

$(BONUS_NAME): $(OBJ) $(OBJS)
	make -C $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(OBJ) $(LIBFTM) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJ) $(OBJS) $(SRCMO)

fclean:clean
	rm -rf $(BONUS_NAME) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus
