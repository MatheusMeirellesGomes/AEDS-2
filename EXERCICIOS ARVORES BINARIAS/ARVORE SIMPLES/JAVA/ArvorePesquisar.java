/*Exercício para inserir e pesquisar elementos numa árvore binária 
- Método public ele serve como uma porta de entrada, escondendo a complexidade, mantendo uma interface mais limpa
- Método private serve como um motor interno recursivo, onde vai realizar as operações, manipulação de nós, lógica interna
- Complexidade do método pesquisar: A cadade busca que vc faz na árvore, eliminamos metade dela
=> Melhor Caso: Uma árvore balanceada, onde vamos ter 0 (log n)
=> Pior Caso: Uma árvore que vai se tornar uma lista com a busca, onde teremos O (n)
*/

//Classe para cada nó da árvore
class No {
    //Atributos
    int elemento; 
    No esq; 
    No dir; 

    //Construtor
    public No(int x) {
        //Atribuir
        this.elemento = x; 
        this.esq = null; 
        this.dir = null; 
    }
}

//Classe para a árvore binária. 
class Arvore {
    No raiz; 

    //Construtor
    public Arvore() {
        raiz = null; 
    }

    //Método public inseri 
    public void inserir(int x) {
        //Chamar o método private para inserir o elemento
        raiz = inserir(raiz, x); 
    }

    //Método private inserir. 
    private No inserir(No i, int x) {
        //Caso base, se a árvore estiver vazia
        if (i == null) {
            //Cria-se novo nó com o elemento sendo inserido como raiz
            i = new No(x); 
        } 

        //Se o elemento for menor que a raiz
        else if (x < i.elemento) {
            //Insere na esquerda.
            i.esq = inserir(i.esq, x); 
        }

        //Se o elemento for maior que a raiz
        else if (x > i.elemento) {
            i.dir = inserir(i.dir, x); 
        }

        //Retornar o raiz da subárvore
        return i; 
    }

    //Método public pesquisar que precisa ser boolean, já que vai retorar true ou false
    public boolean pesquisar(int x) {
        //Retornar o método private pesquisar
        return pesquisar(raiz, x); 
    }

    //Método private pesquisar, que tbm precisa ser boolean
    private boolean pesquisar(No i, int x) {
        //Caso base se a árvore estiver vazia
        if (i == null) {
            //Retornar falso
            return false; 
        }

        //Se o elemento desejado for a raiz
        else if (x == i.elemento) {
            //Retornar verdadeiro, dizendo que achou
            return true; 
        }

        //Se o elemento for menor que a raiz
        else if (x < i.elemento) {
            //Retornar a pesquisa dos elementos da esquerda (menores) até encontrar
            return pesquisar(i.esq, x); 
        }

        //Se o elemento for maior que a raiz
        else {
            //Retornar a pesquisa dos elementos da direita (maiores) até encontrar
            return pesquisar(i.dir, x); 
        }
        //Não é necessário retornar nada, porque quando achar o elemento retorna true
    }
}