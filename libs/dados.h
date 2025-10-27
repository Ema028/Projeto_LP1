#ifndef DADOS_H //include guard para evitar que aconteça novamente problema de duplicatas
#define DADOS_H

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
    };
}RegistroDoMercado;

#endif