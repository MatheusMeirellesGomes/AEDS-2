/*Exercício para apenas inserir elementos na árvore. */

//Classe para um Nó da árvore. 
class No {
    //Atributos do nó. 
    int elemento; //um valor
    No esq; //referência para esquerda
    No dir; //referência para direita

    //Construtor para cada Nó
    public No(int x) {
        //Atribuir
        this.elemento = x; 
        //Tanto esquerda, quanto direita apontam para null antes de inserir.
        this.esq = null; 
        this.dir = null; 
    }
}

//Classe para Árvore
class ArvoreBinaria {
    //Atributos da árvore. 
    No raiz; //Vai ter uma raiz. 

    //Construtor
    public ArvoreBinaria() {
        raiz = null; 
    }

    //Método publico para inserir um nó
    public void inserir (int x) { //x = elemento que vai ser inserido.
        //Chamar o private para inserir o elemento na raiz da árvore.
        raiz = inserir(raiz, x); 
    }

    //Método private para fazer a recursão
    private No inserir (No i, int x) { // i = raiz / x = elemento
        //Caso base (Se não tiver nenhum elemento)
        if (i == null) {
            //Necessário criar um novo nó para inserir o elemento.
            i = new No (x); //i que é a raiz vai receber o elemento, ja que a lista está vazia.
        }
        
        //Se o elemento que vai ser inserido, for menor que o elemento da raiz. 
        else if (x < i.elemento) {
            //Vai ser inserido a esquerda 
            i.esq = inserir(i.esq, x); 
        }

        //Se o elemento que vai ser inserido, for maior que o elemento da raiz
        else if (x > i.elemento) {
            //Vai ser inserido a direita
            i.dir = inserir(i.dir, x); 
        }

        //Retorna a raiz da subárvore atualizada
        return i; 
    }
}