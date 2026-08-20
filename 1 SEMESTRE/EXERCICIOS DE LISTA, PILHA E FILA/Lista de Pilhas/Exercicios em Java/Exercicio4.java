/*Considere uma lista de pilhas, implemente o método CelulaLista primeiraPilhaPar(), que deve retornar a primeira célula da lista
que possui uma quantidade par de elementos.*/

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

CelulaLista primeiraPilhaPar() {
    //Percorrer a lista
    for (CelulaLista i = inicio; i != null; i = i.prox) {
        //Contador para a quantidade de elementos da pilha. 
        int qntdElementos = 0; 

        //Percorrer os elementos da pilha. 
        for (CelulaPilha j = i.topo; j != null; j = j.prox) {
            qntdElementos++; 
        }   

        //Verificar se a quantidade de elementos é par. 
        if (qntdElementos % 2 == 0) {
            //Se for par, retornar a pilha que possui quantidade par. 
            return i;  
        }
    }

    //Caso não tenha, retorna false. 
    return null; 
}