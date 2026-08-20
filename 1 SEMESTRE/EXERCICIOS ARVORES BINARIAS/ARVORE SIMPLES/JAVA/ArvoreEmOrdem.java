/* Exercício agora para adicionar o método em ordem, que como o nome diz, é basicamente imprimir os elementos em ordem, 
começando da esquerda, indo pra raiz, e por fim direita.
Em ordem, imprime sempre do menor elemento da árvore para o maior. 
esq < raiz < dir.
 */

//Classe para cada nó 
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

//Classe para árvore
class Arvore {
    No raiz; 

    public Arvore() {
        raiz = null; 
    }

    public void inserir(int x) {
        raiz = inserir(raiz, x); 
    }

    private No inserir(No i, int x) {
        if (i == null) {
            i = new No(x); 
        } else if (x < i.elemento) {
            i.esq = inserir(i.esq, x); 
        } else if (x > i.elemento) {
            i.dir = inserir(i.dir, x); 
        }

        return i; 
    }

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

    public void preOrdem() {
        if (raiz == null) {
            System.out.println("Arvore Vazia"); 
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

    //Método public para emOrdem
    public void emOrdem() {
        //Se a árvore estiver vazia
        if (raiz == null) {
            //Mensagem de erro
            System.out.println("Vazia"); 
        } else {
            //Se ela não estiver
            emOrdem(raiz); //Chama o private em orde, que vai imprimir do menor para o maior
        }
    }

    //Método private para emOrdem
    private void emOrdem(No i) {
        if (i != null) {
            //Percorrer elementos da esquerda
            emOrdem(i.esq); 
            
            //Imprimir raiz já que ela é maior que os elementos da esquerda
            System.out.print(i.elemento + " "); 
            
            //Percorrer elementos da direita
            emOrdem(i.dir); 
        }
    }
}