/*Exercício para adicionar o método pós ordem na árvore. 
Pós ordem vc percorre toda a esquerda, depois percorre toda a direita, depois imprime a raiz
esquerda -> direita -> raiz
 */ 

class No {
    int elemento; 
    No esq; 
    No dir; 

    public No(int x) {
        this.elemento = x; 
        this.esq = null; 
        this.dir = null;
    }
}

class Arvore {
    No raiz; 

    public Arvore() {
        raiz = null; 
    }

    //Inserir
    public void inserir(int x) {
        raiz = inserir(raiz, x); 
    }

    private No inserir (No i, int x) {
        if (i == null) {
            i = new No(x); 
        } else if (x < i.elemento) {
            i.esq = inserir(i.esq, x); 
        } else if (x > i.elemento) {
            i.dir = inserir(i.dir, x); 
        }

        return i; 
    }

    //Pesquisar
    public boolean pesquisar(int x) {
        return pesquisar(raiz, x); 
    }

    private boolean pesquisar(No i, int x) {
        if (i == null) {
            return false; 
        } else if (x == i.elemento) {
            return true; 
        } else if (x < i.elemento) {
            return pesquisar(i.esq, x); 
        } else {
            return pesquisar(i.dir, x); 
        }
    }

    //Pré Ordem: raiz -> esquerda -> direita
    public void preOrdem() {
        if (raiz == null) {
            System.out.println("Vazia"); 
        } else {
            preOrdem(raiz); 
        }
    }
    
    private void preOrdem(No i) {
        if (i != null) {
            System.out.print(i.elemento + " "); 
            preOrdem(i.esq); 
            preOrdem(i.dir); 
        }
    }

    //Em ordem: esquerda -> raiz -> direita
    public void emOrdem() {
        if (raiz == null) {
            System.out.println("Vazia"); 
        } else {
            emOrdem(raiz); 
        }
    }

    private void emOrdem(No i) {
        if (i != null) {

            emOrdem(i.esq); 
            System.out.print(i.elemento + " "); 
            emOrdem(i.dir); 
        }
    }

    //Pós ordem: esquerda -> direita -> raiz
    public void posOrdem() {
        if (raiz == null) {
            System.out.println("Vazia"); 
        } else {
            posOrdem(raiz); 
        }
    }

    private void posOrdem(No i) {
        if (i != null) {
            posOrdem(i.esq); 
            posOrdem(i.dir); 
            System.out.print(i.elemento + " "); 
        }
    }
}