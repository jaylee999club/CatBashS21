CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_cat test

s21_cat:
	$(CC) $(CFLAGS) -o s21_cat s21_cat.c

clean:
	rm -f s21_cat
	rm -f s21_cat.txt
	rm -f cat.txt

test: test.sh
	chmod +x test.sh
	bash ./test.sh

rebuild: clean all