CC=gcc

NAME=libcstdlist.a

SRC = src/cstd_list.c

CFLAGS 	+= -g2

OBJ=$(SRC:.c=.o)

RM=rm -r

all: ${NAME}

${NAME}: ${OBJ}
	ar rc $(NAME) $^

tests: ${NAME}
	gcc -Wall -g2 tests/main.c -L. -lcstdlist

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME} a.out

re: fclean all
