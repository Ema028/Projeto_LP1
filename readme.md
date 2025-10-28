# MERCADO

Sistema simples de CRUD simulando um registro de mercado.

## SOBRE

### ÁREA DE ATUAÇÃO E INFORMAÇÕES GERENCIADAS
Gestão de inventário para um supermercado, separado pelos corredores e tipo de produto (COMIDA, PAPELARIA, LIMPEZA, ACOUGUE, HORTIFRUTI), além de algumas informações em comum entre os produtos:
    -id
    - preco
    - nome
    - quantidade
    - data de validade

### OPERAÇÕES PERMITIDAS
Permite criação, edição, exclusão e busca de registros.

### ESTRUTURA DO PROJETO
A estrutura foi mantida dessa forma com o objetivo de manter a main o mais enxuta e legível possível, utilizando de 3 bibliotecas locais para modularização do código:

    /libs      -> bibliotecas locais
        arquivos.h -> funções que manipulam arquivos
        dados.h    -> tipos de dados usados para guardar informações do mercado
        input.h    -> biblioteca que lida com input do usuário
    main.c     -> script principal
    Makefile   -> scripts de compilação e execução
    README.md  -> documentação do projeto


#### CONSIDERAÇÕES TÉCNICAS
O script de compilação e execução é uma Makefile, então é necessário instalar o make no sistema. Foi testada na versão GNU Make.

    No ubuntu:
    
        sudo apt install make

    Para compilar: 
    
        make estoque

    Para rodar: 
    
        make run
