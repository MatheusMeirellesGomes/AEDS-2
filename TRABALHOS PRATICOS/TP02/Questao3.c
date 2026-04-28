/*Questao 3: Ordenação por Seleção em C. Usando arranjos, implemente o algoritmo de ordenação por sele¸c˜ao considerando 
que a chave de pesquisa é o atributo nome. A entrada e a saída padrão são iguais as da primeira quest˜ao, contudo, a saída corresponde 
aos registros ordenados. Nome do arquivo de log: matrícula selecao.txt*/

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#include <time.h>

//Struct para Data. 
typedef struct {
    //Atributos
    int dia; 
    int mes; 
    int ano; 
} Data; 

//Construtor para Data. 
Data construtorDate (int ano, int mes, int dia) {
    Data d;
    d.ano = ano;
    d.mes = mes;
    d.dia = dia; 
    return d;
}
//Método parse para Data. 
Data parseData (char *str) {
    int ano, mes, dia;

    //Lê a string no formato aaaa-mm-dd.
    sscanf(str, "%d-%d-%d", &ano, &mes, &dia);

    //Retornar a data com valores convertidos. 
    return construtorDate(ano, mes, dia);
}

/*Set para ano. (Data)
void setAno (Data *d, int ano) {
    if (ano >= 0) d->ano = ano; 
}*/

int getAno(Data *d) {
    return d->ano; 
}

/*Set para mes. 
void setMes (Data *d, int mes) {
    if (mes >= 1 && mes <= 12) d->mes = mes; 
}*/

int getMes(Data *d) {
    return d->mes; 
}

/*Set para dia.
void setDia (Data *d, int dia) {
    if (dia >= 1 && dia <= 31) d->dia = dia; 
}*/

int getDia(Data *d) {
    return d->dia; 
}

//Procedimento para formatar a data. 
void formatarData(Data *d, char *buffer) { //Buffer é um espaço (array) para armazenar a string formatada.
    sprintf(buffer, "%02d/%02d/%04d", d->dia, d->mes, d->ano);
}

//Strcut para Hora. 
typedef struct {
    //Atributos
    int hora; 
    int minuto; 
}Hora; 

//Construtor para Hora.
Hora construtorHour (int hora, int minuto) {
    Hora h; 

    //atribuir os valores.
    h.hora = hora; 
    h.minuto = minuto; 
    
    return h; 
}
 
//Método parse para Hora. 
Hora parseHora (char *str) {
    int hora, minuto; 

    //Lê a hora no formato HH:mm.
    sscanf(str, "%d:%d", &hora, &minuto);
    
    //Retornar a hora com valores convertidos.
    return construtorHour(hora, minuto);
}

int getHora(Hora *h) {
    return h->hora; 
}

int getMinuto(Hora *h) {
    return h->minuto; 
}

//Procedimento para formatar a hora. 
void formatarHora(Hora *h, char *buffer) {
    sprintf(buffer, "%02d:%02d", h->hora, h->minuto);
}

//Struct para Restaurante.
typedef struct {
    //Atributos. 
    int id; 
    char nome[100]; 
    char cidade[100]; 
    int capacidade; 
    double avaliacao; 
    char tiposCozinha[5][50];
    int qntdTipos; //Quantidade de tipos de cozinha.
    int faixaPreco; 
    Hora horarioAbertura; 
    Hora horarioFechamento; 
    Data dataAbertura; 
    bool aberto;  
} Restaurante; 

//Construtor para Restaurante. 
Restaurante construtorRestaurant (int id, char *nome, char *cidade, int capacidade, double avaliacao, char tiposCozinha[5][50], int qntdTipos,
    int faixaPreco, Hora horarioAbertura, Hora horarioFechamento, Data dataAbertura, bool aberto) {
    //Criar o restaurante.
    Restaurante r; 
    
    //Inicializar os atributos.
    r.id = id;
    strcpy(r.nome, nome); 
    strcpy(r.cidade, cidade);
    r.capacidade = capacidade; 
    r.avaliacao = avaliacao; 
    for (int i = 0; i < 5; i++) 
        strcpy(r.tiposCozinha[i], tiposCozinha[i]);
    r.qntdTipos = qntdTipos;
    r.faixaPreco = faixaPreco;
    r.horarioAbertura = horarioAbertura;
    r.horarioFechamento = horarioFechamento;
    r.dataAbertura = dataAbertura;
    r.aberto = aberto;

    //Retornar o restaurante criado.
    return r;
}

//Método parse para tipos de cozinha.(tiposCozinha)
int parseTiposCozinha (char *str, char tiposCozinha[5][50]) {
    //Inicializar um contador. 
    int qntdTipos = 0; //Quantidade de tipos de cozinha.
    char *parte = strtok(str, ";"); //Dividir a string 

    //Loop. 
    while (parte != NULL && qntdTipos < 5) {
        //Loop para remover espaços em branco no início e no final da parte. 
        while (*parte == ' ') parte++; //Tipo um '.trim()' 

        //Copiar a parte atual para o array de tipos de cozinha.
        strcpy(tiposCozinha[qntdTipos], parte);
        qntdTipos++; //Incrementar o contador.
        parte = strtok(NULL, ";"); //Obter a próxima parte.
    }

    //Retornar a quantidade de tipos de cozinha. 
    return qntdTipos;
}

//Procedimento para formatar os tipos de cozinha.
void formatarTiposCozinha (char tiposCozinha[5][50], int qntdTipos, char *buffer) {
    //Garantir que o buffer esteja vazio antes de começar a formatar.
    buffer[0] = '\0';

    //Inicializar o buffer com o formato de abertura.
    strcpy(buffer, "["); 

    //Loop para concatenar os tipos de cozinha no buffer.
    for (int i = 0; i < qntdTipos; i++) {
        //Concatenar o tipo de cozinha atual no buffer.
        strcat(buffer, tiposCozinha[i]);

        //Adicionar o delimitador. 
        if (i < qntdTipos - 1) strcat(buffer, ", "); //Adicionar a vírgula entre os tipos de cozinha.
    }

    //Fechar a formatação com ']'.
    strcat(buffer, "]");
}

//Método parse para faixa de preço.
int parseFaixaPreco (char *str) {
    int faixaPreco = 0; 

    //Contar a quantidade de '$' na string.
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '$') faixaPreco++; //$ = 1, $$ = 2, $$$ = 3, $$$$ = 4.
    }

    //Retornar a faixa de preço.
    return faixaPreco;
}

//Procedimento para formatar a faixa de preço.
void formatarFaixaPreco(int faixaPreco, char *buffer) {
    //Inicializar o buffer vazio
    buffer[0] = '\0';

    //Loop para adicionar a quantidade correta de '$' no buffer.
    for (int i = 0; i < faixaPreco; i++) {
        strcat(buffer, "$"); //Concatenar '$' no buffer.
    }
}

//Método parse para restaurante.
Restaurante parseRestaurante (char *str) {
    //Ponteiro para o restaurante.
    Restaurante r; 

    //Delimitador para separar os campos do restaurante. 
    char *parte = strtok(str, ","); //Delimitador = ','

    //Variáveis para armazenar os campos do restaurante.
    r.id = atoi(parte); //de string para inteiro.
    parte = strtok(NULL, ","); //Próximo campo.
 
    strcpy(r.nome, parte); //Copiar o nome para a variável.
    parte = strtok(NULL, ","); 

    strcpy(r.cidade, parte); 
    parte =strtok(NULL, ",");

    r.capacidade = atoi(parte); //String para inteiro.
    parte = strtok(NULL, ",");

    r.avaliacao = atof(parte); //string para double.
    parte = strtok(NULL, ",");

    r.qntdTipos = parseTiposCozinha(parte, r.tiposCozinha); //tipos de cozinha e a quantidade.
    parte = strtok(NULL, ",");

    r.faixaPreco = parseFaixaPreco(parte); 
    parte = strtok(NULL, ",");

    r.horarioAbertura = parseHora(parte); //String para Hora.
    parte = strtok(NULL, ",");
    r.horarioFechamento = parseHora(parte);
    parte = strtok(NULL, ",");

    r.dataAbertura = parseData(parte); //String para Data.   
    parte = strtok(NULL, ",");

    r.aberto = (strcmp(parte, "true") == 0); //String para booleano, retornar true ou false (aberto ou não). 

    //Retornar o restaurante com os campos convertidos.
    return r; 
}

//Procedimento para formatar o restaurante.
void formatarRestaurante (Restaurante *r, char *buffer) {
    //Buffer (array) auxiliares. 
    char arrayData[11]; 
    char arrayHoraAbertura[6]; 
    char arrayHoraFechamento[6];

    //Chamar os procedimentos para formatar a data e as horas.
    formatarData(&r->dataAbertura, arrayData); //Colocando no buffer auxiliar o endereço formatado, que esta apontando pro conteúdo daquele endereço.
    formatarHora(&r->horarioAbertura, arrayHoraAbertura);
    formatarHora(&r->horarioFechamento, arrayHoraFechamento);

    //Buffer para tipos de cozinha. 
    char arrayTipos[200]; ;
    formatarTiposCozinha(r->tiposCozinha, r->qntdTipos, arrayTipos); 

    //Buffer para faixa de preço.
    char arrayFaixaPreco[5];
    formatarFaixaPreco(r->faixaPreco, arrayFaixaPreco);
    
    //Formatar o restaurante no buffer principal.
    sprintf(buffer, "[%d ## %s ## %s ## %d ## %.1lf ## %s ## %s ## %s-%s ## %s ## %s]",
    r->id, r->nome, r->cidade, r->capacidade, r->avaliacao, arrayTipos, arrayFaixaPreco, arrayHoraAbertura, arrayHoraFechamento, arrayData, r->aberto ? "true" : "false"); //Abre e fecha o restaurante, se aberto = true, senão false.
}

//Procedimento para obter o tamanho da string para depois limpar o \n do final da linha.
int obterTamanhoString (char *str) {
    int tamanho = 0; 

    while (str[tamanho] != '\0') {
        tamanho++; 
    }

    return tamanho; 
}

//Procedmimento para limpar o \n do final da linha. 
void limparNewLine (char *str) {
    int tamanho = obterTamanhoString(str); 

    //Verificar se o último caractere é '\n' e substituí-lo por '\0'.
    if (tamanho > 0 && str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

//Struct para coleção de restaurantes.
typedef struct {
    //Atributos. 
    Restaurante *restaurantes; 
    int qntdRestaurantes; 
} ColecaoRestaurantes;

//Método para ler as linhas do arquivo. 
void ler_csv_colecao(ColecaoRestaurantes *colecao, char *path) {
    //Abrir o arquivo para leitura. 
    FILE *arq = fopen(path, "r"); //r = read (leitura)

    //Verificar se o arquivo foi aberto com sucesso.
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }

    //Inicializar quantidade de restaurantes na coleção e alocar dinamicamente o array de restaurantes.
    colecao->qntdRestaurantes = 0; 
    colecao->restaurantes = malloc(1000 * sizeof(Restaurante)); //Alocação para 1000 restaurantes, com tamanho do struct Restaurante.

    //Buffer para ler as linhas do arquivo.
    char linha[500]; 

    //Loop para ler as linhas do arquivo.
    while (fgets(linha, sizeof(linha), arq)) {
        //Remover o '\n' do final da linha
        limparNewLine(linha);

        //Chamar o método parse para converter a linha em um restaurante e adicionar à coleção.
        Restaurante r = parseRestaurante(linha); 

        //Adicionar o restaurante à coleção e incrementar a quantidade de restaurantes.
        colecao->restaurantes[colecao->qntdRestaurantes] = r; 
        colecao->qntdRestaurantes++;
    }

    //Fechar o arquivo.
    fclose(arq);
}

//Procedimento para troca de restaurantes do array. 
void troca(Restaurante *a, Restaurante *b) {
    //Trocar os restaurantes. 
    Restaurante temp = *a; 
    *a = *b; 
    *b = temp; 
}

//Ordenação por Seleção.
void SelectionSort (Restaurante *array, int n, int *comparacoes, int *movimentacoes) { 
    //Inicializar variáveis. 
    *comparacoes = 0;
    *movimentacoes = 0;

    //Percorrer o array de restaurantes até n - 1. 
    for (int i = 0; i < n - 1; i++) {
        //Menor índice. 
        int menor = i; 

        //Percorrer o array a partir do próximo elemento.
        for (int j = i + 1; j < n; j++) {
            //Contar as comparações.
            (*comparacoes)++;

            //Comparar os nomes dos restaurantes para encontrar o menor.
            if (strcmp(array[j].nome, array[menor].nome) < 0) { //strcmp retorna um valor negativo se a string j for menor que a string menor.
                menor = j; //Atualizar o índice do menor restaurante.
            }
        }

        //Chamar o procedimento de troca. 
        troca (&array[i], &array[menor]); //Trocar o índice atual com o menor encontrado.
        (*movimentacoes) += 3; //Cada troca envolve 3 movimentações (temp, a, b).
    }
}

//Procedimento para criar o arquivo log com os resultados da ordenação.
void criarArqLog (char *matricula, int comparacoes, int movimentacoes, double tempoGasto) {
    //Criar o nome do arquivo. 
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s_selecao.txt", matricula); //Nome do arquivo = matrícula + " selecao.txt".

    //Abrir o arquivo para escrita. 
    FILE *arq = fopen(nomeArquivo, "w"); //w = write (escrita) 

    //Verificar se o arquivo foi aberto 
    if (arq == NULL) printf("Erro ao criar o arquivo de log.\n");

    //Escrever os resultados no arquivo. 
    fprintf(arq, "%s\t%d\t%d\t%lf", matricula, comparacoes, movimentacoes, tempoGasto);

    //Fechar arq
    fclose(arq); 
}

//Main, parte principal 
int main () {
   //Criar a colelecao de Restaurantes.
   ColecaoRestaurantes colecao; 

   //Criar um array de restaurantes selecionados e a quantidade de restaurantes selecionados.
   Restaurante selecionados[1000]; 
   int n = 0; 

   //Chamar o método para ler os restaurantes do arquivo CSV.
   ler_csv_colecao(&colecao, "/tmp/restaurantes.csv"); 

   //Ler entrada. 
   char linha[100];  
   fgets(linha, sizeof(linha), stdin); //Ler a linha de entrada do usuário.
   limparNewLine(linha); //Limpar o '\n' do final da linha.

   //Loop até o final do arquivo de entrada.
   while (strcmp(linha, "-1") != 0) {
        //Converter id. 
        int id = atoi(linha);

        //Ve se encontra o restaurante. 
        Restaurante *encontrado = NULL; //até que encontre o restaurante, o ponteiro é NULL.

        //Loop para encontrar o restaurante com o id correspondente na coleção.
        for (int i = 0; i < colecao.qntdRestaurantes; i++) {
            //Verificar se o id atual bate com o id procurado.
            if (colecao.restaurantes[i].id == id) {
                encontrado = &colecao.restaurantes[i];
            } 
        }

        //Verificar se encontrou o restaurante e adicionar no array. 
        if (encontrado != NULL) {
            selecionados[n] = *encontrado; 
            n++; //Aumentar a qntd de restaurantes selecionados. 
        }

        //Ler a próxima linha de entrada do usuário.
        fgets(linha, sizeof(linha), stdin);
        limparNewLine(linha);
   }
   //Inicializar variáveis para contagem de comparações e movimentações.
   int comparacoes = 0, movimentacoes = 0;

   //Contar o tempo de execução da ordenação.
   clock_t inicio = clock(); //Tempo Inicial. 

   //Chamar o procedimento de ordenação. 
   SelectionSort(selecionados, n, &comparacoes, &movimentacoes); 

   clock_t fim = clock(); //Tempo Final.

    //Calcular o tempo gasto em segundos.
    double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

   //Chamar o procedimento que cria o arquivo log
   criarArqLog("MINHA_MATRICULA", comparacoes, movimentacoes, tempoGasto); //Substituir pela minha matrícula, 889989. 

   //Loop para imprimir os restaurantes selecionados e ordenados.
   for (int i = 0; i < n; i++) {
    //Buffer para formatar
    char buffer[1000]; 

    //Chamar o procedimento para formatar o restaurante no buffer.
    formatarRestaurante(&selecionados[i], buffer);

    //Imprimir o restaurante formatado.
    printf("%s\n", buffer);
   }

   return 0; 
}