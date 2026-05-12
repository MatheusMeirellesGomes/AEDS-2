/*Considere uma lista de pilhas, e crie o método int somaMaiorPilha(), que retorne o nó da lista, com a maior soma dos elementos da pilha 
JAVA*/

class Lista {
    CelulaLista inicio; 
    CelulaLista fim; 
}

class CelulaLista {
    CelulaPilha topo; 
    CelulaLista prox; 
}

class CelulaPilha {
    int elemento; 
    CelulaPilha prox; 
}

//Função para retornar um inteiro, que é a soma da maior Pilha. 
int somaMaiorPilha() {
    //Variável para guardar a pilha com maior soma de seus elementos. 
    int maiorSoma = 0; 

    //Percorrer a lista por completo. 
    for (CelulaLista i = inicio; i != null; i = i.prox) {
        //Variável para somar os elementos da pilha. 
        int somaAtual = 0; 

        //Percorrer a pilha por completo e somar os elementos dela. 
        for (CelulaPilha j = i.topo; j != null; j = j.prox) {
            somaAtual += j.elemento; 
        }

        //Verificar se a soma atual dos elementos é maior que a soma total. 
        if (somaAtual > maiorSoma) {
            maiorSoma = somaAtual; 
        }
    }

    //Retornando inteiro e não célula. 
    return maiorSoma; 
}