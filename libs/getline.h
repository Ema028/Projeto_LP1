#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>
#include <stdlib.h>

/* getline é parte da extensão POSIX 2008.
 * está disponível em im compilador compatível com o POSIX,
 * devido a indisponíbilidade de getline no mingw,
 * o código implementa uma versão local da função para usar se necessário*/

//se é um windows usa a implementação local de getline,mas se getline existe usa o real
#if defined(_WIN32) || defined(_WIN64)

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#else
#define _GNU_SOURCE
#include <stdio.h>

#endif

#endif

