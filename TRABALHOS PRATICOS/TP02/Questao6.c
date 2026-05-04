/*Código de Pesquisa Binária em C*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//Struct Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

//Parse Data
Data parseData(char *str) {
    int ano, mes, dia;
    sscanf(str, "%d-%d-%d", &ano, &mes, &dia);
    Data d = {dia, mes, ano};
    return d;
}

//Struct Hora
typedef struct {
    int hora;
    int minuto;
} Hora;

//Parse Hora
Hora parseHora(char *str) {
    int h, m;
    sscanf(str, "%d:%d", &h, &m);
    Hora hora = {h, m};
    return hora;
}

//Struct Restaurante
typedef struct {
    int id;
    char nome[100];
    char cidade[100];
    int capacidade;
    double avaliacao;
    char tipos[5][50];
    int qntdTipos;
    int faixaPreco;
    Hora abertura;
    Hora fechamento;
    Data data;
    bool aberto;
} Restaurante;

//Parse tipos
int parseTipos(char *str, char tipos[5][50]) {
    int qtd = 0;
    char *parte = strtok(str, ";");

    while (parte != NULL) {
        while (*parte == ' ') parte++;
        strcpy(tipos[qtd++], parte);
        parte = strtok(NULL, ";");
    }
    return qtd;
}

//Parse restaurante
Restaurante parseRestaurante(char *linha) {
    Restaurante r;
    char *parte = strtok(linha, ",");

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
    r.qntdTipos = parseTipos(parte, r.tipos);

    parte = strtok(NULL, ",");
    r.faixaPreco = strlen(parte);

    parte = strtok(NULL, ",");
    r.abertura = parseHora(parte);

    parte = strtok(NULL, ",");
    r.fechamento = parseHora(parte);

    parte = strtok(NULL, ",");
    r.data = parseData(parte);

    parte = strtok(NULL, ",");
    r.aberto = (strcmp(parte, "true") == 0);

    return r;
}

//Coleção
typedef struct {
    Restaurante restaurantes[2000];
    int tamanho;
} Colecao;

//Ler CSV
void lerCsv(Colecao *c, char *path) {
    FILE *arq = fopen(path, "r");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    c->tamanho = 0;
    char linha[500];

    fgets(linha, sizeof(linha), arq); //pular cabeçalho

    while (fgets(linha, sizeof(linha), arq)) {
        linha[strcspn(linha, "\n")] = '\0';
        c->restaurantes[c->tamanho++] = parseRestaurante(linha);
    }

    fclose(arq);
}

//Troca
void troca(Restaurante *a, Restaurante *b) {
    Restaurante temp = *a;
    *a = *b;
    *b = temp;
}

//Selection Sort (necessário antes da binária)
void selectionSort(Restaurante *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j].nome, arr[menor].nome) < 0) {
                menor = j;
            }
        }

        troca(&arr[i], &arr[menor]);
    }
}

//Contador
int comparacoes = 0;

//Pesquisa Binária
int pesquisaBinaria(Restaurante *arr, int n, char *nome) {
    int esq = 0, dir = n - 1;

    while (esq <= dir) {
        int meio = (esq + dir) / 2;

        comparacoes++;

        int cmp = strcmp(arr[meio].nome, nome);

        if (cmp == 0) return meio;
        else if (cmp < 0) esq = meio + 1;
        else dir = meio - 1;
    }

    return -1;
}

//Criar log
void criarLog(char *matricula, int comparacoes, double tempo) {
    FILE *arq = fopen("matricula_binaria.txt", "w");
    fprintf(arq, "%s\t%d\t%lf", matricula, comparacoes, tempo);
    fclose(arq);
}

//Main
int main() {
    Colecao colecao;
    lerCsv(&colecao, "/tmp/restaurantes.csv");

    Restaurante selecionados[1000];
    int n = 0;

    //Entrada IDs
    int id;
    scanf("%d", &id);

    while (id != -1) {
        for (int i = 0; i < colecao.tamanho; i++) {
            if (colecao.restaurantes[i].id == id) {
                selecionados[n++] = colecao.restaurantes[i];
                break;
            }
        }
        scanf("%d", &id);
    }

    //Ordenar antes da binária
    selectionSort(selecionados, n);

    getchar(); //limpar buffer

    char nome[100];

    clock_t inicio = clock();

    //Busca
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    while (strcmp(nome, "FIM") != 0) {

        int resp = pesquisaBinaria(selecionados, n, nome);

        printf("%s\n", resp >= 0 ? "SIM" : "NAO");

        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    criarLog("MINHA_MATRICULA", comparacoes, tempo);

    return 0;
}