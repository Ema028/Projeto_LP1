#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "dados.h"

void limpar_terminal();
void limpar_buffer();
void registrar();
void consultar(int indice);
void deletar(int indice);
void editar(int indice);

#endif
