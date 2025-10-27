#include "libs\input.h" // biblioteca que lida com input do usuário
#include "libs\dados.h" // declara tipos de dados usados para guardar informações do mercado
#include "libs\arquivos.h" // funções que manipulam arquivos
#include <stdio.h>
#include <locale.h> 

#define true 1
#define false 0

int main()
{
    setlocale(LC_ALL,"portuguese"); 
    int opcao;
    int ID = 0;
    while(true)
    {
        limpar_terminal();
        printf("Selecione um item do menu:\n\n");
        printf("1-Registrar\n2-Consultar\n3-Deletar\n4-Editar\n5-Sair do sistema\n\n\n"); 
        opcao = get_int("Qual funcao voce deseja acessar? ");
        limpar_buffer();
        int indice;
        switch(opcao) 
        {
            case 1:
                registrar(ID); 
                ID++;
                break;

            case 2:
                indice = get_int("Indice: ");
                consultar(indice); 
                break;

            case 3:
                indice = get_int("Indice: ");
                deletar(indice); 
                break;

            case 4:
                indice = get_int("Indice: ");
                editar(indice);
                break;

            case 5:
                printf("Saindo do sistema!\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
        }
        printf("Pressione ENTER para sair!");
        limpar_buffer();
        getchar();
    }
    return 0;
}