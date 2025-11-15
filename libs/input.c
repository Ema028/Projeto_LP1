#include "input.h"
#include "getline.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define F fflush(stdout) //limpar buffer de saída

//forçar getline a usar malloc
char* text = NULL;

void free_memory()
{
	free(text);
}

ssize_t get_file_string(char** buffer, FILE* file, void (*func)(void))
{
	ssize_t read;
	size_t size = 0;

	read = getline(buffer, &size, file);

	atexit(func);
	return read;
}

char* get_string()
{
	//size_t ao invés de int pra evitar overflow
	size_t size = 0;
	getline(&text, &size, stdin);
	atexit(free_memory);
	return text;
}

char* get_sized_string(char* text, char* string, int size)
{
    printf("%s\n", text);
    //fgets ao inves de scanf para ser capaz de armazenar nomes completos com espaço entre nome e sobrenome
    fgets(string, size, stdin);
    // Converte para minúsculo caractere por caractere
    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = tolower((unsigned char)string[i]);
    }
    return string;
}

int get_int(char* text)
{
    int x;
    printf("%s\n", text);
    scanf("%i", &x); F;
    return x;
}

float get_float(char* text)
{
    float x;
    printf("%s\n", text);
    scanf("%f", &x); F;
    return x;
}

char get_char(char* text)
{
    char x;
    printf("%s\n", text);
    scanf("%c", &x); F;
    return x;
}
