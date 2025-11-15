#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "dados.h"
#include "arquivos.h"

int load_id(){
	FILE* f_id = fopen("libs/id.txt", "rb");
	if (f_id == NULL){
		//se não existe, cria o arquivo
		f_id = fopen("libs/id.txt", "wb");
		if (f_id == NULL) {
			printf("erro ao criar o arquivo\n");
			return 0;
		}
        return 0;
	}
    
	// Forma correta de ler o que o fwrite salvou:
    int ID = 0;
    fread(&ID, sizeof(int), 1, f_id);
	fclose(f_id);

	return ID;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // descarta todos os caracteres até o final da linha
    }
}

void limpar_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void registrar(){
    //Verifico se estou aqui para editar ou criar um novo elemento
    RegistroDoMercado R;

    int ID = load_id();
	R.id = ID++;
	printf("id do produto: %d\n", R.id);

    FILE * f = fopen("arquivo.bin", "ab");
    if (f == NULL){
        printf("Erro: Falha ao abrir o arquivo\n");
        return;
    }

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
            return;
    }
    if (fwrite(&R,sizeof(RegistroDoMercado), 1, f) != 1){
        printf("Erro ao escrever no arquivo");
        return;
    }
    
    //se ele conseguiu escrever o arquivo, iremos incrementar ID
    //Criamos um arquivo que salva o ID atual
    FILE* f_id = fopen("libs/id.txt", "wb");

	if (f_id == NULL)
	{
		printf("erro ao importar dados\n");
		return;
	}

	//reescrever o último id existente para ser o novo
	fseek(f_id, 0, SEEK_SET);
	fwrite(&ID, sizeof(int), 1, f_id);
	fclose(f_id);
    fclose(f);
}

void consultar(int indice)
{
    RegistroDoMercado RLido;
    FILE * f = fopen("arquivo.bin", "rb");
    if (f == NULL){
        printf("Erro: Falha ao abrir o arquivo\n");
    }
    //Enquanto existirem arquivos a serem lidos, procuramos pelo indice que queremos consultar
    while (fread(&RLido, sizeof(RegistroDoMercado), 1, f) == 1) {
        //Ao encontrar, printamos ele na tela
        if(RLido.id == indice){
            printf("--- Registro %d Lido ---\n", RLido.id);
            printf("ID: %d\nNome: %s\nPreco: %.2f\nQuantidade: %d\nData de Validade: %s\n",
            RLido.id, RLido.nome, RLido.preco, RLido.quantidade, RLido.datadevalidade);
            
            switch (RLido.tag){
            case (COMIDA):
                printf("Marca da Comida: %s", RLido.comida.marca);
                printf("Tipo da Comida: %s", RLido.comida.tipo);
                printf("Categoria da Comida: %s", RLido.comida.categoria);
                fclose(f);
                return;
            case (PAPELARIA):
                printf("Marca da Papelaria: %s", RLido.papelaria.marca);
                printf("Tipo da Papelaria: %s", RLido.papelaria.tipo);
                printf("Detalhe da Papelaria: %s", RLido.papelaria.detalhe);
                fclose(f);
                return;
            case (LIMPEZA):
                printf("Marca do Produto de Limpeza: %s", RLido.limpeza.marca);
                printf("Forma do Produto de Limpeza: %s", RLido.limpeza.forma);
                fclose(f);
                return;
            case (ACOUGUE):
                printf("Origem do Produto do Açougue: %s", RLido.acougue.origem);
                printf("Corte do Produto do Açougue: %s", RLido.acougue.corte);
                fclose(f);
                return;
            case (HORTIFRUTI):
                printf("Classe do Produto do Hortifruti: %s", RLido.hortifruti.classe);
                printf("Variedade do Produto do Hortifruti: %s", RLido.hortifruti.variedade);
                fclose(f);
                return;
            default:
                printf("Você não digitou algo válido!\n");
            }
        }
    }
    fclose(f);
    printf("Erro: Indice não encontrado\n");
}

void deletar(int indice)
{
    //Para deletar, abrimos dois arquivos
    FILE * f = fopen("arquivo.bin", "rb");
    if(f == NULL){
        printf("Erro: Falha ao abrir o arquivo\n");
        return;
    }
    //Esse é o temporario, que tera todos os que não queremos deletar
    FILE * temp = fopen("temp.bin", "wb");
    if(temp == NULL){
        printf("Erro: Falha ao abrir o arquivo temp\n");
        return;
    }
    RegistroDoMercado R;
    int encontrou = 0;
    //Procuramos por aqueles que não queremos e jogamos para o arquivo temporario
    while(fread(&R,sizeof(RegistroDoMercado), 1, f) == 1){
        if(R.id == indice){
            encontrou = 1;
        } else{
            fwrite(&R, sizeof(RegistroDoMercado), 1, temp);
        }
    }
    fclose(temp);
    fclose(f);
    //Se encontramos aquele que queremos deletar, deletamos o arquivo original e fazemos com que o temp vire o original
    if(encontrou == 1){
        remove("arquivo.bin");
        rename("temp.bin", "arquivo.bin");
        printf("Item Removido com Sucesso!\n");
    }
    else{
        printf("Erro: O item nao pode ser removido(indice nao encontrado)");
        remove("temp.bin");
    }
}

void editar(int indice)
{
    RegistroDoMercado R;
    FILE * f = fopen("arquivo.bin", "rb");
    if (f == NULL){
        printf("Erro: Falha ao abrir o arquivo\n");
    }
    FILE * temp = fopen("temp.bin", "wb");
    if (f == NULL){
        printf("Erro: Falha ao abrir o arquivo\n");
    }
    int encontrou = 0;
    //Procura o indice que queremos editar, deletamos e então registramos um novo com o mesmo indice
    while (fread(&R, sizeof(RegistroDoMercado), 1, f) == 1) {
        if(R.id == indice){
            encontrou = 1;
            RegistroDoMercado Rnovo;
            Rnovo.id = indice;
            limpar_buffer();
            get_sized_string("Nome: ", Rnovo.nome, 25);
            Rnovo.preco = get_float("Preco: ");
            limpar_buffer();
            Rnovo.quantidade = get_int("Quantidade: ");
            limpar_buffer();
            get_sized_string("Data(dd/mm/aaaa): ", Rnovo.datadevalidade, 11);
            Rnovo.tag = get_int("[0]Comida, [1]Papelaria, [2]Limpeza, [3]Acougue ou [4]Hortifruti?");
            limpar_buffer();
            switch (Rnovo.tag){
                case (COMIDA):
                    get_sized_string("Marca da Comida: ", Rnovo.comida.marca, 20);
                    get_sized_string("Tipo da Comida: ", Rnovo.comida.tipo, 20);
                    get_sized_string("Categoria da Comida: ", Rnovo.comida.categoria, 20);
                    break;
                case (PAPELARIA):
                    get_sized_string("Marca da Papelaria: ", Rnovo.papelaria.marca, 20);
                    get_sized_string("Tipo da Papelaria: ", Rnovo.papelaria.tipo, 20);
                    get_sized_string("Detalhe da Papelaria: ", Rnovo.papelaria.detalhe, 20);
                    break;
                case (LIMPEZA):
                    get_sized_string("Marca do Produto de Limpeza: ", Rnovo.limpeza.marca, 20);
                    get_sized_string("Forma do Produto de Limpeza: ", Rnovo.limpeza.forma, 12);
                    break;
                case (ACOUGUE):
                    get_sized_string("Origem do Produto do Açougue: ", Rnovo.acougue.origem, 20);
                    get_sized_string("Corte do Produto do Açougue: ", Rnovo.acougue.corte, 20);
                    break;
                case (HORTIFRUTI):
                    get_sized_string("Classe do Produto do Hortifruti: ", Rnovo.hortifruti.classe, 20);
                    get_sized_string("Variedade do Produto do Hortifruti: ", Rnovo.hortifruti.variedade, 20);
                    break;
                default:
                    printf("Você não digitou algo válido!\n");
                    return;
            }
            if (fwrite(&Rnovo,sizeof(RegistroDoMercado), 1, temp) != 1){
                printf("Erro ao escrever no arquivo editado");
                return;
            }
        }
        else{
            if (fwrite(&R,sizeof(RegistroDoMercado), 1, temp) != 1){
                printf("Erro ao escrever no arquivo antigo");
                return;
            }
        }
    }
    fclose(temp);
    fclose(f);
    //Se encontramos aquele que queremos deletar, deletamos o arquivo original e fazemos com que o temp vire o original
    if(encontrou == 1){
        remove("arquivo.bin");
        rename("temp.bin", "arquivo.bin");
    }
    else{
        printf("Erro: O item nao pode ser removido(indice nao encontrado)");
        remove("temp.bin");
    }
}
