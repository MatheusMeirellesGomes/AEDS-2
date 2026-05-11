/*Considere uma estrutura de Lista de Pilhas. Crie o método CelulaLista maiorPilha() na classe ListaPilha, que retorna a célula da Lista
que aponta para a pilha com o maior número de elementos. Caso tenham pilhas do mesmo tamanho, retornar a primeira que aparece */

//Criando uma classe para a Lista
class Lista {
    //Atributos da lista
    Celula inicio; 
    Celula fim; 
} 

//Criar outra classe para a célula da lista. 
class CelulaLista {
    //Atributos da célula
    CelulaPilha topo; 
    CelulaLista prox; 
}

//Criar outra classe para a célula da pilha. 
class CelulaPilha {
    //Atributos da célula da pilha. 
    int elemento; 
    CelulaPilha prox; 
}

CelulaLista maiorPilha() {
    //Criar variável para guardar a maior pilha encontrada. 
    CelulaLista maior = null;
    
    //Variável para guardar o número de elementos da maior pilha encontrada.
    int maiorQntd = 0; 

    //Percorrer a lista de pilhas para encontrar a maior pilha.
    for (CelulaLista i = inicio; i != null; i = i.prox) {
        //Contar o número de elementos na pilha atual. 
        int qntdAtual = 0; 
        for (CelulaPilha j = i.topo; j != null; j = j.prox) { //Percorrer a pilha do índice atual da lista, para ver quantos elementos tem.
            qntdAtual++; //Incrementar o contador para cada elemento. 
        }

        //Comparar o número de elementos da pilha atual com o maior encontrado até agora.
        if (qntdAtual > maiorQntd) {
            maiorQntd = qntdAtual; //Atualizar o maior número de elementos encontrado.
            maior = i; //Atualizar a maior pilha encontrada.
        }
    }

    //Retornar a maior pilha encontrada.
    return maior; 
}