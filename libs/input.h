#ifndef INPUT_H //include guard para evitar que aconteça novamente problema de duplicatas
#define INPUT_H

#include <stdio.h>

void free_memory();
char* get_sized_string(char* text, char* string, int size);
ssize_t get_file_string(char** buffer, FILE* file, void (*func)(void));
char* get_string();
int get_int(char* text);
float get_float(char* text);
char get_char(char* text);

#endif
