/*Para finalizar o módulo de árvore simples, estrutura completa da árvore binária de busca */

//Classe para cada nó 
class No {
    //Atributos
    int elemento; 
    No esq; 
    No dir; 

    //Construtor
    public No (int x) {
        //Atribuir
        this.elemento = x; 
        this.esq = null; 
        this.dir = null; 
    }
}

//Classe para árvore
class Arvore {
    //Atributo
    No raiz; 

    //Construtor
    public Arvore() {
        this.raiz = null; 
    }

    //Método public e private Inserir
    public void inserir(int x) {
        //Chamar private
        raiz = inserir(raiz, x); 
    }

    private No inserir (No i, int x) {
        //Se estiver vaziza
        if (i == null) {
            i = new No(x); //Criar nova raiz
        } else if (x < i.elemento) { 
            i.esq = inserir(i.esq, x); //Inserir na esquerda, se x for menor que a raiz. 
        } else if (x > i.elemento) {
            i.dir = inserir(i.dir, x); //Inserir na direita, se x for maior que a raiz.
        }

        //Retornar a raiz da sub-árvore
        return i; 
    }

    //Método public e private para pesquisar
    public boolean pesquisar(int x) {
        //Retornar a pesquisa do elemento
        return pesquisar(raiz, x); 
    }

    private boolean pesquisar(No i,int x) {
        //Se estiver vazia
        if (i == null) {
            return false; //retorna falso
        }

        //Se a raiz for o elemento procurado
        else if (x == i.elemento) {
            return true; //Retornar verdadeiro
        }

        //Se o elemento for menor que a raiz
        else if (x < i.elemento) {
            return pesquisar(i.esq, x); //Pesquisar o elemento na esquerda da raiz
        }

        //Se o elemento for maior que a raiz
        else {
            return pesquisar(i.dir, x); //Pesquisar elemento a direita da raiz
        }
    }

    //Método public e private para imprimir PRÉ-ORDEM
    public void preOrdem() {
        //Ver se ta vazia
        if (raiz == null) {
            System.out.println("Arvore Vazia");
        } else {
            //Passa somente a raiz
            preOrdem(raiz); 
        }
    }

    private void preOrdem(No i) {
        //Se não estiver vazia
        if (i != null) {
            //Primeiro imprimir raiz
            System.out.println(i.elemento + " "); 
            
            //Depois imprimir os elementos da esquerda, depois os da direita
            preOrdem(i.esq); 
            preOrdem(i.dir); 
        }
    }

    //Método public e private para imprimir EM-ORDEM
    public void emOrdem() {
        //Se estiver vazia
        if (raiz == null) {
            System.out.println("Arvore Vazia");
        } else {
            emOrdem(raiz); 
        }
    }

    private void emOrdem(No i) {
        if (i != null) {
            //Imprimir elementos da esquerda, raiz, e depois os da direita
            emOrdem(i.esq); 
            System.out.println(i.elemento + " ");
            emOrdem(i.dir); 
        }
    }

    //Método public e private para imprimir POS-ORDEM
    public void posOrdem() {
        if (raiz == null) {
            System.out.println("Arvore Vazia");
        } else {
            posOrdem(raiz); 
        }
    }

    private void posOrdem(No i) {
        if (i != null) {
            //Imprimir os da esquerda, depois os da direita e por fim a raiz
            posOrdem(i.esq); 
            posOrdem(i.dir);
            System.out.println(i.elemento + " "); 
        }
    }
}

//Classe principal 
public class ArvoreCompleta {
    //Main
    public static void main(String args[]) {
        //Criar o objeto árvore
        Arvore arvore = new Arvore(); //Do tipo árvore, classe acima desta.

        //Inserir elementos
        arvore.inserir(50);
        arvore.inserir(30);
        arvore.inserir(70);
        arvore.inserir(20);
        arvore.inserir(40);
        arvore.inserir(60);
        arvore.inserir(80);

        //Imprimir pré-ordem
        arvore.preOrdem();
        System.out.println();

        //Imprimir em orde
        arvore.emOrdem(); 
        System.out.println();

        //Imprimir pós-ordem
        arvore.posOrdem(); 
        System.out.println();

        //Pesquisar elementos
        arvore.pesquisar(40);
        arvore.pesquisar(100);
        System.out.println(); 
    }
}