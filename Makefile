MAIN = main.c $(wildcard libs/*.c)
CC = gcc

FLAGS = -Wall -Wextra
all: estoque

#make estoque - gera executável estoque
estoque: main.c
	$(CC) $(FLAGS) $(MAIN) -o estoque 

#make run - executar
run: all
	./estoque

