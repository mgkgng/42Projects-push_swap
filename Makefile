MSRCS =	srcs/main.c srcs/push_swap.c srcs/move.c srcs/algo.c

CSRCS =	common/push_swap_utils.c common/ops.c common/parse.c

BSRCS =	bonus/main.c bonus/checker.c

NAME =	push_swap
BNAME = checker

MOBJS = $(MSRCS:.c=.o)
COBJS = ${CSRCS:.c=.o}
BOBJS = $(BSRCS:.c=.o)

INCLUDES = ./includes/

CFLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft/

%.o:	%.c
		gcc -o $@ -c $< $(CFLAGS) -I${INCLUDES}

all : $(NAME)

bonus	:	$(COBJS) $(BOBJS)
			make all -C $(LIB_PATH)
			gcc $(CFLAGS) -I${INCLUDES} -o $(BNAME) $(BOBJS) $(COBJS) libft/libft.a

$(NAME) :	$(COBJS) $(MOBJS)
			make all -C $(LIB_PATH)
			gcc $(CFLAGS) -I${INCLUDES} -o $(NAME) $(MOBJS) $(COBJS) libft/libft.a

clean :
			rm -f $(MOBJS) $(COBJS) $(BOBJS)
			make clean -C $(LIB_PATH)

fclean :	clean
			rm -f $(NAME) $(BNAME)
			make fclean -C $(LIB_PATH)

re :		fclean all

.PHONY : all clean fclean re bonus
