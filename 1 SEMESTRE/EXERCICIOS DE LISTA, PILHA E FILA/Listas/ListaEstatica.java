//Mesmo exercicio de lista estática, porém em java. 
import java.util.Scanner; 

//Lista Estática
public class ListaEstatica {
    //Inicializar atributos da lista. 
    int array[]; //Vetor com elementos. 
    int n; //Contador
    int tam; //Tamanho da Lista

    //Construtor da classe. 
    public ListaEstatica (int tam) {
        //Inicializar tamanho da lista, o vetor e o contador.
        this.tam = tam;
        this.array = new int[tam];
        this.n = 0;
    }
    
    //Função para inserir no início da lista. (InserirInicio)
    public void inserirInicio (int elemento) {
        //Tentar inserir. 
        try {
            //Verificar se ta cheia
            if (n < tam) {
                //Deslocar os elementos para a direita.
                for (int i = n; i > 0; i--) {
                    array[i] = array[i - 1];
                }
                //Inserir o elemento no início.
                array[0] = elemento;
                n++;
            } else {
                System.out.println("Lista cheia!");
            }
        } catch (Exception e) {
            System.out.println("Erro ao inserir elemento!");
        }
    }

    //Função para inserir na posição i da lista. (InserirPosicao)
    public void inserirPosicao (int elemento, int pos) {
        //Tentar
        try {
            //Verificar se ta cheia
            if (n < tam) {
                //Verificar pos
                if (pos >= 0 && pos <= n) {
                    //Deslocar os elementos para a direita a partir da posição.
                    for (int i = n; i > pos; i--) {
                        array[i] = array[i - 1];
                    }
                    //Inserir o elemento na posição.
                    array[pos] = elemento;
                    n++;
                } else {
                    System.out.println("Posição inválida ou Lista cheia!");
                }
            }
        } catch (Exception e) {
            System.out.println("Erro ao inserir elemento!");
        }
    }

    //Função para inserir no final da lista. (InserirFim)
    public void inserirFim (int elemento) {
        try {
            //Verificar se ta cheia
            if (n < tam) {
                //Inserir o elemento no final.
                array[n] = elemento;
                n++;
            } else {
                System.out.println("Lista cheia!");
            }
        } catch (Exception e) {
            System.out.println("Erro ao inserir elemento!");
        }
    }

    //Função para mostrar os elementos da lista. (Mostrar)
    public void mostrar() {
        //Elementos da lista.
        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    //Função para remover o elemento do início da lista. (RemoverInicio)
    public void removerInicio() {
        //Ver se ta vazia
        if (n > 0) {
            //Deslocar os elementos para a esquerda.
            for (int i = 0; i < n - 1; i++) {
                array[i] = array[i + 1];
            }
            n--;
        } else {
            System.out.println("Lista vazia!");
        }
    }

    //Função para remover o elemento da posição i da lista. (RemoverPosicao)
    public void removerPosicao (int pos) {
        //Ver se ta vazia
        if (n > 0) {
            //Verificar pos
            if (pos >= 0 && pos < n) {
                //Deslocar os elementos para a esquerda a partir da posição.
                for (int i = pos; i < n - 1; i++) {
                    array[i] = array[i + 1];
                }
                n--;
            } else {
                System.out.println("Posição inválida ou Lista vazia!");
            }
        }
    }

    //Função para remover o elemento do final da lista. (RemoverFim)
    public void removerFim() {
        //Ver se ta vazia
        if (n > 0) {
            n--;
        } else {
            System.out.println("Lista vazia!");
        }
    }



    //Principal
    public static void main (String args[]) {
        //Criar objeto scanner 
        Scanner sc = new Scanner(System.in);

        //Informar tamanho da lista
        System.out.print("Tamanho da Lista: ");
        int tam = sc.nextInt();

        //Criar uma lista estática para tamanho n.
        ListaEstatica lista = new ListaEstatica(tam);


        //Inserir elementos na lista.
        lista.inserirInicio(10);
        lista.inserirPosicao(20, 1);
        lista.inserirFim(30);
        lista.inserirFim(40);
        lista.inserirFim(50);
        lista.inserirPosicao(25, 2);

        //Mostrar a lista.
        System.out.println("Lista após inserções: \n");
        lista.mostrar();

        //Remover elementos da lista.
        lista.removerInicio();
        lista.removerPosicao(1);
        lista.removerFim();

        //Mostrar a lista após remoções.
         System.out.println("\nLista após remoções: \n");
        lista.mostrar();

        //Fechar o scanner
        sc.close(); 
    }
}