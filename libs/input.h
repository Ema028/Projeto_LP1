#ifndef INPUT_H //include guard para evitar que aconteça novamente problema de duplicatas
#define INPUT_H

#include <stdio.h>

char* get_sized_string(char* text, char* string, int size);
int get_int(char* text);
float get_float(char* text);
char get_char(char* text);

#endif