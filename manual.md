<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/5d4d10e3-964c-4b63-b16f-5b1d3009bf70" />

# Como usar o programa?
- Este sistema funciona pelo terminal. Todas as ações são feitas escolhendo uma opção do menu digitando o número correspondente e pressionando ENTER.

![Imagem do WhatsApp de 2025-12-03 à(s) 23 10 18_10bcfbf7](https://github.com/user-attachments/assets/c758be9a-efe7-4537-abb4-2a64c140f6ad)

1. Registrar um Produto:
   - Usado para cadastrar um novo item no estoque.
   - Preencha os campos que o programa pedir:
   1. id do produto – código numérico de identificação.
   2. Nome – nome do produto.
   3. Preco – valor unitário.
   4. Quantidade – quantidade em estoque.
   5. Data (dd/mm/aaaa) – data de validade ou de registro.
   6. Tipo de produto – escolha um número:
      0 – Comida;
      1 – Papelaria;
      2 – Limpeza;
      3 – Açougue;
      4 – Hortifruti;

![Imagem do WhatsApp de 2025-12-03 à(s) 23 10 18_b91647a7](https://github.com/user-attachments/assets/673aa5e2-2db7-436c-a02a-623dfedc9cb2)



2. Consultar um produto:
  - Usado para ver os dados de um item já cadastrado
  - O sistema pergunta “Indice:” – digite o ID/índice do produto.
  - Se o índice existir, o sistema mostra todas as informações do produto.
  - Caso o Indice exista:
  
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 10 18_ff7f0e40](https://github.com/user-attachments/assets/bb239054-ba63-481d-802e-889010308341)

  - Caso não exista:

  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 50 37_039d8372](https://github.com/user-attachments/assets/3860f133-2ae6-40ae-8f69-70f1e6f88fd6)

3. Deletar um produto:
   - Usado para remover um item do estoque.
   - Informe o índice do produto a ser removido.
   - Se o índice existir, aparecerá:
  
     ![Imagem do WhatsApp de 2025-12-03 à(s) 23 54 23_183d554b](https://github.com/user-attachments/assets/a77c771d-50fa-4ffa-92d4-0ecd242a5164)

5. Editar um produto:
   -  Usado para alterar os dados de um item já existente.
   -  Informe o índice do produto que deseja alterar.
   -  O sistema pedirá novamente todos os campos (nome, preço, quantidade, data, categoria etc.).
   -  Digite os novos valores. Eles substituem os antigos.

     ![Imagem do WhatsApp de 2025-12-03 à(s) 23 10 19_cb1a07b1](https://github.com/user-attachments/assets/add7890c-ef7d-4b79-a1cd-b0742b59f9f5)

6. Sair do sistema:
   - O sistema é finalizado e a janela do terminal pode ser fechada.

# Por dentro das funções: 
1. Registrar
- O que ela faz?
  - Cria um novo registro de produto e grava no arquivo binário de dados.
- Operações principais: 
1. Carrega e incrementa o ID
   -  Chama load_id() para pegar o último ID usado.
   -  Incrementa esse valor e salva em R.id.
   -  Esse ID será a chave de identificação do novo produto.
2. Abre o arquivo de dados
   - Abre o arquivo em modo append binário para adicionar o novo registro no final.
   - Se der erro ao abrir, a função mostra a mensagem e termina.
3. Lê os dados básicos do produto do teclado
   - Nome (R.nome)
   - Preço (R.preco)
   - Quantidade (R.quantidade)
   - Data de validade (R.datadevalidade)
   - Tipo (tag) do produto (R.tag), através do menu:
     0 – Comida
     1 – Papelaria
     2 – Limpeza
     3 – Açougue
     4 – Hortifruti
4. Lê os dados específicos conforme a categoria (switch (R.tag))
   - COMIDA: marca, tipo, categoria.
   - PAPELARIA: marca, tipo, detalhe.
   - LIMPEZA: marca, forma do produto.
   - ACOUGUE: origem, corte.
   - HORTIFRUTI: classe (fruta, legume, etc.) e variedade.
   - Se o usuário digitar uma tag inválida, a função mostra mensagem e encerra sem gravar.
5. Grava o registro no arquivo de dados
   - fwrite(&R, sizeof(RegistroDoMercado), 1, f);
   - Se falhar, mostra “Erro ao escrever no arquivo” e termina.
6. Atualiza o arquivo de ID
   - Abre libs/id.txt em modo "wb".
   - Regrava lá o novo ID atual (para na próxima inclusão continuar a sequência).
   - Fecha os arquivos.
- Documentação:
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 32 53_c28baa41](https://github.com/user-attachments/assets/0d4e89a9-bbfe-4702-8dcf-c6d5968c64b9)
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 33 35_21363be2](https://github.com/user-attachments/assets/28a707cc-c73f-43c2-b4cd-a77bc41a2011)


2. Consultar
- O que ela faz?
  - Busca um produto pelo ID (índice) e imprime os seus dados na tela.
- Operações principais: 
  1. Abre o arquivo de dados
     - Se der erro ao abrir, a função mostra a mensagem e termina.
  3. Percorre todos os registros
     - Usa um while (fread(...)) lendo um RegistroDoMercado por vez.
  4. Quando encontra o ID desejado
     - Se RLido.id == indice:
     - Mostra ID, nome, preço, quantidade e data de validade.
     - Usa um switch (RLido.tag) para imprimir os campos específicos da categoria
     - Fecha o arquivo e dá return (para assim parar na primeira ocorrência).
  5. Se o loop termina sem encontrar
     - Fecha o arquivo e imprime mensagem de erro.
- Documentação:
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 33 47_751ffd53](https://github.com/user-attachments/assets/7cdba388-b2a1-409b-b6c5-05fc0d33db10)
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 34 03_ecc000b7](https://github.com/user-attachments/assets/cc09c864-f49b-4d40-9f84-b117f0bc49ba)


3. Deletar
- O que ela faz?
  - Remove um registro específico (pelo ID) do arquivo de dados.
- Operações principais: 
1. Abre os arquivos
   - arquivo.bin em modo leitura ("rb"): arquivo original.
   - temp.bin em modo escrita ("wb"): arquivo temporário.
   - Se algum falhar ao abrir, mostra erro e retorna.
2. Copia os registros que devem permanecer
   - Lê cada registro de arquivo.bin com fread.
   - Se R.id == indice, marca encontrou = 1 e não escreve esse registro no temporário (ou seja, ele será “apagado”).
   - Caso contrário, escreve o registro em temp.bin com fwrite.
3. Fecha os arquivos
4. Substitui o arquivo original
   - Se encontrou == 1 (ou seja, existia um registro com esse ID):
   - remove "arquivo.bin"
   - renomeia "temp.bin" pra "arquivo.bin"
   - Se não encontrou imprime mensagem de erro.
- Documentação:
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 34 35_76b18614](https://github.com/user-attachments/assets/7157e9e6-da75-4b25-809e-e15b6a703a33)

   
4. Editar
- O que ela faz?
  - Edita um produto já existente, substituindo o registro antigo por um novo com o mesmo ID.
- Operações principais:
1. Abre o arquivo original e o temporário
2. Percorre os registros
   - Para cada registro lido em R com fread se R.id == indice marca que encontrou, cria uma struct nova Rnovo, define Rnovo.id com o mesmo ID de antes.
   - Pergunta novamente todos os campos (nome, preço, quantidade, data, tag e campos específicos de acordo com a tag).
   - Escreve Rnovo no arquivo temp com fwrite.
   - Se não for o caso de R.id == indice, apenas vai copiar o registro antigo para temp com fwrite.
3. Fecha arquivos
4. Substitui o arquivo original se encontrou:
   - renomeia "temp.bin" pra "arquivo.bin"
5. Se não encontrou:
   - Imprime erro “indice nao encontrado”.
   - Remove temp.bin.
- Documentação:
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 34 44_e6ac26d9](https://github.com/user-attachments/assets/6da0bf7e-e6e0-4dae-9095-17264f11cba6)
  ![Imagem do WhatsApp de 2025-12-03 à(s) 23 35 37_503a2d7b](https://github.com/user-attachments/assets/4c7705ec-ed49-49cc-b2d6-57d853f41d07)
