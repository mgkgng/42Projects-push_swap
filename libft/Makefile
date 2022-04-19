SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strlen.c \
		ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstclear.c ft_putstr.c

NAME = libft.a

INCLUDES = -I ../includes/
OBJS = ${SRCS:.c=.o}

CFLAG = -Wextra -Wall -Werror

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			
.c.o:
			gcc ${CFLAG} ${INCLUDES} -c $< -o ${<:.c=.o}
			
clean:	
			rm -f ${OBJS} ${BOJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
