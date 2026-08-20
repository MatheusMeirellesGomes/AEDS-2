/*Código de Fila Estática em Java. Diferente de lista, a fila conta com os métodos de inserção e remoção em extremos opostos.
Onde o primeiro elemento inserido é o primeiro a ser removido. FIFO, sendo muito parecido com a lógica de pilha.*/

import java.util.Scanner; 

//Classe para representar a fila. 
class FilaEstatica {
    int array[]; //Vetor para guardar os elementos. 
    int inicio; 
    int fim; 

    //Construtor. 
    public FilaEstatica(int tamanho) {
        //Inicializar atributos. 
        array = new int[tamanho]; //Criar vetor com tamanho definido. 
        inicio = 0; //Início da fila. 
        fim = 0; //Fim da fila. 
    }

    //Método para inserir na fila. 
    public void inserir(int x) throws Exception {
        //Verificar se a fila está cheia
        if (fim == array.length) {
            throw new Exception("Fila cheia!"); 
        }

        //Inserir elemento no fim da fila. 
        array[fim] = x; //Colocar o elemento no fim da fila. 
        fim++; //Incrementar o índice do fim da fila. 
    }

    //Método para remover da fila. 
    public int remover() throws Exception {
        //Verificar se a fila está vazia. 
        if (inicio == fim) { //Se o início e o fim são iguais, a fila está vazia.
            throw new Exception("Fila vazia!");  
        }

        //Criar variável para guardar o elemento a ser removido.
        int elementoRemovido = array[inicio]; //O elemento removido é o elemento no início da fila.
        inicio++; //Incrementar o índice do início da fila.
        
        //Retornar o elemento removido.
        return elementoRemovido; 
    }

    //Método para mostrar os elementos da fila.
    public void mostrar() throws Exception {
        //Verificar se a fila está vazia. 
        if (inicio == fim) {
            throw new Exception("Fila vazia!"); 
        }
        
        //Mostrar os elementos da fila. 
        for (int i = inicio; i < fim; i++) {
            System.out.print(array[i] + " "); //Imprimir o elemento da fila.
        }
        System.out.println(); 
    }

    //Main
    public static void main(String args[]) {
        //Criar objeto da classe FilaEstatica. 
        FilaEstatica fila = new FilaEstatica(7); //Fila com tamanho 7. 

        //Criar scanner para ler a entrada do usuário.
        Scanner sc = new Scanner(System.in);

        //Inserir elementos na fila.
        System.out.println("Digite 7 números para inserir na fila:");
        for (int i = 0; i < 7; i++) {
            int num = sc.nextInt(); //Ler número do usuário. 
            try {
                fila.inserir(num); 
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }

        //Espaçamento.
        System.out.println();

        //Mostrar os elementos da fila.
        System.out.println("Elementos da fila:");
        try {       
            fila.mostrar();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        //Chamar o método de remoção da fila para remover 2 elementos.
        try {
            fila.remover(); //Remover o primeiro elemento da fila.
            fila.remover(); //Remover o segundo elemento da fila.
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        //Espaçamento.
        System.out.println();

        //Mostrar os elementos da fila após as remoções.
        System.out.println("Elementos da fila após as remoções:");
        try {
            fila.mostrar();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}