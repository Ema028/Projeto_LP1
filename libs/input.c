#include "input.h"
#include <stdio.h>
#include <ctype.h>

#define F fflush(stdout) //limpar buffer de saída

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