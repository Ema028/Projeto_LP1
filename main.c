#include "libs\input.h"
#include <stdio.h>
#include <locale.h> 

#define true 1
#define false 0

void registrar(void);
void consultar(void);
void deletar(void);
void editar(void);

int main()
{
    setlocale(LC_ALL,"portuguese"); 
    int opcao;

    while(true)
    {
        printf("Selecione um item do menu:\n\n");
        printf("1-Registrar\n2-Consultar\n3-Deletar\n4-Editar\n5-Sair do sistema\n\n\n"); 
        opcao = get_int("Qual função você deseja acessar? ");

        switch(opcao) 
        {
            case 1:
                registrar(); 
                break;

            case 2:
                consultar(); 
                break;

            case 3:
                deletar(); 
                break;

            case 4:
                editar();
                break;

            case 5:
                printf("Saindo do sistema!\n");
                return 0;

            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}

void registrar(void)
{
    return;
}

void consultar(void)
{
    return;
}

void deletar(void)
{
    return;
}

void editar(void)
{
    return;
}