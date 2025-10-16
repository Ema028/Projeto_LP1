#include "libs\input.h"
#include <stdio.h>
#include <locale.h> 

#define true 1
#define false 0
//Estoque do Mercado
typedef enum{COMIDA, PAPELARIA, LIMPEZA, ACOUGUE, HORTIFRUTI}TipoDoProduto;

typedef struct{
    char marca[20];
    char tipo[20]; // Arroz, feijão, macarrao
    char categoria[20]; //seco, perecivel, nao perecivel
}Comida;

typedef struct{
    classe[20]; //fruta, legume, folhosa, raiz
    char variedade[20]; // banana prate, tomate italiano, ...  
}Hortifruti;

typedef struct{
    char marca[20];
    char tipo[20];// caneta, caderno, pincel, ...
    char detalhe[20];// azul, 200f, 75g, ...
}Papelaria;

typedef struct{
    char marca[20];
    char forma[12]; // liquido, spray, po
}Limpeza;

typedef struct{
    char origem[20];// boi, galinha, porco, peixe, ...
    char corte[20]; //alcatra, peito, lombo, ...
}Acougue;

typedef struct{
    int id;
    float preco;
    char nome[25];
    int quantidade;
    char datadevalidade[11];
    TipoDoProduto tag;
    union{
        Comida comida;
        Papelaria papelaria;
        Limpeza limpeza;
        Acougue acougue;
        Hortifruti hortifruti;
    }detalhes;
}RegistroDoMercado;

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