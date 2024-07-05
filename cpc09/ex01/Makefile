
DIR		= srcs/

SRCS	= ${DIR}ft_putchar.c ${DIR}ft_strcmp.c ${DIR}ft_strlen.c ${DIR}ft_putstr.c ${DIR}ft_swap.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

DEPS	= includes/ft.h

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o:		%.c ${DEPS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re