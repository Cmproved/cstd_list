CC=gcc

NAME=libcstd_string_list.a

SRC = src/cstd_list.c

CFLAGS 	+= -O3 -Ofast -Wall

CFLAGS_DEBUG += ${CFLAGS} -g2 -fanalyzer -Wextra -Wundef

OBJ=${patsubst %c, %o, ${SRC}}
OBJ_DEBUG=${patsubst %c, %o_debug, ${SRC}}

RM=rm -rf

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.o_debug: %.c
	${CC} ${CFLAGS_DEBUG} -c -o $@ $<

all: ${NAME}

${NAME}: ${OBJ}
	ar rc $(NAME) $^

debug: ${OBJ_DEBUG}
	ar rc ${NAME} $^

tests: debug
	gcc ${CFLAGS_DEBUG} tests/main.c -L. -lcstdlist

clean:
	${RM} ${OBJ} ${OBJ_DEBUG}

fclean: clean
	${RM} ${NAME} a.out

re: fclean all

.PHONY: all ${NAME} debug tests clean re fclean
