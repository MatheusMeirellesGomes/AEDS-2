/*Mesmo exercício do Competição.java, porém agora feito em uma lista encadeada, vou utilizar o insertion sort, que nesse caso de lista
vai ser mais eficiente, porque não eu vou pegar um nó da lista não ordenada e vou ordenando ele de acordo com o peso em uma lista ordenada. */

import java.util.Scanner; 

//Classe para lista encadeada, que vai ter um nó para cada atleta.
class Lista {
    //Atributos da lista
    CelulaLista inicio; 
    CelulaLista fim; 

    //Construtor da lista
    public Lista() {
        this.inicio = null; 
        this.fim = null; 
    }
}

class CelulaLista {
    //Elementos da célula da lista. 
    Atleta atleta; 
    CelulaLista prox; 

    //Construtor da célula da lista.
    public CelulaLista(Atleta atleta) {
        this.atleta = atleta; 
        this.prox = null; 
    }
}

class Atleta {
    //Atributos da classe atleta. 
    String nome; 
    int peso; 

    //Construtor
    public Atleta(String nome, int peso) {
        this.nome = nome; 
        this.peso = peso; 
    }

    //Getteres
    String getNome() {
        return this.nome; 
    }

    int getPeso() {
        return this.peso; 
    }

    //Método insertion sort para ordenar os atletas. 
    public static void insertionSort (Lista lista) {
        //Criar uma nova lista para armazenar os atletas ordenados. 
        Lista listaOrdenada = new Lista();

        //Variável para percorrer a lista original, ou seja, com os elementos que não estão ordenados.
        CelulaLista listaOriginal = lista.inicio; 

        //Loop para percorrer a lista original. 
        while (listaOriginal != null) {
            //Criar uma nova célula para o atleta atual. 
            CelulaLista novo = new CelulaLista(listaOriginal.atleta); //Essa célula vai ter o atleta atual da lista original, que vai ser ordenado.

            //Variável para percorrer a lista ordenada. 
            CelulaLista atletaAtual = listaOrdenada.inicio; 
            CelulaLista anterior = null; 

            //Enquanto o atleta atual não apontar para null. 
            while (atletaAtual != null) {
                //Se o peso atual for menor que o peso do novo atleta, vai inserir antes do atleta atual.
                if (atletaAtual.atleta.getPeso() < novo.atleta.getPeso()) {
                    //Atualizar o anterior para o atleta atual e o atleta atual para o próximo da lista ordenada. 
                    anterior = atletaAtual; //O anterior vai ser o atleta atual. 
                    atletaAtual = atletaAtual.prox; //O atleta atual vai ser o prox do antigo atleta atual.
                } else if (atletaAtual.atleta.getPeso() == novo.atleta.getPeso()) {
                    if (atletaAtual.atleta.getNome().compareTo(novo.atleta.getNome()) < 0) {
                        //Atualizar o anterior para o atleta atual e o atleta atual para o próximo da lista ordenada. 
                        anterior = atletaAtual; //O anterior vai ser o atleta atual. 
                        atletaAtual = atletaAtual.prox; //O atleta atual vai ser o prox do antigo atleta atual.
                    } else {
                        break; 
                    }
                } else {
                    break; 
                }
            }   

            /*Caso não entra no while, e o peso do novo atleta for maior que o peso do atleta atual, necessário inserir o novo atleta
            antes do atleta atual.*/
        
            //Se o anterior apontar para null
            if (anterior == null) {
                //O novo atleta apontando pro próximo, vai ser o início da lista ordenada. 
                novo.prox = listaOrdenada.inicio; 
                listaOrdenada.inicio = novo; //O início da lista ordenada vai ser o novo atleta.
            } else {
                //O novo atleta vai apontar para o atleta atual. 
                novo.prox = atletaAtual; 
                anterior.prox = novo; //E o anterior passa a apontar para o novo atleta. 
            }

            //Atualizar o fim da lista ordenada.
            if (novo.prox == null) {
                listaOrdenada.fim = novo;
            }

            //Atualizar a lista original para o próximo atleta.
            listaOriginal = listaOriginal.prox;
        }
        
        //Atualizar a lista original para a lista ordenada. 
        lista.inicio = listaOrdenada.inicio;
        lista.fim = listaOrdenada.fim;
    }

    //Método para imprimir a lista de atletas.
    public static void imprimirLista(Lista lista) {
        for (CelulaLista i = lista.inicio; i != null; i = i.prox) {
            System.out.println(i.atleta.getNome() + " " + i.atleta.getPeso());
        }
    }
}

public class ListaCompe {
    public static void main(String args[]) {
        //Criando a lista de atletas
        Lista listaAtletas = new Lista();

        //Criando o scanner para ler a entrada 
        Scanner sc = new Scanner(System.in); 

        //Inicializar variáveis. 
        String nome = ""; 
        int peso = 0; 

        //Ler os dados enquanto não for o fim do arquivo. 
        while (sc.hasNext()) {
            //Ler o nome e o peso. 
            nome = sc.next(); 
            peso = sc.nextInt(); 

            //Criar um novo atleta e adicionar na lista. 
            Atleta atleta = new Atleta(nome, peso); 
            
            //Criar uma nova célula para o atleta e adicionar na lista. 
            CelulaLista novaCelula = new CelulaLista(atleta);
            
            //Se a lista estiver vazia
            if (listaAtletas.inicio == null) {
                //Tanto o início quanto o fim da lista vão apontar para a nova célula.
                listaAtletas.inicio = novaCelula; 
                listaAtletas.fim = novaCelula; 
            } else { //Caso ela ja tenha atletas inseridos
                //O próximo do fim da lista aponta para a nova célula
                listaAtletas.fim.prox = novaCelula; 
                listaAtletas.fim = novaCelula; //Fim passa a ser a nova célula.
            }
        }

        //Chamar o método para ordenar os atletas. 
        Atleta.insertionSort(listaAtletas);

        //Imprimir a lista ordenada. 
        Atleta.imprimirLista(listaAtletas);

        sc.close();
    }
}