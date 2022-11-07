CC=gcc

NAME=libcstdlist.a

SRC = src/cstd_list.c

CFLAGS 	+= -g2 -Wall -Wextra -fanalyzer

OBJ=$(SRC:.c=.o)

RM=rm -r

all: ${NAME}

${NAME}: ${OBJ}
	ar rc $(NAME) $^

tests: ${NAME}
	gcc tests/main.c -L. -lcstdlist

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME} a.out

re: fclean all
