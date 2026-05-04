/*Questao 8 - Ordenação por Quicksort*/
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#include <time.h>

//Struct para Data. 
typedef struct {
    int dia; 
    int mes; 
    int ano; 
} Data; 

//Método parse para Data. 
Data parseData (char *str) {
    int ano, mes, dia;
    sscanf(str, "%d-%d-%d", &ano, &mes, &dia);

    Data d;
    d.ano = ano;
    d.mes = mes;
    d.dia = dia;

    return d;
}

//Procedimento para formatar a data. 
void formatarData(Data *d, char *buffer) {
    sprintf(buffer, "%02d/%02d/%04d", d->dia, d->mes, d->ano);
}

//Struct para Hora. 
typedef struct {
    int hora; 
    int minuto; 
}Hora; 

//Método parse para Hora. 
Hora parseHora (char *str) {
    int hora, minuto;
    sscanf(str, "%d:%d", &hora, &minuto);

    Hora h;
    h.hora = hora;
    h.minuto = minuto;

    return h;
}

//Procedimento para formatar a hora. 
void formatarHora(Hora *h, char *buffer) {
    sprintf(buffer, "%02d:%02d", h->hora, h->minuto);
}

//Struct para Restaurante.
typedef struct {
    int id; 
    char nome[100]; 
    char cidade[100]; 
    int capacidade; 
    double avaliacao; 
    char tiposCozinha[5][50];
    int qntdTipos;
    int faixaPreco; 
    Hora horarioAbertura; 
    Hora horarioFechamento; 
    Data dataAbertura; 
    bool aberto;  
} Restaurante; 

//Método parse para tipos de cozinha.
int parseTiposCozinha (char *str, char tipos[5][50]) {
    int qntd = 0;
    char *parte = strtok(str, ";");

    while (parte != NULL && qntd < 5) {
        while (*parte == ' ') parte++;
        strcpy(tipos[qntd++], parte);
        parte = strtok(NULL, ";");
    }

    return qntd;
}

//Método parse para faixa de preço.
int parseFaixaPreco (char *str) {
    int faixa = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '$') faixa++;

    return faixa;
}

//Método parse para restaurante.
Restaurante parseRestaurante (char *str) {
    Restaurante r;

    char *parte = strtok(str, ",");

    r.id = atoi(parte);
    parte = strtok(NULL, ",");
    strcpy(r.nome, parte);

    parte = strtok(NULL, ",");
    strcpy(r.cidade, parte);

    parte = strtok(NULL, ",");
    r.capacidade = atoi(parte);

    parte = strtok(NULL, ",");
    r.avaliacao = atof(parte);

    parte = strtok(NULL, ",");
    r.qntdTipos = parseTiposCozinha(parte, r.tiposCozinha);

    parte = strtok(NULL, ",");
    r.faixaPreco = parseFaixaPreco(parte);

    parte = strtok(NULL, ",");
    r.horarioAbertura = parseHora(parte);

    parte = strtok(NULL, ",");
    r.horarioFechamento = parseHora(parte);

    parte = strtok(NULL, ",");
    r.dataAbertura = parseData(parte);

    parte = strtok(NULL, ",");
    r.aberto = (strcmp(parte, "true") == 0);

    return r;
}

//Procedimento para formatar o restaurante.
void formatarRestaurante (Restaurante *r, char *buffer) {
    char data[11], hA[6], hF[6], tipos[200], preco[5];

    formatarData(&r->dataAbertura, data);
    formatarHora(&r->horarioAbertura, hA);
    formatarHora(&r->horarioFechamento, hF);

    strcpy(tipos, "[");
    for (int i = 0; i < r->qntdTipos; i++) {
        strcat(tipos, r->tiposCozinha[i]);
        if (i < r->qntdTipos - 1) strcat(tipos, ", ");
    }
    strcat(tipos, "]");

    preco[0] = '\0';
    for (int i = 0; i < r->faixaPreco; i++) strcat(preco, "$");

    sprintf(buffer, "[%d ## %s ## %s ## %d ## %.1lf ## %s ## %s ## %s-%s ## %s ## %s]",
    r->id, r->nome, r->cidade, r->capacidade, r->avaliacao,
    tipos, preco, hA, hF, data, r->aberto ? "true" : "false");
}

//Struct para coleção de restaurantes.
typedef struct {
    Restaurante *restaurantes; 
    int qntdRestaurantes; 
} ColecaoRestaurantes;

//Método para ler o CSV.
void ler_csv_colecao(ColecaoRestaurantes *colecao, char *path) {
    FILE *arq = fopen(path, "r");

    colecao->qntdRestaurantes = 0;
    colecao->restaurantes = malloc(1000 * sizeof(Restaurante));

    char linha[500];
    fgets(linha, sizeof(linha), arq);

    while (fgets(linha, sizeof(linha), arq)) {
        linha[strcspn(linha, "\n")] = '\0';
        colecao->restaurantes[colecao->qntdRestaurantes++] = parseRestaurante(linha);
    }

    fclose(arq);
}

//Procedimento para troca.
void troca(Restaurante *a, Restaurante *b, int *movimentacoes) {
    Restaurante temp = *a;
    *a = *b;
    *b = temp;
    (*movimentacoes) += 3;
}

//Método para comparar restaurantes.
int comparar(Restaurante *a, Restaurante *b, int *comparacoes) {
    (*comparacoes)++;

    if (a->avaliacao < b->avaliacao) return -1;
    if (a->avaliacao > b->avaliacao) return 1;

    (*comparacoes)++;
    return strcmp(a->nome, b->nome);
}

//Partição do Quicksort.
int particionar(Restaurante *array, int esq, int dir, int *comparacoes, int *movimentacoes) {
    Restaurante pivo = array[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (comparar(&array[j], &pivo, comparacoes) <= 0) {
            i++;
            troca(&array[i], &array[j], movimentacoes);
        }
    }

    troca(&array[i + 1], &array[dir], movimentacoes);
    return i + 1;
}

//Quicksort.
void quicksort(Restaurante *array, int esq, int dir, int *comparacoes, int *movimentacoes) {
    if (esq < dir) {
        int p = particionar(array, esq, dir, comparacoes, movimentacoes);
        quicksort(array, esq, p - 1, comparacoes, movimentacoes);
        quicksort(array, p + 1, dir, comparacoes, movimentacoes);
    }
}

//Procedimento para criar o arquivo log.
void criarArqLog (char *matricula, int comparacoes, int movimentacoes, double tempoGasto) {
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s_quicksort.txt", matricula);

    FILE *arq = fopen(nomeArquivo, "w");

    fprintf(arq, "%s\t%d\t%d\t%lf", matricula, comparacoes, movimentacoes, tempoGasto);

    fclose(arq); 
}

//Main, parte principal 
int main () {
   ColecaoRestaurantes colecao; 

   Restaurante selecionados[1000]; 
   int n = 0; 

   ler_csv_colecao(&colecao, "/tmp/restaurantes.csv"); 

   char linha[100];  
   fgets(linha, sizeof(linha), stdin);
   linha[strcspn(linha, "\n")] = '\0';

   while (strcmp(linha, "-1") != 0) {
        int id = atoi(linha);

        for (int i = 0; i < colecao.qntdRestaurantes; i++) {
            if (colecao.restaurantes[i].id == id) {
                selecionados[n++] = colecao.restaurantes[i];
                break;
            }
        }

        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';
   }

   int comparacoes = 0, movimentacoes = 0;

   clock_t inicio = clock(); 

   quicksort(selecionados, 0, n - 1, &comparacoes, &movimentacoes); 

   clock_t fim = clock(); 

   double tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

   criarArqLog("889989", comparacoes, movimentacoes, tempoGasto);

   char buffer[1000];

   for (int i = 0; i < n; i++) {
        formatarRestaurante(&selecionados[i], buffer);
        printf("%s\n", buffer);
   }

   return 0; 
}