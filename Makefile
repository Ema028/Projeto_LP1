MAIN = main.c $(wildcard libs/*.c)
CC = gcc

all: estoque

#make estoque - gera executável estoque
estoque: main.c
	$(CC) $(MAIN) -o estoque

#make run - executar
run: all
	./estoque