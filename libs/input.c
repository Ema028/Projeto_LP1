#include "input.h"
#include <stdio.h>

char* get_sized_string(char* text, char* string, int size)
{
    printf("%s\n", text);
    //fgets ao inves de scanf para ser capaz de armazenar nomes completos com espaço entre nome e sobrenome
    fgets(string, size, stdin);
    return string;
}

int get_int(char* text)
{
    int x;
    printf("%s\n", text);
    scanf("%i", &x);
    return x;
}

float get_float(char* text)
{
    float x;
    printf("%s\n", text);
    scanf("%f", &x);
    return x;
}

char get_char(char* text)
{
    char x;
    printf("%s\n", text);
    scanf("%c", &x);
    return x;
}