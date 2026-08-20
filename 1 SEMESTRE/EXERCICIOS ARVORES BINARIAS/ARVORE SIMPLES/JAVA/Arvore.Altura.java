/*Método para calcular a altura de uma árvore.*/

class No {
    int elemento; 
    No esq; 
    No dir; 

    public No (int x) {
        this.elemento = x; 
        this.esq = null; 
        this.dir = null; 
    }
}

class Arvore {
    No raiz; 

    public Arvore() {
        this.raiz = null; 
    }

    //Método public e private para calcular a altura de uma árvore
    public int altura() {
        //Retornar a altura da árvore
        return altura(raiz); 
    }

    private int altura(No i) {
        //Caso base, se a árvore estiver vazia
        if (i == null) {
            return -1; //altura da árvore sem nada
        }

        //Calcular esquerda da raiz
        int alturaEsq = altura(i.esq); 

        //Calcular direita da raiz
        int alturaDir = altura(i.dir); 

        //Retornar a recursão
        return Math.max(alturaEsq, alturaDir) + 1; 
    }
}