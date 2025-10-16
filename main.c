#include "libs\input.h"
#include <stdio.h>
#include <locale.h> 

#define true 1
#define false 0

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // descarta todos os caracteres até o final da linha
    }
}

//Estoque do Mercado
typedef enum{COMIDA, PAPELARIA, LIMPEZA, ACOUGUE, HORTIFRUTI}TipoDoProduto;

typedef struct{
    char marca[20];
    char tipo[20]; // Arroz, feijão, macarrao
    char categoria[20]; //seco, perecivel, nao perecivel
}Comida;

typedef struct{
    char classe[20]; //fruta, legume, folhosa, raiz
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
    char nome[25];
    float preco;
    int quantidade;
    char datadevalidade[11];
    TipoDoProduto tag;
    union{
        Comida comida;
        Papelaria papelaria;
        Limpeza limpeza;
        Acougue acougue;
        Hortifruti hortifruti;
    };
}RegistroDoMercado;

void registrar(int *ID);
void consultar(void);
void deletar(void);
void editar(void);

int main()
{
    setlocale(LC_ALL,"portuguese"); 
    int opcao;
    int ID = 0;
    while(true)
    {
        printf("Selecione um item do menu:\n\n");
        printf("1-Registrar\n2-Consultar\n3-Deletar\n4-Editar\n5-Sair do sistema\n\n\n"); 
        opcao = get_int("Qual funcao voce deseja acessar? ");
        limpar_buffer();
        switch(opcao) 
        {
            case 1:
                registrar(&ID); 
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
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}

void registrar(int *ID){
    FILE * f = fopen("arquivo.bin", "ab");
    if (f == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    RegistroDoMercado R;
    R.id = *ID;
    get_sized_string("Nome: ", R.nome, 25);
    R.preco = get_float("Preco: ");
    limpar_buffer();
    R.quantidade = get_int("Quantidade: ");
    limpar_buffer();
    get_sized_string("Data(dd/mm/aaaa): ", R.datadevalidade, 11);
    R.tag = get_int("[0]Comida, [1]Papelaria, [2]Limpeza, [3]Acougue ou [4]Hortifruti?");
    limpar_buffer();
    switch (R.tag){
        case (COMIDA):
            get_sized_string("Marca da Comida: ", R.comida.marca, 20);
            get_sized_string("Tipo da Comida: ", R.comida.tipo, 20);
            get_sized_string("Categoria da Comida: ", R.comida.categoria, 20);
            break;
        case (PAPELARIA):
            get_sized_string("Marca da Papelaria: ", R.papelaria.marca, 20);
            get_sized_string("Tipo da Papelaria: ", R.papelaria.tipo, 20);
            get_sized_string("Detalhe da Papelaria: ", R.papelaria.detalhe, 20);
            break;
        case (LIMPEZA):
            get_sized_string("Marca do Produto de Limpeza: ", R.limpeza.marca, 20);
            get_sized_string("Forma do Produto de Limpeza: ", R.limpeza.forma, 12);
            break;
        case (ACOUGUE):
            get_sized_string("Origem do Produto do Açougue: ", R.acougue.origem, 20);
            get_sized_string("Corte do Produto do Açougue: ", R.acougue.corte, 20);
            break;
        case (HORTIFRUTI):
            get_sized_string("Classe do Produto do Hortifruti: ", R.hortifruti.classe, 20);
            get_sized_string("Variedade do Produto do Hortifruti: ", R.hortifruti.variedade, 20);
            break;
        default:
            printf("Você não digitou algo válido!\n");
    }
    if (fwrite(&R,sizeof(RegistroDoMercado), 1, f) != 1){
        printf("Erro ao escrever no arquivo");
    }
    fclose(f);
    (*ID)++;
}

void consultar(void)
{
    int indice = get_int("Indice: ");
    RegistroDoMercado RLido;
    FILE * f = fopen("arquivo.bin", "rb");
    long offset = (long)indice*sizeof(RegistroDoMercado);
    if (fseek(f, offset, SEEK_SET) != 0) {
        printf("Erro: Posicao fora dos limites do arquivo (fseek).\n");
        fclose(f);
        return;
    }
    if (fread(&RLido, sizeof(RegistroDoMercado), 1, f) == 1) {
        printf("--- Registro %d Lido ---\n", indice + 1);
        printf("ID: %d, Nome: %s, Preco: %f\n Quantidade: %d, Data de Validade: %s\n",
             RLido.id, RLido.nome, RLido.preco, RLido.quantidade, RLido.datadevalidade);
        switch (RLido.tag){
            case (COMIDA):
                printf("Marca da Comida: ", RLido.comida.marca);
                printf("Tipo da Comida: ", RLido.comida.tipo);
                printf("Categoria da Comida: ", RLido.comida.categoria);
                break;
            case (PAPELARIA):
                printf("Marca da Papelaria: ", RLido.papelaria.marca);
                printf("Tipo da Papelaria: ", RLido.papelaria.tipo);
                printf("Detalhe da Papelaria: ", RLido.papelaria.detalhe);
                break;
            case (LIMPEZA):
                printf("Marca do Produto de Limpeza: ", RLido.limpeza.marca);
                printf("Forma do Produto de Limpeza: ", RLido.limpeza.forma);
                break;
            case (ACOUGUE):
                printf("Origem do Produto do Açougue: ", RLido.acougue.origem);
                printf("Corte do Produto do Açougue: ", RLido.acougue.corte);
                break;
            case (HORTIFRUTI):
                printf("Classe do Produto do Hortifruti: ", RLido.hortifruti.classe);
                printf("Variedade do Produto do Hortifruti: ", RLido.hortifruti.variedade);
                break;
            default:
                printf("Você não digitou algo válido!\n");
        }
    } else {
        printf("Erro: Nao foi possivel ler o registro na posicao %d (EOF).\n", indice);
    }
}

void deletar(void)
{
    int indice = get_int("Indice: ");
    FILE * f = fopen("arquivo.bin", "rb");
    if(f == NULL){
        printf("Erro: Nao foi blabla bla");
    }
    FILE * temp = fopen("temp.bin", "ab");
    if(temp == NULL){
        printf("Erro: Nao foi blabla bla");
    }
    RegistroDoMercado R;
    int encontrou = 0;
    while(fread(&R,sizeof(RegistroDoMercado), 1, f) == 1){
        if(R.id == indice){
            encontrou = 1;
        } else{
            fwrite(&R, sizeof(RegistroDoMercado), 1, temp);
        }
    }
    if(encontrou == 1){
        remove("arquivo.bin");
        rename("temp.bin", "arquivo.bin");
        printf("REMOVEU PORRRRRRRRRRRAAAA");
    }
    else{
        printf("nao removeu, mane");
        remove("temp.bin");
    }
}

void editar(void)
{
    return;
}