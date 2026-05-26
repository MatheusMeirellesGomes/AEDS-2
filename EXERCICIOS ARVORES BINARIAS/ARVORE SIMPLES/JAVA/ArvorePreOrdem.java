/*Método para realizar o pré ordem de uma árvore
Pré ordem são basicamente imprimir os elementos começando pela raiz, partindo para os elementos da esquerda e por fim os elementos da direita
 */

//Classe para cada nó 
class No {
    //Elementos
    int elemento; 
    No esq; 
    No dir; 

    //Construtor 
    public No (int x) {
        //Atribuindo 
        this.elemento = x; 
        this.esq = null; 
        this.dir = null; 
    }
}

//Classe para árvore
class Arvore {
    //Elementos
    No raiz; 

    //Construtor
    public Arvore() {
        raiz = null; 
    }

    //Método public inserir
    public void inserir(int x) {
        //Chamar o método private para realizar as op
        raiz = inserir(raiz, x); 
    }

    //Método private inserir
    private No inserir(No i, int x) {
        //Caso base 
        if (i == null) {
            //Criar novo no
            i = new No(x); 
        } 

        //Se for menor
        else if (x < i.elemento) {
            //Inserir na esquerda da raiz
            i.esq = inserir(i.esq, x); 
        }

        //Se for maior
        else if (x > i.elemento) {
            //Inserir na direita da raiz
            i.dir = inserir(i.dir, x); 
        }

        //Retornar a raiz
        return i; 
    }

    //Método public pesquisar
    public boolean pesquisar(int x) {
        //Retornar chamando o método private
        return pesquisar(raiz, x); 
    }

    //Método private pesquisar
    private boolean pesquisar(No i, int x) {
        //Caso base
        if (i == null) {
            //Retornar falso
            return false; 
        }

        //Se for igual a raiz
        else if (x == i.elemento) {
            //Retorna verdadeiro
            return true; 
        }

        //Se for menor que a raiz
        else if (x < i.elemento) {
            //Procurar na esquerda
            return pesquisar(i.esq, x); 
        }

        //Se for maior que a raiz 
        else {
            //Procurar na direita
            return pesquisar(i.dir, x); 
        }
    }

    //Método public pré-ordem
    public void preOrdem() {
        //Chamando o private pre ordem passando so a raiz
        preOrdem(raiz); 
    }

    //Método private para imprimir na pré-ordem
    private void preOrdem(No i) {
        //Se a árvore estiver vazia
        if (i == null) {
            //Mensagem de erro
            System.out.println("Arvore Vazia"); 
        }   

        //Se tiver elemento
        if (i != null) {
            //Imprimir primeiramente a raiz
            System.out.print(i.elemento + " "); 
            
            //Caminhar pelos elementos a esquerda e imprimir
            preOrdem(i.esq); 

            //Depois caminhar pelos elementos a direita e imprimir
            preOrdem(i.dir); 
        }
    }
}