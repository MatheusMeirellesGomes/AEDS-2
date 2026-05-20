/*Primeiro exercício de arvore binária em java. Este primeiro exercício é apenas para inserir elementos na árvore. 
- X: insere o número X;

- Pesquisar Y: pesquisa se o número Y está na árvore, imprimindo S caso verdadeiro e N caso contrário. O algoritmo de pesquisa deve imprimir cada nó visitado;

- PRE: imprime os elementos da árvore por caminhamento pré-ordem ou V se a árvore estiver vazia; Pré-ordem começa imprimindo a raiz
depois os elementos a esquerda e depois os elementos a direita.

- POS: imprime os elementos da árvore por caminhamento pós-ordem ou V se a árvore estiver vazia;
Pós-ordem começa imprimindo os elementos a esquerda, depois os elementos a direita e por último a raiz.

- EM: imprime os elementos da árvore por caminhamento em-ordem ou V se a árvore estiver vazia; 
Em-ordem começa imprimindo os elementos a esquerda, depois a raiz e por último os elementos a direita.
*/

import java.util.Scanner; 

//Classe para representar um nó da árvore
class No {
    //Atributos
    int elemento; 
    No esq, dir; 

    //Construtor
    public No (int elemento) {
        //Inicializar os atributos
        this.elemento = elemento; 
        this.esq = null; 
        this.dir = null; //Tanto esquerda quanto direita apontam para null. 
    }
}

//Classe para representar a árvore binária
class ArvoreBinaria {
    //Atributo
    No raiz; //Indicar a raiz da árvore. 

    //Construtor
    public ArvoreBinaria() {
        //Inicializar a árvore como vazia
        this.raiz = null; 
    }

    //Método public que vai chamar o método private. 
    public void inserir (int x) {
        //Inserir o elemento na raiz da árvore
        raiz = inserir(raiz, x); 
    }

    //Método private para inserir um elemento a partir de um nó
    private No inserir (No i, int x) {
        //Verificar se o nó aponta para null 
        if (i == null) {
            i = new No(x); //Criar um novo nó com o elemento x.
        } else if (x < i.elemento) { //Se o elemento x for menor que o elemento do nó i, inserir na esquerda. 
            i.esq = inserir(i.esq, x);
        } else if (x > i.elemento) {
            i.dir = inserir(i.dir, x); //Se o elemento x for maior que o elemento do nó i, inserir na direita.
        }

        //Retornar a raiz da subárvore (elemento que  vai ser inserido, ou na esquerda ou na direita)
        return i;
    }

    //Método public que chama o private, passando a raiz e o elemento a ser pesquisado.
    public boolean pesquisar (int x) {
        return pesquisar(raiz, x); 
    }

    //Método private que vai pesquisar o elemento. 
    private boolean pesquisar (No i, int x) {
        //Verificar se a raiz está apontando para null
        if (i == null) {
            return false; 
        } else if (x == i.elemento) { //Se o elemento x for igual a raiz da subárvore, retornar true.
            return true; 
        } else if (x < i.elemento) {
            return pesquisar(i.esq, x); //Se o elemento x for menor que a raiz da subárvore, pesquisar na esquerda.
        } else {
            return pesquisar(i.dir, x); //Se o elemento x for maior que a raiz da subárvore, pesquisar na direita.
        }
    }

    //Método public que chama o private, preOrdem, passando a raiz da árvore. 
    public void preOrdem() {
        preOrdem(raiz); 
    }

    //Método private para imprimir os elementos da árvore por caminhamento pré-ordem. 
    private void preOrdem (No i) {
        //Se a raiz apontar para null, imprimir V.
        if (i == null) {
            System.out.print("V");
        }

        //Se a raiz tiver algum elemento
        if (i != null) {
            System.out.print(i.elemento + " "); //Imprimir o elemento da raiz mais o espaço. 
            preOrdem(i.esq); 
            preOrdem(i.dir); 
        }
    }

    //Método public que chama o private, posOrdem, passando a raiz da árvore.
    public void posOrdem() {
        posOrdem(raiz); 
    }

    //Método private para imprimir os elementos da árvore por caminhamento pós-ordem.
    private void posOrdem (No i) {
        //Verificar se a raiz aponta para null 
        if (i == null) {
            System.out.print("V");
        }

        //Se a raiz tiver algum elemento
        if (i != null) {
            posOrdem(i.esq); 
            posOrdem(i.dir); 
            System.out.print(i.elemento + " "); //Imprimir o elemento da raiz mais o espaço. 
        }
    }

    //Método public que chama o private, emOrdem, passando a raiz da árvore.
    public void emOrdem() {
        emOrdem(raiz); 
    }

    //Método private para imprimir os elementos da árvore por caminhamento em-ordem.
    private void emOrdem (No i) {
        //Verificar se a raiz aponta para null
        if (i == null) {
            System.out.print("V");
        }

        //Se a raiz tiver algum elemento
        if (i != null) {
            emOrdem(i.esq);
            System.out.print(i.elemento + " "); 
            emOrdem(i.dir);
        }
    }
}

public class Exercicio1 {
    public static void main(String args[]) {
        //Criar uma nova árvore binária
        ArvoreBinaria arvore = new ArvoreBinaria(); 

        //Criar o objeto scanner
        Scanner sc = new Scanner(System.in);

        //Verificar a letra que o usuário digitou, que vai decidir a operação a ser realizada.
        while (sc.hasNext()) {
            //Ler a letra digitada pelo usuário.
            String letra = sc.next(); 

            //Se a letra for I de inserir. 
            if (letra.equals("I")) {
                int x = sc.nextInt(); //Ler o número a ser inserido. 
                arvore.inserir(x); //Inserir o número na árvore.
            }  else if (letra.equals("P")) {
                int y = sc.nextInt(); //Ler o número a ser pesquisado. 
                boolean resultado = arvore.pesquisar(y); //Pesquisar o número na árvore

                //Imprimir S caso o número esteja na árvore e N caso contrário.
                if (resultado) {
                    System.out.println("S");
                } else {
                    System.out.println("N");
                }
            } else if (letra.equals("PRE")) { //Se a letra for PRE, imprimir os elementos da esquerda pra direita, começando da raiz. 
                arvore.preOrdem(); //Imprimir os elementos da árvore por caminhamento pré-ordem.
                System.out.println(); //Pular linha após imprimir a árvore.
            } else if (letra.equals("POS")) { //Se a letra for POS, imprimir os elementos da esquerda pra direita, começando pelos elementos mais a esquerda e terminando na raiz.
                arvore.posOrdem(); //Imprimir os elementos da árvore por caminhamento pós-ordem.
                System.out.println(); //Pular linha após imprimir a árvore.
            } else if (letra.equals("EM")) { //Se a letra for EM, imprimir os elementos da esquerda pra direita, começando pelos elementos mais a esquerda, depois a raiz e terminando pelos elementos mais a direita.
                arvore.emOrdem(); //Imprimir os elementos da árvore por caminhamento em-ordem.
                System.out.println(); //Pular linha após imprimir a árvore.
            }
        }

        sc.close(); 
    }
}