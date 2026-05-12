/*Conside uma lista de pilhas, dessa vez, em vez de retornar a maior pilha, o método agora vai retornar a menor pilha, ou seja, a pilha
que possui a menor quantidade de elementos. */

//Classe para Lista, que vai ter um ponteiro para inicio e outro para o fim da lista. 
class Lista {
    CelulaLista inicio; 
    CelulaLista fim; 
}

//Classe para a célula da lista, que vai cada nó vai ter um topo e da pilha e um prox, apontando pro próximo elemento da lista. 
class CelulaLista {
    CelulaPilha topo; 
    CelulaLista prox; 
}

//Classe para a célula da pilha, que vai ter um elemento, e um prox, apontando para o próximo elemento da pilha. 
class CelulaPilha {
    int elemento; 
    CelulaPilha prox; 
}

//Método para procurar e retornar a menor pilha. 
CelulaLista menorPilha() {
    //Inicializar variável 
    CelulaLista menor = inicio; //Vai ter a célula da lista (nó) que possui a menor quantidade. 
    int menorQntd = 0; //Variável para salvar a quantidade de cada pilha. 

    //Percorrer a primeira pilha para ter base para comparar com as outras. 
    for (CelulaPilha k = inicio.topo; k != null; k = k.prox) {
        menorQntd++; //Incrementar o contador. 
    }

    //Percorrer primeiramente a lista, a partir da segunda pilha, já que a primeira já foi verificada
    for (CelulaLista i = inicio.prox; i != null; i = i.prox) {
        //Variável para contar a quantidade atual de elementos de cada pilha. 
        int qntdAtual = 0; 
        
        //Percorrer os elementos da pilha até que seja diferente de null. 
        for (CelulaPilha j = i.topo; j != null; j = j.prox) {
            qntdAtual++; //Incrementar o contador
        }

        //Verificar se a quantidade atual é menor que a menor quantidade. 
        if (qntdAtual < menorQntd) {
            menorQntd = qntdAtual; 
            menor = i; 
        }
    }

    //Retornar a célula da lista com a menor quantidade de elementos de cada pilha. 
    return menor; 
}